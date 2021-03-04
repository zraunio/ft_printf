/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:07:07 by zraunio           #+#    #+#             */
/*   Updated: 2021/03/04 13:23:17 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"

void	test_multi(void)
{
	char	*p = ft_strnew(3);

	ft_printf("		hello %s, you are %3d years-old and i will kidnap you in\n %.4Lf\n months at %x hours with %c%c%c others\n at %p\nMUHAHAHAHAHAH",
	"stranger", 34, 4.82749382382, 1600, '\0', '\t', '|', p);
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
	ft_printf("dd&i w/ ll\n%lld\n%lli", l, l);
	ft_printf("\n----------\n");
	for (d = 0; d < 20; d++)
		ft_printf("%d\n", d);
	for (d = 0; d > -20; d--)
		ft_printf("%d\n", d);
	ft_printf("u w/ l&ll\n%lu\n%llu", l, ll);
	for (ll = 40000; ll < 40100; ll++)
		ft_printf("%u\n", ll);
}

int		main(void)
{
	test_multi();
	test_decimal();
	return (0);
}
