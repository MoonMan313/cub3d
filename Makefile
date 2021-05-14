# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evelina <evelina@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/13 13:49:35 by cdionna           #+#    #+#              #
#    Updated: 2021/05/14 19:35:04 by evelina          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

HEADER = cub3.h

SRCS = $(addprefix srcs/, $(addprefix parser/, parser_textures.c parser_map.c parser_params.c \
		first_parser.c) $(addprefix utils/, error.c gnl_utils.c gnl.c list.c \
		map_utils.c parser_utils.c pixel_get_put.c) $(addprefix rendering/, \
		draw_line.c draw_sprite.c) main.c motion_control.c raycasting.c \
		screen_bmp.c sprite.c motion_keys.c)


O_FILE = $(SRCS:.c=.o)

MLX_FLAGS = -L. ./minilibx_linux/libmlx.a -lm -lXext -lX11

C_FLAGS = -Wall -Wextra -Werror -I ./minilibx-linux/

all: $(NAME)

$(NAME): $(O_FILE)
	@$(MAKE) -C minilibx_linux all
	@gcc $(C_FLAGS) $(O_FILE) -o $(NAME) $(MLX_FLAGS)

%.o: %.c $(HEADER)
	@gcc -c $(C_FLAGS) $< -o $@

clean:
	@rm -rf $(O_FILE)

fclean: clean
	@$(MAKE) -C minilibx_linux clean
	@rm -rf $(NAME)

re:		fclean all

.PHONY : all clean fclean re
