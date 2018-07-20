/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:19:59 by rgrigore          #+#    #+#             */
/*   Updated: 2018/01/29 17:20:00 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	render_ui(t_menu *menu, t_mlx *mlx, char *map)
{
	if (menu->is_visible)
	{
		MLX_PITW(mlx->mlx, mlx->win, menu->gui.value, 0, 0);
		MLX_PITW(mlx->mlx, mlx->win, menu->img_grad.value,
			menu->button[0].corner[0].x + 2, menu->button[0].corner[0].y + 1);
		mlx_string_put(mlx->mlx, mlx->win,
			W_WIDTH / 2 - ft_strlen(map) / 2 * 11 - 14, 13, 0x00ffffff, map);
	}
}

static void	render_mesh(t_data *data)
{
	int		i;
	t_point	point1;
	t_point	point2;
	double	z;

	clear_img(&data->image, data->z_buffer, 0);
	i = 0;
	while (i < data->mesh.line_count)
	{
		point1 = data->mesh.points[data->mesh.lines[i]];
		point2 = data->mesh.points[data->mesh.lines[i + 1]];
		z = point1.camera.z;
		if (z > point2.camera.z)
			z = point2.camera.z;
		if (point1.world.z > -data->camera.location.z + 2 &&
			point2.world.z > -data->camera.location.z + 2)
			draw_img_line(&data->image.pixel, point1, point2, &data->z_buffer);
		i += 2;
	}
	if (data->render_points)
		render_mesh_points(data, &data->image.pixel, 1);
	MLX_PITW(data->mlx.mlx, data->mlx.win, data->image.value, 0, 0);
}

int			render(t_data *data)
{
	MLX_PITW(data->mlx.mlx, data->mlx.win, data->bg_array[data->bg], 0, 0);
	render_mesh(data);
	render_zoom(data);
	render_ui(&data->menu, &data->mlx, data->selected_map);
	return (0);
}
