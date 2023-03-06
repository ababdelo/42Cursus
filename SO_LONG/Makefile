# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/03 11:51:18 by ababdelo          #+#    #+#              #
#    Updated: 2023/03/06 23:00:40 by ababdelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAND_PRGM = so_long

BON_PGRM = so_long_bonus

CFLAGS = -Wall -Wextra -Werror -fsanitize=address

CC = cc

RM = rm -f

MAND_SRCS = Mandatory/main.c Mandatory/initializer.c Mandatory/functions_check.c \
			Mandatory/utils_function_1.c Mandatory/utils_function_2.c Mandatory/check_textures_availability.c \
			Mandatory/get_values.c Mandatory/check_map_path.c Mandatory/actions.c

BON_SRCS = Bonus/main.c Bonus/initializer.c Bonus/functions_check.c Bonus/utils_function_1.c \
			Bonus/utils_function_2.c Bonus/check_textures_availability.c Bonus/get_values.c \
			Bonus/ft_animate.c Bonus/check_map.c Bonus/actions.c Bonus/print_2_win.c

MAND_OBJS = $(MAND_SRCS:.c=.o)

BON_OBJS = $(BON_SRCS:.c=.o)

all : $(MAND_PRGM)

$(MAND_PRGM) : $(MAND_OBJS)
	$(CC) $(CFLAGS) $(MAND_OBJS) -lmlx -framework OpenGL -framework AppKit -o $(MAND_PRGM)

bonus : $(BON_PGRM)

$(BON_PGRM) : $(BON_OBJS)
	$(CC) $(CFLAGS) $(BON_OBJS) -lmlx -framework OpenGL -framework AppKit -o $(BON_PGRM)

clean :
	@$(RM) $(MAND_OBJS) $(BON_OBJS)

fclean : clean
	@$(RM) $(MAND_PRGM) $(BON_PGRM)

re : fclean all bonus

run_mand : clean 
	@clear && ./$(MAND_PRGM) maps/map_1.ber

run_bonus : clean
	@clear && ./$(BON_PGRM) maps/map_3.ber

.PHONY: all bonus clean fclean re run_mand run_bonus