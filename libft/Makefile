# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgan <jgan@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/10 21:57:00 by jgan              #+#    #+#              #
#    Updated: 2016/02/29 13:48:48 by jgan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror -O3

NAME = libft.a

SRC = ft_atoi.c \
	ft_atoi_base.c \
	ft_atoli.c \
	ft_bzero.c \
	ft_gnl.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_itoa_base.c \
	ft_lstadd.c \
	ft_lstaddend.c \
	ft_lstdel.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_memalloc.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memdel.c \
	ft_memmove.c \
	ft_memset.c \
	ft_printf.c \
	ft_putchar.c \
	ft_putchar_fd.c \
	ft_putendl.c \
	ft_putendl_fd.c \
	ft_putinttab.c \
	ft_putnbr.c \
	ft_putnbr_fd.c \
	ft_putstr.c \
	ft_putstr_fd.c \
	ft_putstrtab.c \
	ft_straddc.c \
	ft_strcat.c \
	ft_strchr.c \
	ft_strclr.c \
	ft_strcmp.c \
	ft_strcpy.c \
	ft_strdel.c \
	ft_strdup.c \
	ft_strequ.c \
	ft_strisnum.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlen.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strncat.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_strndup.c \
	ft_strnequ.c \
	ft_strnew.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strsplit.c \
	ft_strsplitstr.c \
	ft_strstr.c \
	ft_strsub.c \
	ft_strtablen.c \
	ft_strtrim.c \
	ft_swap.c \
	ft_tolower.c \
	ft_toupper.c \
\
	checker.c \
	info.c \
	print_char.c \
	print_int.c \
	print_str.c \
	print_uint.c \
	print_float.c \
	type_len.c \

OBJ = $(SRC:.c=.o)

COMMIT = fast_push

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "libft built & indexed"

%.o: %.c
	@gcc $(FLAG) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "libft .o deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "libft.a deleted"

re: fclean all

push: fclean
	@git add --all
	@git commit -m $(COMMIT)
	@git push
	
.PHONY: all, clean, fclean, re
