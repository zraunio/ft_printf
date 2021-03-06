/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 09:02:10 by zraunio           #+#    #+#             */
/*   Updated: 2021/03/06 10:00:51 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*float_prepend(char *str, t_flags *flg)
{
	int		len;
	char	*ret;
	char	*temp;

	len = flg->decimal - ft_strlen(str);
	if (len > 0)
	{
		if (str[0] == '-')
		{
			len += 1;
			temp = str;
			str = ft_strjoin_free(ft_strcnew(len, '0'), &str[1], 1);
			free(temp);
			str = ft_strjoin_free("-", str, 2);
		}
		else
			str = ft_strjoin_free(ft_strcnew(len, '0'), str, 3);
	}
	if (flg->decimal == 0 && flg->hash)
		ret = ft_strjoin_free(str, ".", 1);
	else
		ret = str;
	return (ret);
}

static size_t	float_check_flags(t_flags *flgs, long long nb, char *str)
{
	char	*ret;

	if ((flgs->spc || flgs->sign) && nb >= 0)
	{
		if (flgs->sign)
			ret = ft_strjoin_free("+", str, 2);
		else
			ret = ft_strjoin_free(" ", str, 2);
	}
	else
		ret = str;
	return (padd_nbr(ret, flgs));
}

size_t		float_nbr(va_list *list, t_flags *flg)
{
	double		f;
	long double	d;
	char		*str;

	if (flg->lng_f)
	{
		d = va_arg(*list, long double);
		str = float_prepend(ft_ftoa(d, flg->decimal), flg);
		return (float_check_flags(flg, (long long)d, str));
	}
	else
	{
		f = va_arg(*list, double);
		str = float_prepend(ft_ftoa(f, flg->decimal), flg);
		return (float_check_flags(flg, (long long)f, str));
	}
}
