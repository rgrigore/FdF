/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 16:29:47 by rgrigore          #+#    #+#             */
/*   Updated: 2018/01/29 16:29:48 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Event for key press detection
*/

int			event_keyboard(int keycode, t_data *data)
{
	static t_v3	trans;
	static t_v3	rot;

	keyboard_manager(keycode, &trans, &rot, &data->camera.ortho_scale);
	mx_new(&data->mesh.translation);
	mx_new(&data->mesh.rotation);
	if (!data->camera.projection)
	{
		mx_rotate(&data->mesh.rotation, rot.x, rot.y, rot.z);
		mx_translate(&data->mesh.translation, trans.x, trans.y, trans.z);
	}
	else
	{
		mx_rotate(&data->mesh.rotation, -rot.x, -rot.y, rot.z);
		mx_translate(&data->mesh.translation, -trans.x, -trans.y, 0);
	}
	calculate_projection(data);
	return (0);
}

/*
** Event for mouse movement detection
*/

int			event_mouse_move(int mouse_x, int mouse_y, t_data *data)
{
	if ((mouse_y < 55 && mouse_y >= 0) && (mouse_x >= 0 && mouse_x <= W_WIDTH))
		data->menu.is_visible = 1;
	else
		data->menu.is_visible = 0;
	if (data->is_zoom)
	{
		data->zoom_x = mouse_x;
		data->zoom_y = mouse_y;
	}
	return (0);
}

/*
** Function for checking the location of a mouse click
*/

static void	check_mouse_click(int mouse_x, int mouse_y, t_data *data)
{
	int	i;

	if (data->menu.is_visible)
	{
		i = -1;
		while (++i < data->menu.button_count)
		{
			if (mouse_x >= data->menu.button[i].corner[0].x &&
				mouse_x <= data->menu.button[i].corner[1].x &&
				mouse_y >= data->menu.button[i].corner[0].y &&
				mouse_y <= data->menu.button[i].corner[3].y)
				data->menu.button[i].target(data);
		}
	}
}

/*
** Event for mouse press detection
*/

int			event_mouse_down(int button, int mouse_x, int mouse_y, t_data *data)
{
	if (button == 2)
	{
		data->is_zoom = 1;
		data->zoom_x = mouse_x;
		data->zoom_y = mouse_y;
	}
	if (button == 4 && data->is_zoom == 1 && data->zoom_level <= ZOOM_MAX)
		data->zoom_level += 0.2;
	if (button == 5 && data->is_zoom == 1 && data->zoom_level >= ZOOM_MIN)
		data->zoom_level -= 0.2;
	check_mouse_click(mouse_x, mouse_y, data);
	return (0);
}

/*
** Event for mouse release detection
*/

int			event_mouse_up(int button, int mouse_x, int mouse_y, t_data *data)
{
	if (mouse_x && mouse_y)
		;
	if (button == 2)
	{
		data->is_zoom = 0;
		data->zoom_level = ZOOM_MIN;
	}
	return (0);
}
