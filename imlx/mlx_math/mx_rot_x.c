/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_rot_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:05:44 by rgrigore          #+#    #+#             */
/*   Updated: 2018/01/13 17:05:46 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx_math.h>

t_mx4	mx_rot_x(float alpha)
{
	t_mx4	result;
	int		i;

	i = -1;
	while (++i < 4)
	{
		result.x[i] = (i == 0) ? 1 : 0;
		result.t[i] = (i == 3) ? 1 : 0;
		if (i == 1)
		{
			result.y[i] = cos(alpha * 0.01745329252);
			result.z[i] = -sin(alpha * 0.01745329252);
		}
		else if (i == 2)
		{
			result.y[i] = sin(alpha * 0.01745329252);
			result.z[i] = cos(alpha * 0.01745329252);
		}
		else
		{
			result.y[i] = 0;
			result.z[i] = 0;
		}
	}
	return (result);
}
