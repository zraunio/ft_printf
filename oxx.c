/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oxx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:39:01 by zraunio           #+#    #+#             */
/*   Updated: 2021/03/05 17:43:51 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t		octal_nbr(va_list *list, t_flags *flg)
{
	char		c;
	size_t		u;

	u = va_arg(*list, size_t);
	c = 32;
	c = flg->zero == 1 ? 48 : c;
	c = flg->left == 1 ? 32 : c;
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

static char			*hex_convert(char *out, t_flags *flgs, char x)
{
	size_t	i;
	char	*ret;

	i = 0;
	ret = NULL;
	if (ft_strcmp("0", out) == 0)
		return (out);
	else if (flgs->hash == 1 && x == 'x')
		ret = ft_strjoin_free("0x", out, 2);
	else if (flgs->hash == 1 && x == 'X')
		ret = ft_strjoin_free("0X", out, 2);
	else
		ret = out;
	if (x == 'X')
	{
		while (ret[i])
		{
			if (ret[i] >= 'a' && ret[i] <= 'f')
				ret[i] -= 32;
			i++;
		}
	}
	return (ret);
}

static size_t		hex_nbr(va_list *list, t_flags *flg, char ex)
{
	char					c;
	char					*str;
	unsigned long long int	x;

	x = va_arg(*list, unsigned long long int);
	c = 32;
	c = flg->zero == 1 ? 48 : c;
	c = flg->left == 1 ? 32 : c;
	if (flg->h)
		return (precision_base(ft_itoa_base((unsigned short)x, 16), flg, 'h', c));
	else if (flg->l)
	{
		if (flg->ll)
		{
			str = ft_lutoa_base(x, 16);
			return (precision_base(hex_convert(str, flg, ex), flg, 'h', c));
		}
		else
		{
			str = ft_lutoa_base((unsigned long int)x, 16);
			return (precision_base(hex_convert(str, flg, ex), flg, 'h', c));
		}
	}
	else
		return (precision_base(hex_convert(ft_itoa_base((unsigned int)x, 16), flg, ex), flg, 'h', c));
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
