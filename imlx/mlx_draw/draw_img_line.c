/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 17:49:45 by rgrigore          #+#    #+#             */
/*   Updated: 2018/02/02 17:49:47 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx_draw.h>

#define X1 p1.projected.x
#define Y1 p1.projected.y
#define X2 p2.projected.x
#define Y2 p2.projected.y
#define Z ((p1.camera.z < p2.camera.z) ? p1.camera.z : p2.camera.z)
#define Z_BUFF (*((*z_buff) + x + y * W_WIDTH))

static void	draw_line_x(int **s_pixel, t_point p1, t_point p2, double **z_buff)
{
	int		x;
	int		y;
	double	slope;
	double	error;

	error = 0;
	slope = fabs((float)(Y2 - Y1) / (float)(X2 - X1));
	x = X1;
	y = Y1;
	while ((X1 < X2) ? x <= X2 : x >= X2)
	{
		if ((x >= 0 && x < W_WIDTH && y >= 0 && y < W_HEIGHT) && (Z < Z_BUFF))
		{
			*((*s_pixel) + y * W_WIDTH + x) = get_color(p1.color,
				p2.color, fabs(x - X1) / fabs(X2 - X1));
			Z_BUFF = Z;
		}
		error += slope;
		while (error >= 0.5)
		{
			y += (Y2 > Y1) ? 1 : -1;
			error -= 1;
		}
		(X1 < X2) ? x++ : x--;
	}
}

static void	draw_line_y(int **s_pixel, t_point p1, t_point p2, double **z_buff)
{
	int		x;
	int		y;
	double	slope;
	double	error;

	error = 0;
	slope = fabs((float)(X2 - X1) / (float)(Y2 - Y1));
	x = X1;
	y = Y1;
	while ((Y1 < Y2) ? y <= Y2 : y >= Y2)
	{
		if ((x >= 0 && x < W_WIDTH && y >= 0 && y < W_HEIGHT) && (Z < Z_BUFF))
		{
			*((*s_pixel) + y * W_WIDTH + x) = get_color(p1.color,
				p2.color, fabs(y - Y1) / fabs(Y2 - Y1));
			Z_BUFF = Z;
		}
		error += slope;
		while (error >= 0.5)
		{
			x += (X2 > X1) ? 1 : -1;
			error -= 1;
		}
		(Y1 < Y2) ? y++ : y--;
	}
}

void		draw_img_line(int **s_pixel, t_point p1, t_point p2, double **z_buf)
{
	if (fabs(Y2 - Y1) < fabs(X2 - X1))
		draw_line_x(s_pixel, p1, p2, z_buf);
	else
		draw_line_y(s_pixel, p1, p2, z_buf);
}
