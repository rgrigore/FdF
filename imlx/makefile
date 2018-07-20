# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/13 15:59:45 by rgrigore          #+#    #+#              #
#    Updated: 2018/01/13 15:59:47 by rgrigore         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra -I ./includes

PATH_MLX = ../minilibx/

NAME = libimlx.a

SRC_DRAW = ./mlx_draw/draw_line.c \
		./mlx_draw/draw_curve.c \
		./mlx_draw/draw_circle.c \
		./mlx_draw/draw_poly.c \
		./mlx_draw/get_color.c \
		./mlx_draw/draw_img_line.c \
		./mlx_draw/mx_new.c \
		./mlx_draw/mx_scale.c \
		./mlx_draw/mx_rotate.c \
		./mlx_draw/mx_translate.c \
		./mlx_draw/to_perspective.c \
		./mlx_draw/to_ortho.c \
		./mlx_draw/calculate_projection.c \
		./mlx_draw/center_mesh.c \

SRC_MATH = ./mlx_math/mx_ortho.c \
		./mlx_math/mx_persp.c \
		./mlx_math/mx_trans.c \
		./mlx_math/mx_rot_x.c \
		./mlx_math/mx_rot_y.c \
		./mlx_math/mx_rot_z.c \
		./mlx_math/mx_mult_4x1.c \
		./mlx_math/mx_mult_4x4.c \
		./mlx_math/mx_scal_2x2.c \
		./mlx_math/mx_add_2x2.c \
		./mlx_math/mx_sub_2x2.c \
		./mlx_math/mx_mult_2x2.c \
		./mlx_math/mx_inv_2x2.c \
		./mlx_math/mx_inv_4x4.c \
		./mlx_math/v3_add.c \
		./mlx_math/mx_copy.c \

OBJ_DRAW = $(SRC_DRAW:.c=.o)

OBJ_MATH = $(SRC_MATH:.c=.o)

all :
	@gcc $(FLAGS) -c -I $(PATH_MLX) $(SRC_DRAW)
	@mv *.o ./mlx_draw/
	@gcc $(FLAGS) -c -I $(PATH_MLX) $(SRC_MATH)
	@mv *.o ./mlx_math/
	@ar rc $(NAME) $(OBJ_DRAW) $(OBJ_MATH)
	@ranlib $(NAME)

clean :
	@rm -f $(OBJ_DRAW)
	@rm -f $(OBJ_MATH)

fclean : clean
	@rm -f $(NAME)

re : fclean all
