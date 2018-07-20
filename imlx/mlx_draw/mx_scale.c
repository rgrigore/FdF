/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_scale.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 11:37:33 by rgrigore          #+#    #+#             */
/*   Updated: 2018/01/26 11:37:36 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx_draw.h>

void		mx_scale(t_mx4 *transform, double scale)
{
	t_mx4	scale_mx;
	int		i;

	i = -1;
	while (++i < 4)
	{
		scale_mx.x[i] = (i == 0) ? scale : 0;
		scale_mx.y[i] = (i == 1) ? scale : 0;
		scale_mx.z[i] = (i == 2) ? scale : 0;
		scale_mx.t[i] = (i == 3) ? 1 : 0;
	}
	*transform = mx_mult_4x4(*transform, scale_mx);
}
