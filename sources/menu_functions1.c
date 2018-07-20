/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_functions1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 19:46:30 by rgrigore          #+#    #+#             */
/*   Updated: 2018/02/07 19:46:32 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	menu_select_gradient(t_data *data)
{
	if (data->menu.colors[data->menu.left_color] != data->grad.start ||
		data->menu.colors[data->menu.right_color] != data->grad.end)
	{
		data->grad.start = data->menu.colors[data->menu.left_color];
		data->grad.end = data->menu.colors[data->menu.right_color];
	}
	set_mesh_colors(&data->mesh, data->grad);
}

void	menu_next_left_color(t_data *data)
{
	if (data->menu.left_color < data->menu.color_count - 1)
		data->menu.left_color++;
	else
		data->menu.left_color = 0;
	update_img_grad(data, 0);
}

void	menu_previous_left_color(t_data *data)
{
	if (data->menu.left_color > 0)
		data->menu.left_color--;
	else
		data->menu.left_color = data->menu.color_count - 1;
	update_img_grad(data, 0);
}

void	menu_next_right_color(t_data *data)
{
	if (data->menu.right_color < data->menu.color_count - 1)
		data->menu.right_color++;
	else
		data->menu.right_color = 0;
	update_img_grad(data, 1);
}

void	menu_previous_right_color(t_data *data)
{
	if (data->menu.right_color > 0)
		data->menu.right_color--;
	else
		data->menu.right_color = data->menu.color_count - 1;
	update_img_grad(data, 1);
}
