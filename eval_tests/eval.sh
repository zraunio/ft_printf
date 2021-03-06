#!/bin/sh

rm -rf printf_output ft_printf_output

make && make clean && make fclean && make re
if [ $? != 0 ]
then
	exit 1
fi

make test && gcc libft/libft.a -I libft/ -x c eval_tests/main_p.c.test -o print_orig

printf "\nRunning ft_printf... "
{ ./ft_printf | cat -e > ft_printf_output; }
printf "\nRunning printf... "
{ ./print_orig | cat -e > printf_output; }

valgrind --leak-check=yes --track-origins=yes ./ft_printf

make clean
