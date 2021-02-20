/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:45:46 by zraunio           #+#    #+#             */
/*   Updated: 2021/02/20 11:44:24 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		integer_long(va_list *list, t_flags *flg)
{
	long long int	d;
	long int		i;

	if (flg->ll)
		{
			d = va_arg(*list, long long int);
			nbr_check_flags(flg, (int)d, ft_litoa(d));
		}
	else
		{
			i = va_arg(*list, long int);
			nbr_check_flags(flg, (int)i, ft_litoa(i));
		}
}

static void		decimal_nbr(va_list *list, t_flags *flg)
{
	int				nb;
	short			s;

	if (flg->h)
	{
		s = (short)va_arg(*list, int);
		nbr_check_flags(flg, (int)s, ft_itoa(s));
	}
	else if (flg->hh)
		ft_putchar((signed char)va_arg(*list, int)); //seg faults
	else if (flg->l)
		integer_long(list, flg);
	else
	{
		nb = va_arg(*list, int);
		nbr_check_flags(flg, nb, ft_itoa(nb));
	}
}

static void		unsigned_long(va_list *list, t_flags *flg)
{
	unsigned long long	d;
	unsigned long		i;

	if (flg->ll)
		{
			d = va_arg(*list, unsigned long long);
			nbr_check_flags(flg, (int)d, ft_lutoa(d));
		}
	else
		{
			i = va_arg(*list, unsigned long int);
			nbr_check_flags(flg, (int)i, ft_lutoa(i));
		}
}

static void		unsigned_nbr(va_list *list, t_flags *flg)
{
	unsigned int	nb;
	unsigned short	s;

	if (flg->h)
	{
		s = (unsigned short)va_arg(*list, unsigned int);
		nbr_check_flags(flg, (int)s, ft_utoa(s));
	}
	else if (flg->hh)
		ft_putchar((unsigned char)va_arg(*list, unsigned int)); //doesn't convert correctly
	else if (flg->l)
		unsigned_long(list, flg);
	else
	{
		nb = va_arg(*list, unsigned int);
		nbr_check_flags(flg, nb, ft_utoa(nb));
	}
}

void		convert_diu(char *str, va_list *list, t_flags *flg)
{
	if (str[ft_strlen(str) - 1] == 'd')
		decimal_nbr(list, flg);
	else if (str[ft_strlen(str) - 1] == 'i')
		decimal_nbr(list, flg);
	else if (str[ft_strlen(str) - 1] == 'u')
		unsigned_nbr(list, flg);
}
