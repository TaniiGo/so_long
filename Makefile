# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keitanig <keitanig@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/21 12:41:00 by keitanig          #+#    #+#              #
#    Updated: 2022/05/23 16:59:12 by keitanig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC	= main.c map.c render.c move.c \
	move_utils.c error.c free.c

SRC_DIR = src/

SRCS = $(addprefix $(SRC_DIR), $(SRC))

OBJ	= $(SRCS:.c=.o)

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) -Imlx -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
