/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 10:38:57 by zraunio           #+#    #+#             */
/*   Updated: 2021/03/03 18:17:13 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t		padd_nbr(char *out, t_flags *flg, char c)
{
	char	*pad;
	size_t	ret;

	if (flg->min_wi > ft_strlen(out))
	{
		pad = ft_strcnew(flg->min_wi - ft_strlen(out), c);
		if (flg->left)
			out = ft_strjoin_free(out, pad, 2);
		else
		{
			if ((out[0] == '-' || out[0] == '+') && c == '0')
			{
				pad = ft_strjoin_free(ft_strcnew(1, out[0]), pad, 2);
				out = ft_strjoin_free(pad, &out[1], 3);
			}
			else
				out = ft_strjoin_free(pad, out, 3);
		}
	}
	ft_putstr(out);
	ret = ft_strlen(out);
	ft_strdel(&out);
	free(out);
	return (ret);
}

static char			*expand_nbr(char *out, t_flags *flgs)
{
	int		len;
	char	*ret;

	len = flgs->decimal - ft_strlen(out);
	if (out[0] == '-' && len > 0)
	{
		len += 1;
		out = ft_strjoin_free(ft_strcnew(len, '0'), &out[1], 1);
		ret = ft_strjoin_free("-", out, 2);
	}
	else
		ret = ft_strjoin_free(ft_strcnew(len, '0'), out, 3);
	return (ret);
}

size_t				nbr_check_flags(t_flags *flgs, int nb, char *str)
{
	char	c;
	int		len;
	char	*ret;

	c = 32;
	flgs->zero == 1 ? c = 48 : 32;
	flgs->left == 1 ? c = 32 : 48;
	if ((len = flgs->decimal - ft_strlen(str)) > 0)
	{
		ret = expand_nbr(str, flgs);
		c = 32;
	}
	else if (flgs->decimal == 0 && ft_strcmp("0", str) == 0)
		ret = ft_strnew(0);
	else
	{
		if (!(ret = (char*)malloc(sizeof(char) * ft_strlen(str) - 1)))
			return (0);
		ret = ft_strcpy(ret, str);
		free(str);
	}
	if ((flgs->spc || flgs->sign) && nb >= 0)
	{
		if (flgs->sign)
			ret = ft_strjoin_free("+", ret, 2);
		else
			ret = ft_strjoin_free(" ", ret, 2);
	}
	return (padd_nbr(ret, flgs, c));
}

static	size_t		float_nbr(va_list *list, t_flags *flg)
{
	double	f;

	f = va_arg(*list, double);
	if (flg->lng_f)
		return (nbr_check_flags(flg, (int)f, ft_ftoa((long double)f,
		flg->decimal)));
	else if (flg->l)
		return (nbr_check_flags(flg, (int)f, ft_ftoa(f, flg->decimal)));
	else
		return (nbr_check_flags(flg, (int)f, ft_ftoa(f, flg->decimal)));
}

size_t				ft_convert(char *str, va_list *list, t_flags *flg)
{
	char	*ret;

	if (str[ft_strlen(str) - 1] == 's' || str[ft_strlen(str) - 1] == 'p' ||
	str[ft_strlen(str) - 1] == 'c')
		return (convert_spc(str, list, flg));
	else if (str[ft_strlen(str) - 1] == 'f')
		return (float_nbr(list, flg));
	else if (str[ft_strlen(str) - 1] == 'd' || str[ft_strlen(str) - 1] == 'i' ||
	str[ft_strlen(str) - 1] == 'u')
		return (convert_diu(str, list, flg));
	else if (str[ft_strlen(str) - 1] == '%')
	{
		ret = ft_strcnew(1, '%');
		return (padd_str(ret, flg, ' '));
	}
	else
		return (convert_oxx(str, list, flg));
}
