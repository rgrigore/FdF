/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 13:48:09 by rgrigore          #+#    #+#             */
/*   Updated: 2018/01/30 13:48:10 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Function for identifying given parameters as colors
*/

static int	get_input_color(char *str)
{
	int		i;
	int		nr;

	nr = 0;
	if (ft_strlen(str) != 10)
		return (-1);
	if (!(str[0] == '0' && (str[1] == 'x' || str[1] == 'X')))
		return (-1);
	i = 1;
	while (++i < 10)
	{
		if (ft_strchr(HEX, str[i]))
		{
			if (ft_isdigit(str[i]))
				nr += (str[i] - '0') << (4 * (9 - i));
			else
			{
				str[i] = ft_toupper(str[i]);
				nr += (str[i] - 55) << (4 * (9 - i));
			}
		}
		else
			return (-1);
	}
	return (nr);
}

/*
** Function for allocating parameters identified as map files
*/

static void	manage_map(char *map, t_data *data)
{
	if (map)
	{
		data->map[data->map_count++] = ft_strdup(map);
		data->curr_map = ft_strdup(map);
		data->selected_map = data->map[data->map_count - 1];
		data->map_index = data->map_count - 1;
	}
	else
	{
		if (data->map_count)
		{
			data->selected_map = data->map[0];
			data->curr_map = ft_strdup(data->selected_map);
		}
	}
}

/*
** Function for allocating parameters identified as colors
*/

static void	manage_colors(int colors[2], t_data *data)
{
	if (colors[0] != -1)
	{
		data->grad.start = colors[0];
		data->menu.colors[data->menu.color_count++] = colors[0];
		data->menu.left_color = data->menu.color_count - 1;
		if (colors[1] != -1)
		{
			data->grad.end = colors[1];
			data->menu.colors[data->menu.color_count++] = colors[1];
			data->menu.right_color = data->menu.color_count - 1;
		}
		else
		{
			data->grad.end = colors[0];
			data->menu.right_color = data->menu.color_count - 1;
		}
	}
	clear_button(&data->menu.img_grad, 0);
	update_img_grad(data, 0);
	update_img_grad(data, 1);
}

/*
** Function for printing errors
*/

static void	print_error(char *str, int code)
{
	if (code == 0)
	{
		ft_putstr(str);
		ft_putendl(" : Invalid parameter!");
	}
	else if (code == 1)
	{
		ft_putstr(str);
		ft_putendl(" : Maximum of 2 color parameters!");
	}
	else if (code == 2)
	{
		ft_putstr(str);
		ft_putendl(" : Only 1 map parameter!");
	}
}

/*
** Main function for interpretting the parameters given to the program
*/

void		get_input(t_data *data, int ac, char **av)
{
	int		i;
	int		colors[2];
	char	*map;
	int		cur_col;
	int		color;

	colors[0] = -1;
	colors[1] = -1;
	cur_col = 0;
	map = NULL;
	i = 0;
	while (++i < ac)
	{
		if (((color = get_input_color(av[i])) != -1))
			((cur_col < 2)) ? colors[cur_col++] = color : print_error(av[i], 1);
		else if (ft_strstr(av[i] + ft_strlen(av[i]) - 4, ".fdf"))
			(!map) ? map = ft_strdup(av[i]) : print_error(av[i], 2);
		else
			print_error(av[i], 0);
	}
	manage_map(map, data);
	manage_colors(colors, data);
}
