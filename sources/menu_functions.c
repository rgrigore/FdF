/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 19:46:30 by rgrigore          #+#    #+#             */
/*   Updated: 2018/02/07 19:46:32 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	menu_exit(t_data *data)
{
	if (data)
		;
	exit(0);
}

void	menu_next_map(t_data *data)
{
	if (data->map_index < data->map_count - 1)
		data->map_index++;
	else
		data->map_index = 0;
	data->selected_map = data->map[data->map_index];
}

void	menu_previous_map(t_data *data)
{
	if (data->map_index > 0)
		data->map_index--;
	else
		data->map_index = data->map_count - 1;
	data->selected_map = data->map[data->map_index];
}

void	menu_select_map(t_data *data)
{
	if (ft_strcmp(data->selected_map, data->curr_map))
	{
		free(data->curr_map);
		data->curr_map = ft_strdup(data->selected_map);
		unload_map(data);
		load_map(data);
	}
}

void	menu_projection(t_data *data)
{
	if (data->camera.projection)
		data->camera.projection = 0;
	else
		data->camera.projection = 1;
	event_keyboard(NUM_5, data);
	calculate_projection(data);
}
