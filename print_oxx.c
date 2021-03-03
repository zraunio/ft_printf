/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_oxx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 10:11:20 by zraunio           #+#    #+#             */
/*   Updated: 2021/03/01 14:17:19 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static size_t		padd_base(char *out, t_flags *flg, char b, char c)
{
	char	*pad;
	size_t	ret;

	if (flg->min_wi > ft_strlen(out))
	{
		pad = ft_strcnew(flg->min_wi - ft_strlen(out), c);
		if (flg->left)
			out = ft_strjoin(out, pad);
		else
		{
			if (out[0] == '0' && c == '0')
			{
				if (b == 'h')
				{
					pad = ft_strjoin("0x", pad);
					out = ft_strjoin(pad, &out[2]);
				}
				else
				{
					pad = ft_strjoin(ft_strcnew(1, c), pad);
					out = ft_strjoin(pad, &out[1]);
				}
			}
			else
				out = ft_strjoin(pad, out);
		}
		ft_memdel((void*)&pad);
	}
	ft_putstr(out);
	if ((ret = ft_strlen(out)) > 1)
		ft_memdel((void*)&out);
	free(flg);
	return (ret);
}

size_t		precision_base(char *out, t_flags *flgs, char b, char c)
{
	int		len;
	char	*x;

	len = flgs->decimal - ft_strlen(out);
	if (flgs->decimal == 0 && ft_strcmp("0", out) == 0)
	{
		ft_memdel((void*)&out);
		if (flgs->hash && b == 'o')
			return (padd_base("0", flgs, b, c));
		else
			return (padd_base("", flgs, b, c));
	}
	if (flgs->hash && b == 'o')
		out = ft_strjoin("0", out);
	else if (len > 0)
	{
		if (out[0] == '0' && b == 'h' && flgs->hash)
		{
			len += 1;
			out[1] == 'x' ? x = ft_strdup("0x") : ft_strdup("0X");
			out = ft_strjoin(ft_strcnew(len, '0'), &out[2]);
			out = ft_strjoin(x, out);
		}
		else
			out = ft_strjoin(ft_strcnew(len, '0'), out);
	}
	return (padd_base(out, flgs, b, c));
}
