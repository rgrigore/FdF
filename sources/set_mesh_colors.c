/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mesh_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 13:17:40 by rgrigore          #+#    #+#             */
/*   Updated: 2018/02/08 13:17:42 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_mesh_colors(t_mesh *mesh, t_grad grad)
{
	int	i;

	i = -1;
	while (++i < mesh->pct_count)
	{
		if (mesh->height_min != mesh->height_max)
			mesh->points[i].color = get_color(grad.start, grad.end,
				((mesh->points[i].local.y - mesh->height_min) /
				(mesh->height_max - mesh->height_min)));
		else
			mesh->points[i].color = grad.end;
	}
}
