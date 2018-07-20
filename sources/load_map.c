/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:24:11 by rgrigore          #+#    #+#             */
/*   Updated: 2018/01/29 17:24:12 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	load_error(int code)
{
	if (code == 1)
		ft_putendl("errorcode: 1;\nFailed to open specified map file");
	if (code == 2)
		ft_putendl("errorcode: 2;\nSpecified map file is empty");
	if (code == 3)
		ft_putendl("errorcode: 3;\nFailed to read from specified map file");
	if (code == 4)
		ft_putendl("errorcode: 4;\nFailed to build the point array");
	if (code == 5)
		ft_putendl("errorcode: 5;\nSpecified map file is invalid");
	if (code == 6)
		ft_putendl("errorcode: 6;\nFailed to build the mesh");
	if (code == 7)
	{
		ft_putendl("errorcode: 7;\nMaps folder empty and no map specified");
		exit(1);
	}
}

void		load_map(t_data *data)
{
	t_file	fl;
	int		code;

	if (data->curr_map)
	{
		if ((code = read_file(&fl, data->curr_map)))
			load_error(code);
		else if (!build_mesh(data, &fl))
			load_error(6);
	}
	else
		load_error(7);
	center_mesh(&data->mesh);
	calculate_camera(&data->mesh, &data->camera);
	calculate_projection(data);
}
