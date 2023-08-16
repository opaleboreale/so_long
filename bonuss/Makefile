# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mferracc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/12 11:19:36 by mferracc          #+#    #+#              #
#    Updated: 2023/03/12 11:19:38 by mferracc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long_bonus

SRC = gnl/get_next_line_utils.c \
		gnl/get_next_line.c \
		src/main.c \
		src/utils.c \
		src/init.c \
		src/parsing.c \
		src/clear_all.c \
		src/get_map.c \
		src/parsing2.c \
		src/explore.c \
		src/start_play.c \
		src/quit_game.c \
		src/get_pos.c \
		src/game_loop.c \
		src/init_anim.c \
		src/anim.c \
		src/move.c \
		src/get_pos_utils.c \
		src/init_anim_utils.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -Iinc -O3 -o $@ -c $<

$(NAME) : $(OBJ)
	make -C ./libft
	make -C ./ft_printf
	$(CC) $(CFLAGS) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz libft/libft.a ft_printf/libftprintf.a -o $(NAME)

clean :
	make clean -C ./libft
	make clean -C ./ft_printf
	rm -rf src/*.o
	rm -rf bonus/*.o
	rm -rf gnl/*.o

fclean : clean
	make fclean -C ./libft
	make fclean -C ./ft_printf
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
#  Variables spéciales
#
#  $@ nom cible
#  $< nom première dépendance
#  $^ liste dépendances
#  $? liste dépendances plus récentes que la cible
#  $* nom fichier, sans son extension
