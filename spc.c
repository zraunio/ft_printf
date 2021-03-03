/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 13:24:38 by zraunio           #+#    #+#             */
/*   Updated: 2021/03/02 14:42:14 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t			padd_str(char *str, t_flags *flg, char c)
{
	char	*pad;
	char	*out;
	size_t	len;

	len = 0;
	out = ft_strdup(str);
	if (flg->min_wi > ft_strlen(out))
	{
		pad = ft_strcnew(flg->min_wi - ft_strlen(out), c);
		if (flg->left)
			out = ft_strjoin(out, pad);
		else
			out = ft_strjoin(pad, out);
		ft_memdel((void*)&pad);
	}
	ft_putstr(out);
	len = ft_strlen(out);
	free(flg);
	return (len);
}

static char		*handle_str(char *out, t_flags *flg)
{
	if (out == NULL)
		return (out = ft_strdup("(null)"));
	if (flg->decimal && flg->decimal < ft_strlen(out))
		out = ft_strsub(out, 0, flg->decimal);
	return (out);
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
			return (len + 1);
		}
		else
			ft_putstr(pad);
		ft_memdel((void*)&pad);
	}
	ft_putchar(c);
	free(flg);
	return (len + 1);
}

size_t			convert_spc(char *str, va_list *list, t_flags *flg)
{
	if (str[ft_strlen(str) - 1] == 's')
		return (padd_str(handle_str(va_arg(*list, char *), flg), flg, ' '));
	else if (str[ft_strlen(str) - 1] == 'p')
		return (padd_str(ft_itoa_base(va_arg(*list, unsigned long), 16),
		flg, ' '));
	else
		return (padd_char((va_arg(*list, int)), flg));
}
