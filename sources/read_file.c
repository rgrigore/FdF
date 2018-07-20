/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 16:12:40 by rgrigore          #+#    #+#             */
/*   Updated: 2018/01/31 16:12:42 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	new_line(t_line **line_list, char **line, int count)
{
	int i;

	if (!(*line_list = (t_line*)malloc(sizeof(t_line))))
		return (0);
	if (!((*line_list)->line = (int*)malloc(sizeof(int) * count)))
		return (0);
	i = -1;
	while (line[++i])
	{
		if (ft_ishexa(line[i]))
			(*line_list)->line[i] = ft_hatoi(line[i]);
		else
			(*line_list)->line[i] = ft_atoi(line[i]);
	}
	(*line_list)->next = NULL;
	return (1);
}

static int	add_line(t_line **line_list, char **line, int count)
{
	t_line	*temp;

	temp = *line_list;
	while (temp->next)
		temp = temp->next;
	if (!(new_line(&temp->next, line, count)))
		return (0);
	return (1);
}

static int	manage_line(t_file *file, char **buff)
{
	char **line;

	line = ft_strsplit(*buff, ' ');
	if (!(validate_file(line, file->nr_col)))
		return (5);
	if (file->line_list)
	{
		if (!add_line(&file->line_list, line, file->nr_col))
			return (4);
	}
	else
	{
		if (!new_line(&file->line_list, line, file->nr_col))
			return (4);
	}
	file->nr_ln++;
	free(*buff);
	free(line);
	return (0);
}

static int	read_content(t_file *file)
{
	char	*buff;
	int		count;
	int		code;

	if (!(count = get_next_line(file->fd, &buff)))
		return (2);
	if (count < 0)
		return (3);
	file->nr_col = count_words(ft_strsplit(buff, ' '));
	if ((code = manage_line(file, &buff)))
		return (code);
	while ((count = get_next_line(file->fd, &buff)))
	{
		if (count < 0)
			return (3);
		if ((code = manage_line(file, &buff)))
			return (code);
	}
	return (0);
}

int			read_file(t_file *file, char *map_name)
{
	int	code;

	file->line_list = NULL;
	file->nr_col = 0;
	file->nr_ln = 0;
	if (ft_strchr(map_name, '/'))
		file->path = map_name;
	else
		file->path = ft_strjoin("./maps/", map_name);
	if (!((file->fd = open(file->path, O_RDONLY)) > 0))
		return (1);
	if ((code = read_content(file)))
		return (code);
	return (0);
}
