# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/27 10:47:16 by zraunio           #+#    #+#              #
#    Updated: 2021/03/06 19:24:34 by zraunio          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBNAME = libft/libft.a

HDR = ./

NAME = libftprintf.a

TEST = ft_printf

SRCS = 	ft_printf.c \
		print_split.c \
		convert.c \
		parse.c\
		floats.c \
		diu.c \
		oxx.c \
		print_oxx.c \
		spc.c \

MAINS = eval_tests/main_ft.c.test

OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): 
	make -C libft
	@gcc -Wall -Wextra -Werror -c $(SRCS)
	@cp libft/libft.a libftprintf.a
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean: 
	/bin/rm -f $(OBJS)
	@make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f $(TEST)
	@make -C libft/ fclean

test: fclean
	make -C libft
	gcc -Wall -Wextra -Werror -g $(SRCS) $(LIBNAME) -x c $(MAINS) -I $(HDR) -o $(TEST)

re: fclean all

	rm -f $(OBJS)
