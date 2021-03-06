/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 10:38:57 by zraunio           #+#    #+#             */
/*   Updated: 2021/03/06 13:57:19 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*signed_nbr(char *pad, char *str, char c)
{
	char	*out;

	if ((str[0] == '-' || str[0] == '+' || str[0] == ' ') && c == '0')
	{
		pad = ft_strjoin_free(ft_strcnew(1, str[0]), pad, 3);
		out = ft_strjoin_free(pad, &str[1], 1);
		ft_strdel(&str);
	}
	else
		out = ft_strjoin_free(pad, str, 3);
	return (out);
}

size_t			padd_nbr(char *str, t_flags *flg)
{
	char	*pad;
	char	*out;
	char	c;
	size_t	ret;

	c = flg->padd_c;
	if (flg->min_wi > ft_strlen(str))
	{
		pad = ft_strcnew(flg->min_wi - ft_strlen(str), c);
		if (flg->left)
			out = ft_strjoin_free(str, pad, 3);
		else
			out = signed_nbr(pad, str, c);
	}
	else
	{
		if (!(out = (char*)malloc(sizeof(char) * ft_strlen(str) + 1)))
			return (0);
		out = ft_strcpy(out, str);
		free(str);
	}
	ft_putstr(out);
	ret = ft_strlen(out);
	ft_strdel(&out);
	return (ret);
}

static char		*expand_nbr(char *out, t_flags *flgs)
{
	int		len;
	char	*ret;
	char	*temp;

	len = flgs->decimal - ft_strlen(out);
	if (out[0] == '-' && len >= 0)
	{
		len += 1;
		temp = out;
		out = ft_strjoin_free(ft_strcnew(len, '0'), &out[1], 1);
		free(temp);
		ret = ft_strjoin_free("-", out, 2);
	}
	else
		ret = ft_strjoin_free(ft_strcnew(len, '0'), out, 3);
	return (ret);
}

size_t			nbr_check_flags(t_flags *flgs, long long nb, char *str)
{
	int		len;
	char	*ret;

	if (((len = flgs->decimal - ft_strlen(str)) > 0 && nb > 0) ||
	(nb <= 0 && (len = flgs->decimal - ft_strlen(&str[1])) > 0))
	{
		ret = expand_nbr(str, flgs);
		flgs->padd_c = 32;
	}
	else if (flgs->decimal == 0 && ft_strcmp("0", str) == 0)
	{
		ret = ft_strnew(0);
		ft_strdel(&str);
	}
	else
		ret = str;
	if ((flgs->spc || flgs->sign) && nb >= 0 && flgs->cnvrsn != 'u')
	{
		if (flgs->sign)
			ret = ft_strjoin_free("+", ret, 2);
		else
			ret = ft_strjoin_free(" ", ret, 2);
	}
	return (padd_nbr(ret, flgs));
}

size_t			ft_convert(char *str, va_list *list, t_flags *flg)
{
	if (str[ft_strlen(str) - 1] == 's' || str[ft_strlen(str) - 1] == 'p' ||
	str[ft_strlen(str) - 1] == 'c' || str[ft_strlen(str) - 1] == '%')
		return (convert_spc(str, list, flg));
	else if (str[ft_strlen(str) - 1] == 'f')
		return (float_nbr(list, flg));
	else if (str[ft_strlen(str) - 1] == 'd' || str[ft_strlen(str) - 1] == 'i' ||
	str[ft_strlen(str) - 1] == 'u')
		return (convert_diu(str, list, flg));
	else
		return (convert_oxx(str, list, flg));
}
