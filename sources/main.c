/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:10:06 by rgrigore          #+#    #+#             */
/*   Updated: 2018/01/11 13:10:08 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Start point for the application and mlx_loop function
*/

int			main(int ac, char **av)
{
	t_data	data;

	ft_putendl("usage: ./fdf [source_file] [color1] [color2]");
	ft_putendl("or choose a map and colors from the menu");
	data.mlx.mlx = mlx_init();
	data.mlx.win = mlx_new_window(data.mlx.mlx, W_WIDTH, W_HEIGHT, "FdF");
	init_data(&data);
	get_input(&data, ac, av);
	load_map(&data);
	mlx_loop_hook(data.mlx.mlx, render, &data);
	mlx_hook(data.mlx.win, 2, 1, event_keyboard, &data);
	mlx_hook(data.mlx.win, 6, 0, event_mouse_move, &data);
	mlx_hook(data.mlx.win, 4, 0, event_mouse_down, &data);
	mlx_hook(data.mlx.win, 5, 0, event_mouse_up, &data);
	mlx_loop(data.mlx.mlx);
	return (0);
}
