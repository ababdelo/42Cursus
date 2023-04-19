# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/30 11:15:54 by ababdelo          #+#    #+#              #
#    Updated: 2023/03/30 12:25:16 by ababdelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Color
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
WHITE = \033[0;37m
BLUE = \033[1;34m

PRGM = push_swap

MAKE_MSG = --->> Mandatory part has been compiled successfully

CLN_MSG = --->> ' .o ' files has been removed successfully

FCLN_MSG = --->> executable file ' $(PRGM) ' has been removed successfully

CFLAGS = -Wall -Wextra -Werror

CC = gcc

RM = rm -f

SRCS = Sort_Utils_1.c Push_Swap.c PS_Utils.c Libft_Utils.c

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