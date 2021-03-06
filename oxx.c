/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oxx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:39:01 by zraunio           #+#    #+#             */
/*   Updated: 2021/03/06 17:44:43 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t		octal_nbr(va_list *list, t_flags *flg)
{
	size_t		u;

	u = va_arg(*list, size_t);
	if (flg->h)
		return (precision_base(ft_itoa_base((short)u, 8), flg));
	else if (flg->l)
	{
		if (flg->ll)
			return (precision_base(ft_lutoa_base((unsigned long long)u, 8),
			flg));
		else
			return (precision_base(ft_lutoa_base((unsigned long)u, 8),
			flg));
	}
	else
		return (precision_base(ft_itoa_base((unsigned int)u, 8), flg));
}

static char			*hex_convert(char *out, char x)
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
	}
	return (out);
}

static size_t		hex_nbr(va_list *list, t_flags *flg, char ex)
{
	char					*str;
	unsigned long long int	x;

	x = va_arg(*list, unsigned long long int);
	if (flg->h)
		return (precision_base(ft_itoa_base((unsigned short)x, 16), flg));
	else if (flg->l)
	{
		if (flg->ll)
		{
			str = ft_lutoa_base(x, 16);
			return (precision_base(hex_convert(str, ex), flg));
		}
		else
		{
			str = ft_lutoa_base((unsigned long int)x, 16);
			return (precision_base(hex_convert(str, ex), flg));
		}
	}
	else
		return (precision_base(hex_convert(ft_itoa_base((unsigned int)x, 16),
		ex), flg));
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
