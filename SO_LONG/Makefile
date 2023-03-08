# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/03 11:51:18 by ababdelo          #+#    #+#              #
#    Updated: 2023/03/08 16:02:43 by ababdelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Color
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
WHITE = \033[0;37m


MAND_MSG = --> Mandatory part has been made successfully <--

BON_MSG = --> Bonus part has been made successfully <--

MAND_PRGM = so_long

BON_PGRM = so_long_bonus

CLN_MSG = ' .o ' files has been removed successfully

FCLN_MSG = executables files has been removed successfully

CFLAGS = -Wall -Wextra -Werror -fsanitize=address

CC = cc

RM = rm -f

MAND_SRCS = Mandatory/main.c Mandatory/initializer.c Mandatory/functions_check.c Mandatory/check_utils.c \
			Mandatory/utils_function_1.c Mandatory/utils_function_2.c Mandatory/check_textures_availability.c \
			Mandatory/get_values.c Mandatory/check_items_reachability.c Mandatory/actions.c 

BON_SRCS = Bonus/main.c Bonus/initializer.c Bonus/functions_check.c Bonus/utils_function_1.c \
			Bonus/utils_function_2.c Bonus/check_textures_availability.c Bonus/get_values.c \
			Bonus/animate.c Bonus/ft_animate.c Bonus/check_map.c Bonus/check_items_reachability.c Bonus/actions.c\
			Bonus/get_key.c Bonus/print_2_win.c

MAND_OBJS = $(MAND_SRCS:.c=.o)

BON_OBJS = $(BON_SRCS:.c=.o)

all :  $(MAND_PRGM)

$(MAND_PRGM) : $(MAND_OBJS)
	@echo "${GREEN}$(MAND_MSG)${WHITE}"\
	&& $(CC) $(CFLAGS) $(MAND_OBJS) -lmlx -framework OpenGL -framework AppKit -o $(MAND_PRGM)

bonus : $(BON_PGRM)

$(BON_PGRM) : $(BON_OBJS)
	@echo "${GREEN}$(BON_MSG)${WHITE}"\
	&& $(CC) $(CFLAGS) $(BON_OBJS) -lmlx -framework OpenGL -framework AppKit -o $(BON_PGRM)

clean :
	@echo "${YELLOW}$(CLN_MSG)${WHITE}"\
	&& $(RM) $(MAND_OBJS) $(BON_OBJS)

fclean : clean
	@echo "${RED}$(FCLN_MSG)${WHITE}"\
	&& $(RM) $(MAND_PRGM) $(BON_PGRM)

re : fclean all bonus

run_mand : clean
	@clear && ./$(MAND_PRGM) maps/map_1.ber
	
run_bonus : clean
	@clear && ./$(BON_PGRM) maps/map_3.ber

.PHONY: all bonus clean fclean re run_mand run_bonus
