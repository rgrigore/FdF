/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_zoom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 15:23:04 by rgrigore          #+#    #+#             */
/*   Updated: 2018/02/08 15:23:06 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	mask_zoom(t_data *data)
{
	int		i;
	int		j;
	int		k;

	k = -1;
	i = -1;
	while (++i < W_HEIGHT)
	{
		j = -1;
		while (++j < W_WIDTH)
			if (++k && !((j > data->zoom_x - Z_W) && (j < data->zoom_x + Z_W) &&
				(i > data->zoom_y - Z_H) && (i < data->zoom_y + Z_H)))
			{
				if ((((j > data->zoom_x - Z_W - 3) && (j < data->zoom_x -
					Z_W + 3 + 8)) && ((i > data->zoom_y - Z_H - 3) &&
					(i < data->zoom_y + Z_H + 3))) || (((j > data->zoom_x +
					Z_W - 3 - 8) && (j < data->zoom_x + Z_W + 3)) &&
					((i > data->zoom_y - Z_H - 3) && (i < data->zoom_y +
					Z_H + 3))))
					data->zoom.pixel[k] = 0X00888888;
				else
					data->zoom.pixel[k] = 0XFF000000;
			}
	}
}

static void	zoom_background(t_data *data, void *background)
{
	t_img_data	bg;
	int			i;
	int			j;

	bg.bpp = 32;
	bg.endi = 0;
	bg.value = background;
	bg.l_size = W_WIDTH * bg.bpp;
	bg.pixel = (int*)mlx_get_data_addr(bg.value, &bg.bpp, &bg.l_size, &bg.endi);
	i = -1;
	while (++i < W_HEIGHT)
	{
		j = -1;
		while (++j < W_WIDTH)
			if (((j > data->zoom_x - Z_W) && (j <= data->zoom_x + Z_W) &&
				(i >= data->zoom_y - Z_H) && (i < data->zoom_y + Z_H)))
				*(data->zoom.pixel + j + i * W_WIDTH) =
						*(bg.pixel + j + i * W_WIDTH);
	}
}

static void	build_zoom(t_data *data, t_point *point1, t_point *point2)
{
	double	p1_dist_x;
	double	p1_dist_y;
	double	p2_dist_x;
	double	p2_dist_y;

	p1_dist_x = data->zoom_x - (*point1).projected.x;
	p1_dist_y = data->zoom_y - (*point1).projected.y;
	p2_dist_x = data->zoom_x - (*point2).projected.x;
	p2_dist_y = data->zoom_y - (*point2).projected.y;
	(*point1).projected.x = -(p1_dist_x * data->zoom_level - data->zoom_x);
	(*point1).projected.y = -(p1_dist_y * data->zoom_level - data->zoom_y);
	(*point2).projected.x = -(p2_dist_x * data->zoom_level - data->zoom_x);
	(*point2).projected.y = -(p2_dist_y * data->zoom_level - data->zoom_y);
	draw_img_line(&data->zoom.pixel, *point1, *point2, &data->z_buffer);
}

void		render_zoom(t_data *data)
{
	int		i;
	t_point	p1;
	t_point	p2;

	if (data->is_zoom)
	{
		clear_img(&data->zoom, data->z_buffer, 1);
		zoom_background(data, data->bg_array[data->bg]);
		i = -2;
		while ((i += 2) < data->mesh.line_count)
		{
			p1 = data->mesh.points[data->mesh.lines[i]];
			p2 = data->mesh.points[data->mesh.lines[i + 1]];
			if (p1.world.z > -data->camera.location.z + 1 &&
				p2.world.z > -data->camera.location.z + 1)
				build_zoom(data, &p1, &p2);
		}
		if (data->render_points)
			render_mesh_points(data, &data->zoom.pixel, data->zoom_level);
		mask_zoom(data);
		MLX_PITW(data->mlx.mlx, data->mlx.win, data->zoom.value, 0, 0);
	}
}
