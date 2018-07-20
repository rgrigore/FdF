/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 18:48:19 by rgrigore          #+#    #+#             */
/*   Updated: 2018/01/29 18:48:21 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_menu(t_menu *menu, void *mlx, int *b_w, int *b_h)
{
	int	i;

	menu->button_count = 12;
	menu->is_visible = 0;
	menu->button = (t_button*)malloc(sizeof(t_button) * menu->button_count);
	i = -1;
	while (++i < menu->button_count)
	{
		menu->button[i].id = i;
		menu->button[i].corner[0].y = 7;
		menu->button[i].corner[1].y = 7;
		menu->button[i].corner[2].y = 45;
		menu->button[i].corner[3].y = 45;
	}
	fu_norminette(menu);
	init_color_array(menu);
	menu->gui.value = mlx_xpm_file_to_image(mlx, "./gui/menu.XPM", b_w, b_h);
}

static void	init_objects(t_mesh *mesh, t_camera *camera)
{
	mesh->points = NULL;
	mesh->lines = NULL;
	mx_new(&mesh->translation);
	mx_new(&mesh->rotation);
	mx_new(&camera->transform);
	camera->location.x = 0;
	camera->location.y = 0;
	camera->location.z = 0;
	camera->location = mx_mult_4x1(camera->transform, camera->location);
	camera->projection = 0;
	camera->aspect_ratio = (double)W_WIDTH / (double)W_HEIGHT;
}

static void	init_image(void *mlx, t_img_data *image, int w, int h)
{
	image->bpp = 32;
	image->endi = 0;
	image->value = mlx_new_image(mlx, w, h);
	image->l_size = w * image->bpp;
	image->pixel = (int*)mlx_get_data_addr(image->value, &image->bpp,
									&image->l_size, &image->endi);
}

static void	init_map_array(char ***map, int *map_count)
{
	DIR				*dir;
	struct dirent	*dd;
	int				cont;

	*map_count = 0;
	if ((dir = opendir("./maps")))
	{
		cont = 0;
		while ((dd = readdir(dir)))
			if (ft_strstr(dd->d_name + ft_strlen(dd->d_name) - 4, ".fdf"))
				cont++;
		closedir(dir);
		dir = opendir("./maps");
		*map_count = cont;
		*map = (char**)ft_memalloc(sizeof(char*) * (cont + 2));
		while ((dd = readdir(dir)))
			if (ft_strstr(dd->d_name + ft_strlen(dd->d_name) - 4, ".fdf"))
				(*map)[--cont] = ft_strdup(dd->d_name);
		closedir(dir);
	}
}

/*
** Initiate all the transform matrixes and the menu
*/

void		init_data(t_data *data)
{
	int	wid;
	int	hei;

	wid = W_WIDTH;
	hei = W_HEIGHT;
	data->grad.start = 0x00FFFFFF;
	data->grad.end = 0x00FFFFFF;
	wid = 1200;
	hei = 53;
	data->z_buffer = (double*)malloc(sizeof(double) * W_WIDTH * W_HEIGHT);
	init_map_array(&data->map, &data->map_count);
	init_background_array(data, W_WIDTH, W_HEIGHT);
	data->curr_map = NULL;
	init_menu(&data->menu, data->mlx.mlx, &wid, &hei);
	init_objects(&data->mesh, &data->camera);
	init_image(data->mlx.mlx, &data->image, W_WIDTH, W_HEIGHT);
	init_image(data->mlx.mlx, &data->zoom, W_WIDTH, W_HEIGHT);
	init_image(data->mlx.mlx, &data->menu.img_grad, GRAD_W, GRAD_H);
	data->is_zoom = 0;
	data->render_points = 0;
	data->zoom_level = ZOOM_MIN;
}
