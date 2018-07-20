/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_inv_2x2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 11:04:08 by rgrigore          #+#    #+#             */
/*   Updated: 2018/01/17 11:04:09 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx_math.h>

t_mx2	mx_inv_2x2(t_mx2 mx)
{
	float	coef;
	t_mx2	result;

	coef = 1 / (mx.x[0] * mx.y[1] - mx.y[0] * mx.x[1]);
	result.x[0] = mx.y[1] * coef;
	result.x[1] = -mx.x[1] * coef;
	result.y[0] = -mx.y[0] * coef;
	result.y[1] = mx.x[0] * coef;
	return (result);
}
