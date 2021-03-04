/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:07:07 by zraunio           #+#    #+#             */
/*   Updated: 2021/03/04 15:28:11 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"
#include "stdio.h"

void	test_multi(void)
{
	char	*p = ft_strnew(3);

	ft_printf("		hello %s, you are %3d years-old and i will kidnap you in\n %.4Lf\n months at %x hours",
	"stranger", 34, 4.82749382382, 1600);
	ft_printf("\n----------\n");
	ft_printf("%s%s%d%d", "string", NULL, 923, -8988);
	ft_printf("\n----------\n");
	ft_printf("%o%u%lo%zu", 8888, 8888, 999999, 999999);
	ft_printf("\n----------\n");
	ft_printf("%c, %%, %%, %6l%, %c", 56, 120);
	ft_printf("\n----------\n");
	ft_strdel(&p);
}

void	test_decimal(void)
{
	int				d = 0;
	int				i = -12345678;
	long long int	l = 4294967295;
	unsigned long	ll = 8294967295;

	ft_printf("d&i w/ l\n%ld\n%li", d, i);
	ft_printf("\n----------\n");
	ft_printf("d&i w/ ll\n%lld\n%lli", l, l);
	ft_printf("\n----------\n");
	ft_printf("precision of .5 %.5d\nmin width of 40 %40d \n", i, i);
	ft_printf("same with 0&+ %+0.5i\nthen with - and ' ' % -40i \n", i, i);
	for (d = 0; d < 20; d++)
		ft_printf("%d\n", d);
	for (d = 0; d > -20; d--)
		ft_printf("%d\n", d);
	ft_printf("u w/ l&ll\n%lu\n%llu", l, ll);
	ft_printf("precision of .5 %.5u\nmin width of 40 %40u\n", l, l);
	ft_printf("same with 0&+ %+0.5u\nthen with - and ' ' % -40u\n", l, l);
	for (ll = 40000; ll < 40100; ll++)
		ft_printf("%u\n", ll);
}

void	test_spc(void)
{
	char	*p;
	char	*s;
	p = ft_strnew(3);
	s = ft_strdup("and IIIIIIIIIIIiIIIII will aLLLLways\n");

	ft_printf("hello |%c| that was a NULL char", 0);
	ft_printf("\n----------\n");
	ft_printf("hello |%c| that was another char", 123);
	ft_printf("\n----------\n");
	ft_printf("this is s |%s|\n", s);
	ft_printf("this is s with precision |%60s|\n", s);
	ft_printf("this is s with '-' precision |%-60s|");
	ft_printf("\n----------\n");
	ft_printf("this is p |%p|\nthis is p with precision |%20p|\nthis is p with '-' precision |%-20p|", p, p, p);

	ft_memdel((void*)&p);
	ft_memdel((void*)&s);
}

int		main(void)
{
	test_multi();
	test_decimal();
	test_spc();
	return (0);
}
