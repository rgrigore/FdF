/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_background_array.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 13:28:16 by rgrigore          #+#    #+#             */
/*   Updated: 2018/02/09 13:28:17 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Function that checks the backgrounds folder for images and stores them
*/

void	init_background_array(t_data *data, int w_w, int w_h)
{
	DIR				*dir;
	struct dirent	*dd;
	int				cont;

	dir = opendir("./backgrounds");
	cont = 0;
	while ((dd = readdir(dir)))
		if (ft_strstr(dd->d_name + ft_strlen(dd->d_name) - 4, ".XPM"))
			cont++;
	closedir(dir);
	dir = opendir("./backgrounds");
	data->bg_array = (void**)ft_memalloc(sizeof(void*) * ((cont += 1) + 1));
	(data->bg_array)[0] = solid_img(&data->mlx, 0X00000000);
	while ((dd = readdir(dir)))
		if (ft_strstr(dd->d_name + ft_strlen(dd->d_name) - 4, ".XPM"))
			(data->bg_array)[--cont] = mlx_xpm_file_to_image(data->mlx.mlx,
				ft_strjoin("./backgrounds/", dd->d_name), &w_w, &w_h);
	data->bg = 0;
	closedir(dir);
}
