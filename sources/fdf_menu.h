/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_menu.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 20:01:41 by rgrigore          #+#    #+#             */
/*   Updated: 2018/02/07 20:01:42 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_MENU_H
# define FDF_MENU_H

void	menu_select_gradient(t_data *data);
void	menu_next_left_color(t_data *data);
void	menu_previous_left_color(t_data *data);
void	menu_next_right_color(t_data *data);
void	menu_previous_right_color(t_data *data);

void	menu_points(t_data *data);

void	menu_select_map(t_data *data);
void	menu_next_map(t_data *data);
void	menu_previous_map(t_data *data);

void	menu_background(t_data *data);

void	menu_projection(t_data *data);

void	menu_exit(t_data *data);

#endif
