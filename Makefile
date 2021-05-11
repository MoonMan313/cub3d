# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdionna <cdionna@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/13 13:49:35 by cdionna           #+#    #+#              #
#    Updated: 2021/05/11 17:34:02 by cdionna          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

HEADER = cub3.h

SRCS = $(addprefix srcs/, $(addprefix parser/, parser_textures.c parser_map.c parser_params.c \
		first_parser.c) $(addprefix utils/, error.c gnl_utils.c gnl.c list.c \
		map_utils.c parser_utils.c pixel_get_put.c) $(addprefix rendering/, \
		draw_line.c draw_sprite.c) main.c motion_control.c raycasting.c \
		screen_bmp.c sprite.c)

O_FILE = $(SRCS:.c=.o)

C_FLAGS = -Wall -Wextra -Werror -Imlx

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(O_FILE)
	@$(MAKE) -C minilibx all
	@gcc $(C_FLAGS) $(MLX_FLAGS) $(O_FILE) -o $(NAME)

%.o: %.c $(HEADER)
	@gcc -c $(C_FLAGS) $< -o $@

clean:
	@rm -rf $(O_FILE)

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -C minilibx clean

re:		fclean all

.PHONY : all clean fclean re
