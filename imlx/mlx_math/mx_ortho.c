/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_ortho.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 11:23:49 by rgrigore          #+#    #+#             */
/*   Updated: 2018/01/17 11:23:50 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx_math.h>

t_mx4	mx_ortho(float w, float h, float zn, float zf)
{
	t_mx4	result;

	result.x[0] = 1 / w;
	result.x[1] = 0;
	result.x[2] = 0;
	result.x[3] = 0;
	result.y[0] = 0;
	result.y[1] = 1 / h;
	result.y[2] = 0;
	result.y[3] = 0;
	result.z[0] = 0;
	result.z[1] = 0;
	result.z[2] = -(2 / (zf - zn));
	result.z[3] = 0;
	result.t[0] = 0;
	result.t[1] = 0;
	result.t[2] = -((zf + zn) / (zf - zn));
	result.t[3] = 1;
	return (result);
}
