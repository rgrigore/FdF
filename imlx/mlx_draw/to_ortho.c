/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_ortho.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 17:22:59 by rgrigore          #+#    #+#             */
/*   Updated: 2018/02/02 17:23:01 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx_draw.h>

void	to_ortho(t_v3 v3, t_v2 *v2, double zoom)
{
	float	zf;
	float	zn;
	float	ratio;
	t_mx4	m;

	zf = 1000000;
	zn = 0;
	ratio = W_WIDTH / W_HEIGHT;
	mx_new(&m);
	m.x[0] = 1.0 / ratio;
	m.y[1] = 1.0 / 1;
	m.z[2] = -2.0 / (zf - zn);
	m.t[2] = -(zf + zn) / (zf - zn);
	v3 = mx_mult_4x1(m, v3);
	v2->x = v3.x * -1 * zoom + W_WIDTH / 2;
	v2->y = v3.y * -1 * zoom + W_HEIGHT / 2;
}
