
CC = gcc -Wall -Werror -Wextra
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
FILES = main.c
PRORM_NAME = so_long

all:
	$(CC) $(MLX_FLAGS) $(FILES) -o $(PRORM_NAME)
fclean: clean
clean:
	rm -rf a.out
re: fclean all