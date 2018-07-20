/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 19:46:30 by rgrigore          #+#    #+#             */
/*   Updated: 2018/02/07 19:46:32 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	menu_background(t_data *data)
{
	if (data->bg_array[data->bg + 1])
		data->bg++;
	else
		data->bg = 0;
}

void	menu_points(t_data *data)
{
	if (data->render_points)
		data->render_points = 0;
	else
		data->render_points = 1;
}
