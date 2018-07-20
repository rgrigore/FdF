/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 15:35:23 by rgrigore          #+#    #+#             */
/*   Updated: 2018/02/08 15:35:25 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Function for cleaning the images that are to be rendered
*/

void	clear_img(t_img_data *image, double *z_buff, int alpha)
{
	int		i;
	int		*current_pixel;

	i = 0;
	while (i < W_WIDTH * W_HEIGHT)
	{
		current_pixel = (image->pixel) + i;
		if (alpha == 1)
			*current_pixel = 0X00000000;
		else
			*current_pixel = 0XFF000000;
		*(z_buff + i) = 10000000;
		i++;
	}
}
