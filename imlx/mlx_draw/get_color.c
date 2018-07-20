/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 18:40:38 by rgrigore          #+#    #+#             */
/*   Updated: 2018/02/02 18:40:39 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx_draw.h>

int		get_color(unsigned int start, unsigned int end, float position)
{
	int		current_color;
	t_argb	c1;
	t_argb	c2;
	t_argb	c;

	if (position > 1)
		position = 1;
	c1.r = start >> 16;
	c1.g = start >> 8 & 0xff;
	c1.b = start & 0xff;
	c2.r = end >> 16;
	c2.g = end >> 8 & 0xff;
	c2.b = end & 0xff;
	c.r = c1.r + position * (c2.r - c1.r);
	c.g = c1.g + position * (c2.g - c1.g);
	c.b = c1.b + position * (c2.b - c1.b);
	current_color = (1 << 24) + (c.r << 16) + (c.g << 8) + (c.b | 0);
	return (current_color);
}
