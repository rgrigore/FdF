/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_inv_4x4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:08:40 by rgrigore          #+#    #+#             */
/*   Updated: 2018/01/17 13:08:42 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx_math.h>

#define S mx_sub_2x2
#define A mx_add_2x2
#define M mx_mult_2x2
#define I mx_inv_2x2
#define SC mx_scal_2x2

static void	one_to_four(t_mx4 mx, t_mx2 (*sq)[5])
{
	(*sq)[0].x[0] = mx.x[0];
	(*sq)[0].x[1] = mx.x[1];
	(*sq)[0].y[0] = mx.y[0];
	(*sq)[0].y[1] = mx.y[1];
	(*sq)[1].x[0] = mx.z[0];
	(*sq)[1].x[1] = mx.z[1];
	(*sq)[1].y[0] = mx.t[0];
	(*sq)[1].y[1] = mx.t[1];
	(*sq)[2].x[0] = mx.x[2];
	(*sq)[2].x[1] = mx.x[3];
	(*sq)[2].y[0] = mx.y[2];
	(*sq)[2].y[1] = mx.y[3];
	(*sq)[3].x[0] = mx.z[2];
	(*sq)[3].x[1] = mx.z[3];
	(*sq)[3].y[0] = mx.t[2];
	(*sq)[3].y[1] = mx.t[3];
}

t_mx4		mx_inv_4x4(t_mx4 mx)
{
	t_mx4	result;
	t_mx2	sq[5];
	int		i;

	one_to_four(mx, &sq);
	sq[3] = I(S(sq[3], M(M(sq[2], I(sq[0])), sq[1])));
	sq[4] = A(I(sq[0]), M(M(M(M(I(sq[0]), sq[1]), sq[3]), sq[2]), I(sq[0])));
	sq[1] = SC(M(M(I(sq[0]), sq[1]), sq[3]), -1);
	sq[2] = SC(M(M(sq[3], sq[2]), I(sq[0])), -1);
	i = -1;
	while (++i < 4)
	{
		result.x[i] = (i < 2) ? sq[4].x[i % 2] : sq[2].x[i % 2];
		result.y[i] = (i < 2) ? sq[4].y[i % 2] : sq[2].y[i % 2];
		result.z[i] = (i < 2) ? sq[1].x[i % 2] : sq[3].x[i % 2];
		result.t[i] = (i < 2) ? sq[1].y[i % 2] : sq[3].y[i % 2];
	}
	return (result);
}
