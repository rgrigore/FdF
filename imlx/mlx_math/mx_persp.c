/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_persp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 11:27:10 by rgrigore          #+#    #+#             */
/*   Updated: 2018/01/17 11:27:11 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx_math.h>

t_mx4	mx_persp(float fov_x, float fov_y, float zn, float zf)
{
	t_mx4	result;

	fov_x = 0.01745329252 * fov_x;
	fov_y = 0.01745329252 * fov_y;
	result.x[0] = 1 / tan(fov_x / 2);
	result.x[1] = 0;
	result.x[2] = 0;
	result.x[3] = 0;
	result.y[0] = 0;
	result.y[1] = 1 / tan(fov_y / 2);
	result.y[2] = 0;
	result.y[3] = 0;
	result.z[0] = 0;
	result.z[1] = 0;
	result.z[2] = -((zf + zn) / (zf - zn));
	result.z[3] = -1;
	result.t[0] = 0;
	result.t[1] = 0;
	result.t[2] = -(2 * zn * zf / (zf - zn));
	result.t[3] = 0;
	return (result);
}
