/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_mult_4x1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 18:08:50 by rgrigore          #+#    #+#             */
/*   Updated: 2018/01/13 18:08:51 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx_math.h>

t_v3	mx_mult_4x1(t_mx4 m, t_v3 v)
{
	t_v3	v3_result;
	double	t;

	t = m.x[3] * v.x + m.y[3] * v.y + m.z[3] * v.z + m.t[3] * 1;
	v3_result.x = (m.x[0] * v.x + m.y[0] * v.y + m.z[0] * v.z + m.t[0]) / t;
	v3_result.y = (m.x[1] * v.x + m.y[1] * v.y + m.z[1] * v.z + m.t[1]) / t;
	v3_result.z = (m.x[2] * v.x + m.y[2] * v.y + m.z[2] * v.z + m.t[2]) / t;
	return (v3_result);
}
