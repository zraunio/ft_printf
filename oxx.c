/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oxx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:39:01 by zraunio           #+#    #+#             */
/*   Updated: 2021/03/02 14:27:09 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t		octal_nbr(va_list *list, t_flags *flg)
{
	char		c;
	size_t		u;

	u = va_arg(*list, size_t);
	c = 32;
	flg->zero == 1 ? c = 48 : 32;
	flg->left == 1 ? c = 32 : 48;
	if (flg->h)
		return (precision_base(ft_itoa_base((short)u, 8), flg, 'o', c));
	else if (flg->l)
	{
		if (flg->ll)
			return (precision_base(ft_lutoa_base((unsigned long long)u, 8), flg, 'o', c));
		else
			return (precision_base(ft_lutoa_base((unsigned long)u, 8),
			flg, 'o', c));
	}
	else
		return (precision_base(ft_itoa_base((unsigned int)u, 8), flg, 'o', c));
}

static char			*hex_convert(char *out, t_flags *flg, char x)
{
	size_t	i;

	i = 0;
	if (x == 'X')
	{
		while (out[i])
		{
			if (out[i] >= 'a' && out[i] <= 'f')
				out[i] -= 32;
			i++;
		}
		if (flg->hash == 1)
			out = ft_strjoin("0X", out);
		return (out);
	}
	else
	{
		if (flg->hash && (flg->decimal != 0 && ft_strcmp("0", out)))
			out = ft_strjoin("0x", out);
		return (out);
	}
}

static size_t		hex_nbr(va_list *list, t_flags *flg, char ex)
{
	char			c;
	unsigned int	x;

	x = va_arg(*list, long long int);
	c = 32;
	flg->zero == 1 ? c = 48 : 32;
	flg->left == 1 ? c = 32 : 48;
	if (flg->h)
		return (precision_base(ft_itoa_base((unsigned short)x, 16), flg, 'h', c));
	else if (flg->l)
	{
		if (flg->ll)
			return (precision_base(hex_convert(ft_lutoa_base(x, 16), flg, ex),
			flg, 'h', c));
		else
			return (precision_base(hex_convert(ft_lutoa_base((unsigned long int)
			x, 16), flg, ex), flg, 'h', c));
	}
	else
		return (precision_base(hex_convert(ft_itoa_base((unsigned int)x, 16),
		flg, ex), flg, 'h', c));
}

size_t				convert_oxx(char *str, va_list *list, t_flags *flg)
{
	if (str[ft_strlen(str) - 1] == 'o')
		return (octal_nbr(list, flg));
	else if (str[ft_strlen(str) - 1] == 'x')
		return (hex_nbr(list, flg, 'x'));
	else if (str[ft_strlen(str) - 1] == 'X')
		return (hex_nbr(list, flg, 'X'));
	return (0);
}
