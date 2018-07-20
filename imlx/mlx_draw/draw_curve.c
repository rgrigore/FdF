/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_curve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:58:42 by rgrigore          #+#    #+#             */
/*   Updated: 2018/01/12 11:01:09 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx_draw.h>
#include <math.h>

void	draw_curve(t_mlx mlx, t_v2 p0, t_v2 p1, t_v2 p2)
{
	t_v2	p;
	double	i;

	i = 0;
	while (i <= 1)
	{
		p.x = p0.x * i * i + p1.x * 2 * i * (1 - i) + p2.x * pow((1 - i), 2);
		p.y = p0.y * i * i + p1.y * 2 * i * (1 - i) + p2.y * pow((1 - i), 2);
		mlx_pixel_put(mlx.mlx, mlx.win, p.x, p.y, 0x009900ff);
		i += 0.00005;
	}
}
