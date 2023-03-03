# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/03 11:51:18 by ababdelo          #+#    #+#              #
#    Updated: 2023/03/03 12:41:36 by ababdelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -Wall -Werror -Wextra
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
FILES = main.c so_long_utils.c
PRORM_NAME = so_long

all:
	$(CC) $(MLX_FLAGS) $(FILES) -o $(PRORM_NAME)
fclean: clean
clean:
	rm -rf $(PRORM_NAME)
run:
	./so_long maps/map_1.ber
re: fclean all