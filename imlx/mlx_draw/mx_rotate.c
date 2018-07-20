/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 01:36:24 by rgrigore          #+#    #+#             */
/*   Updated: 2018/01/26 01:36:27 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx_draw.h>

void		mx_rotate(t_mx4 *transform, double x, double y, double z)
{
	*transform = mx_mult_4x4(*transform, mx_rot_x(x));
	*transform = mx_mult_4x4(*transform, mx_rot_y(y));
	*transform = mx_mult_4x4(*transform, mx_rot_z(z));
}
