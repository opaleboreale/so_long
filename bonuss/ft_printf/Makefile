# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mferracc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/26 15:27:43 by mferracc          #+#    #+#              #
#    Updated: 2022/11/26 15:38:35 by mferracc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -c -g
AR = ar
ARFLAGS = rcs

INCLUDES = ft_printf.h
SRC = ft_printf.c ft_print_letter.c ft_print_numbers.c ft_print_pointer.c
OBJ = *.o

all : $(NAME)

$(NAME) :
	$(CC) $(CFLAGS) -c $(SRC) -I $(INCLUDES)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	ranlib $(NAME)

clean :
	/bin/rm -f $(OBJ)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
