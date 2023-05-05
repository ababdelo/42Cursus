# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/30 11:15:54 by ababdelo          #+#    #+#              #
#    Updated: 2023/05/05 16:34:09 by ababdelo         ###   ########.fr        #
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

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address 

CC = gcc

RM = rm -f

SRCS = Act_Utils_1.c Push_Swap.c PS_Utils_1.c PS_Utils_2.c Act_Utils_2.c Act_Utils_3.c\
	Lst_Utils_1.c Lst_Utils_2.c FT_Sort.c FT_Check.c Libft_Utils.c Lst_Utils_3.c\
	Sort_Utils_1.c Sort_Utils_2.c \
	

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