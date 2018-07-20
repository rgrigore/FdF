/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 16:56:35 by rgrigore          #+#    #+#             */
/*   Updated: 2018/02/02 16:56:36 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx_draw.h>

void	calculate_projection(t_data *data)
{
	int		i;
	t_v3	tmp_point;

	i = -1;
	while (++i < data->mesh.pct_count)
	{
		tmp_point = mx_mult_4x1(data->mesh.init_translation,
								data->mesh.points[i].local);
		if (data->camera.projection)
			tmp_point = mx_mult_4x1(data->mesh.ortho_rotation, tmp_point);
		else
			tmp_point = mx_mult_4x1(data->mesh.persp_rotation, tmp_point);
		tmp_point = mx_mult_4x1(data->mesh.rotation, tmp_point);
		tmp_point = mx_mult_4x1(data->mesh.translation, tmp_point);
		data->mesh.points[i].world = tmp_point;
		tmp_point = mx_mult_4x1(data->camera.transform, tmp_point);
		data->mesh.points[i].camera = tmp_point;
		if (data->camera.projection)
			to_ortho(tmp_point, &data->mesh.points[i].projected,
										data->camera.ortho_scale);
		else
			to_perspective(tmp_point, &data->mesh.points[i].projected, 1);
	}
}
