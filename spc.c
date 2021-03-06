/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 13:24:38 by zraunio           #+#    #+#             */
/*   Updated: 2021/03/06 12:36:44 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t			padd_str(char *str, t_flags *flg)
{
	char	*pad;
	char	*out;
	char	c;
	size_t	len;

	len = 0;
	c = flg->padd_c;
	out = ft_strdup(str);
	if (flg->min_wi > ft_strlen(out))
	{
		pad = ft_strcnew(flg->min_wi - ft_strlen(out), c);
		if (flg->left)
			out = ft_strjoin_free(out, pad, 3);
		else
			out = ft_strjoin_free(pad, out, 3);
	}
	ft_putstr(out);
	len = ft_strlen(out);
	free(out);
	free(str);
	return (len);
}

static char		*handle_str(char *out, t_flags *flg)
{
	char	*ret;

	ret = NULL;
	if (out == NULL)
		ret = ft_strdup("(null)");
	if (flg->decimal != (size_t)-1 && flg->decimal < ft_strlen(out))
		ret = ft_strsub(out, 0, flg->decimal);
	else if (!ret)
		ret = ft_strdup(out);
	return (ret);
}

static size_t	padd_char(int c, t_flags *flg)
{
	char	*pad;
	size_t	len;

	len = 0;
	if (flg->min_wi > 1)
	{
		pad = ft_strcnew(flg->min_wi - 1, ' ');
		len = ft_strlen(pad);
		if (flg->left)
		{
			ft_putchar(c);
			ft_putstr(pad);
			ft_strdel(&pad);
			return (len + 1);
		}
		else
			ft_putstr(pad);
		ft_strdel(&pad);
	}
	ft_putchar(c);
	return (len + 1);
}

static size_t	prepend_ptr(char *str, t_flags *flg)
{
	char *out;	

	out = ft_strjoin_free("0x", str, 2);
	return (padd_str(out, flg));
}

size_t			convert_spc(char *str, va_list *list, t_flags *flg)
{
	char	*ret;

	flg->padd_c = 32;
	if (str[ft_strlen(str) - 1] == 's')
	{
		ret = handle_str(va_arg(*list, char *), flg);
		return (padd_str(ret, flg));
	}
	else if (str[ft_strlen(str) - 1] == 'p')
		return (prepend_ptr(ft_itoa_base(va_arg(*list, unsigned long), 16),
		flg));
	else if (str[ft_strlen(str) - 1] == '%')
	{
		ret = ft_strcnew(1, '%');
		flg->padd_c = flg->zero == 1 ? 48 : 32;
		return (padd_str(ret, flg));
	}
	else
		return (padd_char((va_arg(*list, int)), flg));
}
