/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_math.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:00:31 by rgrigore          #+#    #+#             */
/*   Updated: 2018/01/13 17:00:33 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_MATH_H
# define MLX_MATH_H

# include <math.h>

typedef struct	s_v3
{
	double	x;
	double	y;
	double	z;
}				t_v3;

typedef struct	s_v2
{
	double	x;
	double	y;
}				t_v2;

typedef struct	s_mx4
{
	double	x[4];
	double	y[4];
	double	z[4];
	double	t[4];
}				t_mx4;

typedef struct	s_mx2
{
	double	x[2];
	double	y[2];
}				t_mx2;

typedef struct	s_mx1
{
	double	c[4];
}				t_mx1;

t_mx4			mx_ortho(float w, float h, float zn, float zf);
t_mx4			mx_persp(float fov_x, float fov_y, float zn, float zf);
t_mx4			mx_rot_x(float alpha);
t_mx4			mx_rot_y(float alpha);
t_mx4			mx_rot_z(float alpha);
t_mx4			mx_trans(t_v3 v);
t_mx2			mx_inv_2x2(t_mx2 mx);
t_mx4			mx_inv_4x4(t_mx4 mx);
t_mx2			mx_scal_2x2(t_mx2 mx, double d);
t_mx2			mx_add_2x2(t_mx2 m1, t_mx2 m2);
t_mx2			mx_sub_2x2(t_mx2 m1, t_mx2 m2);
t_mx2			mx_mult_2x2(t_mx2 m1, t_mx2 m2);
t_mx4			mx_mult_4x4(t_mx4 m1, t_mx4 m2);
t_v3			mx_mult_4x1(t_mx4 mx, t_v3 vt);
t_v3			v3_add(t_v3 v1, t_v3 v2);
void			mx_copy(t_mx4 *m1, t_mx4 m2);

#endif
