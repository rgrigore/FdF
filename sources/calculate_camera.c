/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_camera.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 18:31:22 by rgrigore          #+#    #+#             */
/*   Updated: 2018/02/08 18:31:24 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Calculate the location of the camera as to fit the entire mesh on the screen
*/

void	calculate_camera(t_mesh *mesh, t_camera *cam)
{
	mx_new(&cam->transform);
	if (mesh->width >= mesh->depth / 2 &&
		mesh->width >= (mesh->height_max - mesh->height_min) / 2)
	{
		mx_translate(&cam->transform, 0, 0, mesh->width);
		cam->ortho_scale = 6 - 6 * mesh->width / (500 - 10) >= 1 ?
			6 - 6 * mesh->width / (500 - 10) : 1;
	}
	else if (mesh->depth / 2 >= (mesh->height_max - mesh->height_min) / 2)
	{
		mx_translate(&cam->transform, 0, 0, mesh->depth / 2 + 10 * UNIT);
		cam->ortho_scale = 6 - 6 * mesh->depth / (500 - 10) >= 1 ?
			6 - 6 * mesh->depth / (500 - 10) : 1;
	}
	else
	{
		mx_translate(&cam->transform, 0, 0,
			(mesh->height_max - mesh->height_min) / 2 + 10 * UNIT);
		cam->ortho_scale =
			6 - 6 * (mesh->height_max - mesh->height_min) / (500 - 10) >= 1 ?
				6 - 6 * (mesh->height_max - mesh->height_min) / (500 - 10) : 1;
	}
	cam->location = mx_mult_4x1(cam->transform, cam->location);
}
