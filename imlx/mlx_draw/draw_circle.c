/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:32:49 by rgrigore          #+#    #+#             */
/*   Updated: 2018/01/13 15:32:51 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlx_draw.h>

void	draw_circle(t_mlx mlx, t_v2 org, int r, int color)
{
	int		x;
	int		y;

	x = -1;
	while (++x <= r * 5 / 7)
	{
		y = round(sqrt(r * r - x * x));
		mlx_pixel_put(mlx.mlx, mlx.win, x + org.x, y + org.y, color);
		mlx_pixel_put(mlx.mlx, mlx.win, y + org.x, x + org.y, color);
		mlx_pixel_put(mlx.mlx, mlx.win, -x + org.x, y + org.y, color);
		mlx_pixel_put(mlx.mlx, mlx.win, -y + org.x, x + org.y, color);
		mlx_pixel_put(mlx.mlx, mlx.win, x + org.x, -y + org.y, color);
		mlx_pixel_put(mlx.mlx, mlx.win, y + org.x, -x + org.y, color);
		mlx_pixel_put(mlx.mlx, mlx.win, -x + org.x, -y + org.y, color);
		mlx_pixel_put(mlx.mlx, mlx.win, -y + org.x, -x + org.y, color);
	}
}
