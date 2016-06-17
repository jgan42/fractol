# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgan <jgan@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/28 21:57:41 by jgan              #+#    #+#              #
#    Updated: 2016/01/13 16:37:33 by jgan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror -O3

NAME = fractol

SRC = main.c \
	core.c \
	painter.c \
	buddha.c \
	buddha2.c \
	cplx.c \
	key.c

OBJ = $(SRC:.c=.o)

MLX = -Lminilibx_macos -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	@make -k -C libft
	@make -k -C minilibx_macos
	@gcc $(FLAG) -o $(NAME) $(OBJ) $(MLX) -Llibft -lft
	@echo "$(NAME) created"

%.o: %.c
	@gcc $(FLAG) -c $< -o $@

clean:
	@make clean -k -C libft
	@rm -f $(OBJ)
	@echo "$(NAME) *.o deleted"

fclean: clean
	@make fclean -k -C libft
	@make clean -k -C minilibx_macos
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

push: fclean
	@git add --all
	@git commit -m fast_push
	@git push

.PHONY: all, clean, fclean, re
