/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_mult_4x4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:38:58 by rgrigore          #+#    #+#             */
/*   Updated: 2018/01/13 17:38:59 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx_math.h>

t_mx4	mx_mult_4x4(t_mx4 m1, t_mx4 m2)
{
	t_mx4	result;
	int		i;

	i = -1;
	while (++i < 4)
	{
		result.x[i] = m1.x[i] * m2.x[0] + m1.y[i] * m2.x[1] +
					m1.z[i] * m2.x[2] + m1.t[i] * m2.x[3];
		result.y[i] = m1.x[i] * m2.y[0] + m1.y[i] * m2.y[1] +
					m1.z[i] * m2.y[2] + m1.t[i] * m2.y[3];
		result.z[i] = m1.x[i] * m2.z[0] + m1.y[i] * m2.z[1] +
					m1.z[i] * m2.z[2] + m1.t[i] * m2.z[3];
		result.t[i] = m1.x[i] * m2.t[0] + m1.y[i] * m2.t[1] +
					m1.z[i] * m2.t[2] + m1.t[i] * m2.t[3];
	}
	return (result);
}
