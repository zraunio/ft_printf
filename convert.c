/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 10:38:57 by zraunio           #+#    #+#             */
/*   Updated: 2021/02/01 15:23:31 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		decimal_nbr(va_list list, t_flags *flg)
{
	if (flg->h)
		ft_putshort((short)va_arg(list, int));
		//printf's short CONVERTS ints to short when cast
		//do we need a shortoa? lol
	else if (flg->hh)
		ft_putchar((signed char)va_arg(list, int));
//	else if (flg->l)
		//ft_putlong(va_arg(list, long int));
	//else if (flg->ll)
	else
		ft_putnbr(va_arg(list, int));
	
}

void		ft_convert(char *str, va_list list, t_flags *flg)
{
	if (str[ft_strlen(str) - 1] == 's')
		ft_putstr(va_arg(list, char *));
	else if (str[ft_strlen(str) - 1] == 'c')
		ft_putchar(va_arg(list, int));
	else if (str[ft_strlen(str) - 1] == 'p')
		ft_putstr(ft_itoa_base(va_arg(list, unsigned long), 16));
	else if (str[ft_strlen(str) - 1] == 'd')
		decimal_nbr(list, flg);
	else if (str[ft_strlen(str) - 1] == 'i')
		decimal_nbr(list, flg);
	else if (str[ft_strlen(str) - 1] == 'o')
		ft_putstr(ft_itoa_base(va_arg(list, long int), 8));
	//else if (str[ft_strlen(str) - 1] == 'u')
		//ft_putstr(ft_lutoa(va_arg(list, unsigned int)));
	else if (str[ft_strlen(str) - 1] == 'x')
		ft_putstr(ft_itoa_base(va_arg(list, long int), 16));
	//else if (str[ft_strlen(str) - 1] == 'X')
		//return ('X');
	else if (str[ft_strlen(str) - 1] == 'f')
		ft_putdouble(va_arg(list, double), flg->decimal);
}
