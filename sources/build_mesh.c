/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_mesh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 12:57:17 by rgrigore          #+#    #+#             */
/*   Updated: 2018/02/02 12:57:18 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define L (file->nr_ln - 1)
#define C (file->nr_col - 1)

/*
** Initialize all the points of the mesh in local space
*/

static void		build_points(t_mesh *mesh, t_line *line_list, int nr_col)
{
	t_line	*current_line;
	t_line	*next_line;
	int		collumn;
	int		row;
	int		index;

	current_line = line_list;
	row = 0;
	index = 0;
	while (current_line)
	{
		collumn = -1;
		while (++collumn < nr_col)
		{
			mesh->points[index].local.x = collumn * UNIT;
			mesh->points[index].local.y = current_line->line[collumn] * UNIT;
			mesh->points[index].local.z = row * UNIT;
			index++;
		}
		next_line = current_line->next;
		free(current_line->line);
		free(current_line);
		current_line = next_line;
		row++;
	}
}

/*
** Match each point from the points array with its neighbors
*/

static void		build_lines(t_mesh *mesh, int nr_col, int nr_ln)
{
	int		index;
	int		row;
	int		collumn;

	index = 0;
	row = -1;
	while (++row < nr_ln)
	{
		collumn = -1;
		while (++collumn < nr_col)
		{
			if ((row == 0 && collumn != 0) || (row != 0 && collumn != 0))
			{
				mesh->lines[index++] = row * nr_col + collumn;
				mesh->lines[index++] = row * nr_col + collumn - 1;
			}
			if ((row != 0 && collumn == 0) || (row != 0 && collumn != 0))
			{
				mesh->lines[index++] = row * nr_col + collumn;
				mesh->lines[index++] = (row - 1) * nr_col + collumn;
			}
		}
	}
}

/*
** Calculate the width, depth, height_min and height_max
*/

static void		get_sizes(t_mesh *mesh, t_file *file)
{
	int		i;

	mesh->width = file->nr_col * UNIT;
	mesh->depth = file->nr_ln * UNIT;
	i = 1;
	mesh->height_max = mesh->points[0].local.y;
	mesh->height_min = mesh->points[0].local.y;
	while (i < mesh->pct_count)
	{
		if (mesh->points[i].local.y > mesh->height_max)
			mesh->height_max = mesh->points[i].local.y;
		if (mesh->points[i].local.y < mesh->height_min)
			mesh->height_min = mesh->points[i].local.y;
		i++;
	}
}

/*
** Main function for building the wireframe later to be rendered
*/

int				build_mesh(t_data *data, t_file *file)
{
	data->mesh.pct_count = file->nr_col * file->nr_ln;
	if (!(data->mesh.points = (t_point*)malloc(sizeof(t_point) *
								data->mesh.pct_count)))
		return (0);
	data->mesh.line_count = 2 * (2 * L * C + L + C);
	if (!(data->mesh.lines = (int*)malloc(sizeof(int) * data->mesh.line_count)))
		return (0);
	build_points(&data->mesh, file->line_list, file->nr_col);
	build_lines(&data->mesh, file->nr_col, file->nr_ln);
	get_sizes(&data->mesh, file);
	set_mesh_colors(&data->mesh, data->grad);
	return (1);
}
