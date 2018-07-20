# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/14 15:21:45 by rgrigore          #+#    #+#              #
#    Updated: 2018/01/14 15:21:46 by rgrigore         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

MLX_PATH = /usr/local/

LIB_PATH = ./imlx

LIBFT_PATH = ./libft

SRC_PATH = ./sources

SRC = $(SRC_PATH)/main.c \
		$(SRC_PATH)/init_data.c \
		$(SRC_PATH)/build_mesh.c \
		$(SRC_PATH)/calculate_camera.c \
		$(SRC_PATH)/clear_button.c \
		$(SRC_PATH)/clear_image.c \
		$(SRC_PATH)/events.c \
		$(SRC_PATH)/fu_norminette.c \
		$(SRC_PATH)/get_input.c \
		$(SRC_PATH)/init_background_array.c \
		$(SRC_PATH)/init_color_array.c \
		$(SRC_PATH)/keyboard_manager.c \
		$(SRC_PATH)/load_map.c \
		$(SRC_PATH)/menu_functions.c \
		$(SRC_PATH)/menu_functions1.c \
		$(SRC_PATH)/menu_functions2.c \
		$(SRC_PATH)/read_file.c \
		$(SRC_PATH)/render_mesh_points.c \
		$(SRC_PATH)/render_zoom.c \
		$(SRC_PATH)/render.c \
		$(SRC_PATH)/set_mesh_colors.c \
		$(SRC_PATH)/solid_img.c \
		$(SRC_PATH)/unload_map.c \
		$(SRC_PATH)/update_img_grad.c \
		$(SRC_PATH)/validate_file.c \

OBJ = $(SRC:.c=.o)

INCLUDES = -I $(MLX_PATH)/include -I $(LIB_PATH)/includes -I $(LIBFT_PATH)/includes

FLAGS = -Wall -Werror -Wextra $(INCLUDES)

FRMW = -framework OpenGL -framework AppKit

LIBS = -L $(MLX_PATH)/lib -lmlx -L $(LIB_PATH) -limlx -L $(LIBFT_PATH) -lft

all:
	@gcc $(FLAGS) -c $(SRC)
	@mv *.o $(SRC_PATH)
	@gcc $(FLAGS) $(LIBS) $(FRMW) $(OBJ) -o $(NAME)

full:
	@make -C ./libft
	@make -C ./imlx
	@make

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

fullclean:	fclean
	@make -C libft fclean
	@make -C imlx fclean

re:	fclean all

fullre:
	@make -C libft re
	@make -C imlx re
	@make re
