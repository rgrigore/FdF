/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_trans.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 19:09:51 by rgrigore          #+#    #+#             */
/*   Updated: 2018/01/13 19:09:52 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx_math.h>

t_mx4	mx_trans(t_v3 v)
{
	t_mx4	result;
	int		i;

	i = -1;
	while (++i < 4)
	{
		result.x[i] = (i == 0) ? 1 : 0;
		result.y[i] = (i == 1) ? 1 : 0;
		result.z[i] = (i == 2) ? 1 : 0;
	}
	result.t[0] = v.x;
	result.t[1] = v.y;
	result.t[2] = v.z;
	result.t[3] = 1;
	return (result);
}
