/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 17:34:25 by rgrigore          #+#    #+#             */
/*   Updated: 2018/02/08 17:34:26 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Function for storing colors
*/

void	init_color_array(t_menu *menu)
{
	menu->color_count = 11;
	menu->colors = (int*)malloc(sizeof(int) * (menu->color_count + 2));
	menu->left_color = 0;
	menu->right_color = 0;
	menu->colors[0] = 0xFFFFFF;
	menu->colors[1] = 0x000000;
	menu->colors[2] = 0xFF0000;
	menu->colors[3] = 0x00FF00;
	menu->colors[4] = 0x0000FF;
	menu->colors[5] = 0x90ffaf;
	menu->colors[6] = 0xFFFF00;
	menu->colors[7] = 0xFF7700;
	menu->colors[8] = 0xA1A1F1;
	menu->colors[9] = 0xFF00FF;
	menu->colors[10] = 0xFF99FF;
}
