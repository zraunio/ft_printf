/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oxX.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:39:01 by zraunio           #+#    #+#             */
/*   Updated: 2021/02/19 12:49:13 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		octal_nbr(va_list *list, t_flags *flg)
{
	char			c;
	unsigned int	u;

	u = va_arg(*list, unsigned int);
	c = 32;
	flg->zero == 1 ? c = 48 : 32;
	if (flg->h)
		output_str(ft_itoa_base((short)u, 8), flg, c);
	else if (flg->l)
		output_str(ft_itoa_base((unsigned long)u, 8), flg, c);
	else
		output_str(ft_itoa_base(u, 8), flg, c);
}

static char		*hex_convert(char *hex, t_flags *flg, char x)
{
	size_t	i;

	i = 0;
	if (x == 'X')
	{
		while (hex[i++])
		{
			if (ft_isalpha(hex[i]) && hex[i] != '\0')
				hex[i] -= 32;
		}
		if (flg->hash == 1)
			ft_putstr("0X");	
		return (hex);
	}
	else
	{
		if (flg->hash)
			ft_putstr("0x");
		return (hex);
	}

}

static void		hex_nbr(va_list *list, t_flags *flg, char ex)
{
	char			c;
	unsigned int	x;

	x = va_arg(*list, unsigned int);
	c = 32;
	flg->zero == 1 ? c = 48 : 32;
	if (flg->h)
		output_str(ft_itoa_base((short)x, 16), flg, c);
	else if (flg->l)
		output_str(hex_convert(ft_itoa_base((unsigned long)x, 16), flg, ex), flg, c);
	else
		output_str(hex_convert(ft_itoa_base(x, 16), flg, ex), flg, c);
}

void		convert_oxX(char *str, va_list *list, t_flags *flg)
{
	if (str[ft_strlen(str) - 1] == 'o')
		octal_nbr(list, flg);
	else if (str[ft_strlen(str) - 1] == 'x')
		hex_nbr(list, flg, 'x');
	else if (str[ft_strlen(str) - 1] == 'X')
		hex_nbr(list, flg, 'X');
}
