/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_poly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:44:22 by rgrigore          #+#    #+#             */
/*   Updated: 2018/01/13 15:44:25 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx_draw.h>
#include <stdarg.h>

void	draw_poly(int nr, ...)
{
	int		i;
	va_list	valist;
	t_v2	prev;
	t_v2	current;
	t_mlx	mlx;

	va_start(valist, nr);
	mlx = va_arg(valist, t_mlx);
	prev = va_arg(valist, t_v2);
	i = 1;
	while (++i < nr)
	{
		current = va_arg(valist, t_v2);
		draw_line(mlx, prev, current, 0X00DDA1A1);
		prev = current;
	}
	va_end(valist);
}
