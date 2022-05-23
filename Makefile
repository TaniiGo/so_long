# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keitanig <keitanig@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/21 12:41:00 by keitanig          #+#    #+#              #
#    Updated: 2022/05/21 19:43:43 by keitanig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

SRC	=	src/main.c src/map.c src/render.c src/move.c \
		src/move_utils.c src/error.c src/free.c

OBJ	=	$(SRC:.c=.o)

CC	=	cc
CFLAGS	=	-Wall -Wextra -Werror

%.o: %.c
	$(CC) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
