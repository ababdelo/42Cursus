# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 13:44:33 by ababdelo          #+#    #+#              #
#    Updated: 2023/03/25 16:31:38 by ababdelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Color
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
WHITE = \033[0;37m
BLUE = \033[1;34m

PRGM = pipex

MAKE_MSG = --->> Mandatory part has been compiled successfully

CLN_MSG = --->> ' .o ' files has been removed successfully

FCLN_MSG = --->> executable file ' $(MAND_PRGM) ' has been removed successfully

CFLAGS = -Wall -Wextra -Werror -fsanitize=address

CC = cc

RM = rm -f

SRCS = main.c ft_check.c get_values.c initializer.c libft_utils_1.c libft_utils_2.c pipex_utils.c

OBJS = $(SRCS:.c=.o)

all :  $(PRGM)

$(PRGM) : $(OBJS)
	@echo "${GREEN}$(MAKE_MSG)${WHITE}"\
	&& $(CC) $(CFLAGS) $(OBJS) -o $(PRGM)

clean :
	@echo "${YELLOW}$(CLN_MSG)${WHITE}"\
	&& $(RM) $(OBJS)

fclean : clean
	@echo "${RED}$(FCLN_MSG)${WHITE}"\
	&& $(RM) $(PRGM)

re : fclean all

.PHONY: all clean fclean re