/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_rot_y.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:05:50 by rgrigore          #+#    #+#             */
/*   Updated: 2018/01/13 17:05:51 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx_math.h>

t_mx4	mx_rot_y(float alpha)
{
	t_mx4	result;
	int		i;

	i = -1;
	while (++i < 4)
	{
		result.y[i] = (i == 1) ? 1 : 0;
		result.t[i] = (i == 3) ? 1 : 0;
		if (i == 0)
		{
			result.x[i] = cos(alpha * 0.01745329252);
			result.z[i] = sin(alpha * 0.01745329252);
		}
		else if (i == 2)
		{
			result.x[i] = -sin(alpha * 0.01745329252);
			result.z[i] = cos(alpha * 0.01745329252);
		}
		else
		{
			result.x[i] = 0;
			result.z[i] = 0;
		}
	}
	return (result);
}
