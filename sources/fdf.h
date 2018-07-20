/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:12:44 by rgrigore          #+#    #+#             */
/*   Updated: 2018/01/11 14:12:46 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <imlx.h>
# include <libft.h>
# include "fdf_menu.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <dirent.h>
# define UNIT 1
# define B_WIDTH 125
# define B_HEIGHT 40
# define Z_W 100
# define Z_H 75
# define ZOOM_MIN 1.2
# define ZOOM_MAX 5
# define P_COLOR 0X00FFFFFF
# define GRAD_W 110
# define GRAD_H 32
# define GRAD_D 4

typedef struct	s_line
{
	int				*line;
	struct s_line	*next;
}				t_line;

typedef struct	s_file
{
	t_line	*line_list;
	int		nr_col;
	int		nr_ln;
	char	*path;
	int		fd;
}				t_file;

void			get_input(t_data *data, int ac, char **av);
void			init_data(t_data *data);
void			init_color_array(t_menu *menu);
void			init_background_array(t_data *data, int w_w, int w_h);
void			fu_norminette(t_menu *menu);
void			*solid_img(t_mlx *mlx, int color);
void			clear_img(t_img_data *img, double *z_buff, int alp);
void			clear_button(t_img_data *image, int alpha);
void			load_map(t_data *data);
void			unload_map(t_data *data);
int				read_file(t_file *fl, char *map_name);
int				validate_file(char **line, int nr_col);
int				build_mesh(t_data *data, t_file *file);
void			set_mesh_colors(t_mesh *mesh, t_grad grad);
void			calculate_camera(t_mesh *mesh, t_camera *cam);
int				render(t_data *data);
void			render_zoom(t_data *data);
void			render_mesh_points(t_data *data, int **pixel, double zoom);
void			get_gradient(t_grad *gr, t_data *data, t_point p1, t_point p2);
void			project_mesh(t_mesh *mesh, t_camera *camera);
int				event_keyboard(int keycode, t_data *data);
int				event_mouse_move(int x, int y, t_data *data);
int				event_mouse_down(int key, int x, int y, t_data *data);
int				event_mouse_up(int button, int x, int y, t_data *data);
void			keyboard_manager(int key_c, t_v3 *trans, t_v3 *rot, double *os);
void			update_img_grad(t_data *data, int side);

#endif
