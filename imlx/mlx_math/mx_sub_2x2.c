/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_sub_2x2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 10:56:19 by rgrigore          #+#    #+#             */
/*   Updated: 2018/01/17 10:56:20 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx_math.h>

t_mx2	mx_sub_2x2(t_mx2 m1, t_mx2 m2)
{
	t_mx2	result;

	result.x[0] = m1.x[0] - m2.x[0];
	result.x[1] = m1.x[1] - m2.x[1];
	result.y[0] = m1.y[0] - m2.y[0];
	result.y[1] = m1.y[1] - m2.y[1];
	return (result);
}
