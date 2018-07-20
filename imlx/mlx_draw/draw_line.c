/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:33:15 by rgrigore          #+#    #+#             */
/*   Updated: 2018/01/11 15:33:18 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx_draw.h>
#include <math.h>
#include <stdlib.h>

static void		draw_line_x(t_mlx mlx, t_v2 p1, t_v2 p2, int color)
{
	int		x;
	int		y;
	double	slope;
	double	error;

	error = 0;
	slope = fabs((float)(p2.y - p1.y) / (float)(p2.x - p1.x));
	x = p1.x;
	y = p1.y;
	while ((p1.x < p2.x) ? x <= p2.x : x >= p2.x)
	{
		mlx_pixel_put(mlx.mlx, mlx.win, x, y, color);
		error += slope;
		while (error >= 0.5)
		{
			y += (p2.y > p1.y) ? 1 : -1;
			error -= 1;
		}
		(p1.x < p2.x) ? x++ : x--;
	}
}

static void		draw_line_y(t_mlx mlx, t_v2 p1, t_v2 p2, int color)
{
	int		x;
	int		y;
	double	slope;
	double	error;

	error = 0;
	slope = fabs((float)(p2.x - p1.x) / (float)(p2.y - p1.y));
	x = p1.x;
	y = p1.y;
	while ((p1.y < p2.y) ? y <= p2.y : y >= p2.y)
	{
		mlx_pixel_put(mlx.mlx, mlx.win, x, y, color);
		error += slope;
		while (error >= 0.5)
		{
			x += (p2.x > p1.x) ? 1 : -1;
			error -= 1;
		}
		(p1.y < p2.y) ? y++ : y--;
	}
}

void			draw_line(t_mlx mlx, t_v2 p1, t_v2 p2, int color)
{
	if (fabs(p2.y - p1.y) < fabs(p2.x - p1.x))
		draw_line_x(mlx, p1, p2, color);
	else
		draw_line_y(mlx, p1, p2, color);
}
