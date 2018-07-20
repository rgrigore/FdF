/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 12:16:53 by rgrigore          #+#    #+#             */
/*   Updated: 2018/02/09 12:16:54 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	reset(t_v3 *trans, t_v3 *rot, double *os)
{
	rot->y = 0;
	rot->x = 0;
	rot->z = 0;
	trans->x = 0;
	trans->y = 0;
	trans->z = 0;
	*os = 1;
}

void		keyboard_manager(int keycode, t_v3 *trans, t_v3 *rot, double *os)
{
	if (keycode == ARROW_LEFT || keycode == ARROW_RIGHT)
		rot->y += (keycode == ARROW_LEFT) ? 1 : -1;
	if (keycode == ARROW_DOWN || keycode == ARROW_UP)
		rot->x += (keycode == ARROW_DOWN) ? 1 : -1;
	if (keycode == NUM_7 || keycode == NUM_9)
		rot->z += (keycode == NUM_7) ? -1 : 1;
	if (keycode == NUM_4 || keycode == NUM_6)
		trans->x += (keycode == NUM_4) ? -1 * UNIT : 1 * UNIT;
	if (keycode == NUM_8 || keycode == NUM_2)
		trans->y += (keycode == NUM_8) ? -1 * UNIT : 1 * UNIT;
	if (keycode == NUM_PLUS || keycode == NUM_MINUS)
	{
		*os += (keycode == NUM_PLUS) ? 0.05 * UNIT : -0.05 * UNIT;
		trans->z += (keycode == NUM_PLUS) ? -1 * UNIT : 1 * UNIT;
	}
	if (keycode == NUM_5)
		reset(trans, rot, os);
	if (keycode == KEY_ESCAPE)
		exit(0);
}
