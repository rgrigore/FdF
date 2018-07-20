/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_img_grad.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 18:26:04 by rgrigore          #+#    #+#             */
/*   Updated: 2018/02/09 18:26:06 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	update_left(t_data *data)
{
	int		*pixel;
	int		line;
	int		x;
	int		y;

	pixel = data->menu.img_grad.pixel;
	line = (GRAD_W - GRAD_D) / 2;
	x = -1;
	while (++x < line)
	{
		y = -1;
		while (++y < GRAD_H)
			pixel[x + y * GRAD_W] = data->menu.colors[data->menu.left_color];
	}
}

static void	update_right(t_data *data)
{
	int		*pixel;
	int		line;
	int		x;
	int		y;

	pixel = data->menu.img_grad.pixel;
	line = GRAD_W;
	x = (GRAD_W + GRAD_D) / 2 - 1;
	while (++x < line)
	{
		y = -1;
		while (++y < GRAD_H)
			pixel[x + y * line] = data->menu.colors[data->menu.right_color];
	}
}

void		update_img_grad(t_data *data, int side)
{
	if (side == 0)
		update_left(data);
	else if (side == 1)
		update_right(data);
}
