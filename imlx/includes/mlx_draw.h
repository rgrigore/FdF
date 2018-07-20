/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:36:16 by rgrigore          #+#    #+#             */
/*   Updated: 2018/01/11 15:36:18 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_DRAW_H
# define MLX_DRAW_H

# include <mlx.h>
# include <mlx_math.h>
# include <mlx_colors.h>

# define W_WIDTH 1200
# define W_HEIGHT 800
# define FOCAL_DIST 400

# define MLX_PITW mlx_put_image_to_window
# define MLX_XFTI mlx_xpm_file_to_image

typedef struct s_data	t_data;

typedef struct	s_img_data
{
	void	*value;
	int		l_size;
	int		*pixel;
	int		bpp;
	int		endi;
}				t_img_data;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
}				t_mlx;

typedef struct	s_camera
{
	t_v3	location;
	t_mx4	transform;
	double	aspect_ratio;
	int		projection;
	double	ortho_scale;
}				t_camera;

typedef struct	s_point
{
	t_v3	local;
	t_v3	world;
	t_v3	camera;
	t_v2	projected;
	int		color;
}				t_point;

typedef struct	s_mesh
{
	t_point	*points;
	int		*lines;
	int		pct_count;
	int		line_count;
	t_mx4	translation;
	t_mx4	rotation;
	t_mx4	init_translation;
	t_mx4	persp_rotation;
	t_mx4	ortho_rotation;
	double	width;
	double	depth;
	double	height_max;
	double	height_min;
}				t_mesh;

typedef struct	s_button
{
	int		id;
	t_v2	corner[4];
	void	(*target)(t_data*);
}				t_button;

typedef struct	s_menu
{
	t_button	*button;
	int			button_count;
	int			is_visible;
	t_img_data	gui;
	int			*colors;
	int			left_color;
	int			right_color;
	int			color_count;
	t_img_data	img_grad;
}				t_menu;

typedef struct	s_grad
{
	int	start;
	int	end;
}				t_grad;

struct			s_data
{
	t_mlx		mlx;
	t_camera	camera;
	t_mesh		mesh;
	t_menu		menu;
	void		**bg_array;
	int			bg;
	t_grad		grad;
	char		**map;
	int			map_count;
	int			map_index;
	char		*selected_map;
	char		*curr_map;
	t_img_data	image;
	double		*z_buffer;
	t_img_data	zoom;
	int			is_zoom;
	int			zoom_x;
	int			zoom_y;
	double		zoom_level;
	int			render_points;
};

void			mx_new(t_mx4 *mx);
void			center_mesh(t_mesh *mesh);
void			mx_scale(t_mx4 *transform, double scale);
void			mx_rotate(t_mx4 *transform, double x, double y, double z);
void			mx_translate(t_mx4 *transform, double x, double y, double z);
void			to_perspective(t_v3 v3, t_v2 *v2, int zoom);
void			to_ortho(t_v3 v3, t_v2 *v2, double zoom);
void			calculate_projection(t_data *data);
int				get_color(unsigned int start, unsigned int end, float position);
void			draw_img_line(int **s_p, t_point p1, t_point p2, double **z_b);
void			draw_line(t_mlx mlx, t_v2 p1, t_v2 p2, int color);
void			draw_circle(t_mlx mlx, t_v2 org, int r, int color);
void			draw_curve(t_mlx mlx, t_v2 p0, t_v2 p1, t_v2 p2);
void			draw_poly(int nr, ...);

#endif
