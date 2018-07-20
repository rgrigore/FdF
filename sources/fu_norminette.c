/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fu_norminette.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 19:07:14 by rgrigore          #+#    #+#             */
/*   Updated: 2018/02/07 19:07:15 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Set the location of each button in the gui as well as the targets
*/

void	fu_norminette4(t_menu *menu)
{
	menu->button[0].target = menu_select_gradient;
	menu->button[1].target = menu_next_left_color;
	menu->button[2].target = menu_previous_left_color;
	menu->button[3].target = menu_next_right_color;
	menu->button[4].target = menu_previous_right_color;
	menu->button[5].target = menu_points;
	menu->button[6].target = menu_select_map;
	menu->button[7].target = menu_next_map;
	menu->button[8].target = menu_previous_map;
	menu->button[9].target = menu_background;
	menu->button[10].target = menu_projection;
	menu->button[11].target = menu_exit;
}

void	fu_norminette3(t_menu *menu)
{
	menu->button[1].corner[2].y = 26;
	menu->button[1].corner[3].y = 26;
	menu->button[2].corner[0].y = 27;
	menu->button[2].corner[1].y = 27;
	menu->button[3].corner[2].y = 26;
	menu->button[3].corner[3].y = 26;
	menu->button[4].corner[0].y = 27;
	menu->button[4].corner[1].y = 27;
	menu->button[7].corner[2].y = 26;
	menu->button[7].corner[3].y = 26;
	menu->button[8].corner[0].y = 27;
	menu->button[8].corner[1].y = 27;
	fu_norminette4(menu);
}

void	fu_norminette2(t_menu *menu)
{
	menu->button[6].corner[0].x = 443;
	menu->button[6].corner[1].x = 715;
	menu->button[6].corner[2].x = 715;
	menu->button[6].corner[3].x = 443;
	menu->button[7].corner[0].x = 716;
	menu->button[7].corner[1].x = 744;
	menu->button[7].corner[2].x = 744;
	menu->button[7].corner[3].x = 716;
	menu->button[8].corner[0].x = 716;
	menu->button[8].corner[1].x = 744;
	menu->button[8].corner[2].x = 744;
	menu->button[8].corner[3].x = 716;
	menu->button[9].corner[0].x = 877;
	menu->button[9].corner[1].x = 987;
	menu->button[9].corner[2].x = 987;
	menu->button[9].corner[3].x = 877;
	menu->button[10].corner[0].x = 1010;
	menu->button[10].corner[1].x = 1120;
	menu->button[10].corner[2].x = 1120;
	menu->button[10].corner[3].x = 1010;
	menu->button[11].corner[0].x = 1167;
	menu->button[11].corner[1].x = 1195;
	menu->button[11].corner[2].x = 1195;
	menu->button[11].corner[3].x = 1167;
	fu_norminette3(menu);
}

void	fu_norminette(t_menu *menu)
{
	menu->button[0].corner[0].x = 35;
	menu->button[0].corner[1].x = 152;
	menu->button[0].corner[2].x = 152;
	menu->button[0].corner[3].x = 35;
	menu->button[1].corner[0].x = 7;
	menu->button[1].corner[1].x = 34;
	menu->button[1].corner[2].x = 34;
	menu->button[1].corner[3].x = 7;
	menu->button[2].corner[0].x = 7;
	menu->button[2].corner[1].x = 34;
	menu->button[2].corner[2].x = 34;
	menu->button[2].corner[3].x = 7;
	menu->button[3].corner[0].x = 153;
	menu->button[3].corner[1].x = 180;
	menu->button[3].corner[2].x = 180;
	menu->button[3].corner[3].x = 153;
	menu->button[4].corner[0].x = 153;
	menu->button[4].corner[1].x = 180;
	menu->button[4].corner[2].x = 180;
	menu->button[4].corner[3].x = 153;
	menu->button[5].corner[0].x = 205;
	menu->button[5].corner[1].x = 315;
	menu->button[5].corner[2].x = 315;
	menu->button[5].corner[3].x = 205;
	fu_norminette2(menu);
}
