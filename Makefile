# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/27 10:47:16 by zraunio           #+#    #+#              #
#    Updated: 2021/01/27 10:49:53 by zraunio          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBNAME = libft/libft.a

HDR = ./

NAME = ft_printf

SRCS = 	convert.c \
		ft_printf.c \
		parse.c 

OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

clean: 
	make -C libft clean
	rm -f $(OBJS)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all

$(NAME): $(OBJS)
	make -C libft
	gcc -Wall -Wextra -Werror $(SRCS) $(LIBNAME) -I $(HDR) -o $(NAME)
