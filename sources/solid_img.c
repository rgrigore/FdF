/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solid_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:12:35 by rgrigore          #+#    #+#             */
/*   Updated: 2018/01/30 15:12:38 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*solid_img(t_mlx *mlx, int color)
{
	t_img_data	img;
	int			i;

	img.bpp = 32;
	img.endi = 0;
	img.value = mlx_new_image(mlx->mlx, W_WIDTH, W_HEIGHT);
	img.l_size = W_WIDTH * img.bpp;
	img.pixel = (int*)mlx_get_data_addr(img.value, &img.bpp,
									&img.l_size, &img.endi);
	i = -1;
	while (++i < W_WIDTH * W_HEIGHT)
		*(img.pixel + i) = color;
	return (img.value);
}
