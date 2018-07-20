/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mesh_points.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 15:49:35 by rgrigore          #+#    #+#             */
/*   Updated: 2018/02/08 15:49:37 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render_mesh_points(t_data *data, int **pixel, double zoom)
{
	int		i;
	int		x;
	int		y;
	double	p1_dist_x;
	double	p1_dist_y;

	i = -1;
	while (++i < data->mesh.pct_count)
	{
		p1_dist_x = data->zoom_x - (data->mesh.points[i].projected.x);
		p1_dist_y = data->zoom_y - (data->mesh.points[i].projected.y);
		x = -(p1_dist_x * zoom - data->zoom_x);
		y = -(p1_dist_y * zoom - data->zoom_y);
		if (data->mesh.points[i].world.z > -data->camera.location.z + 2)
			if (x > 0 && x < W_WIDTH && y > 0 && y < W_HEIGHT)
				*((*pixel) + x + y * W_WIDTH) = P_COLOR;
	}
}
