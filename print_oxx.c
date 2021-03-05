/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_oxx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 10:11:20 by zraunio           #+#    #+#             */
/*   Updated: 2021/03/05 17:49:53 by zraunio          ###   ########.fr       */
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
			out = ft_strjoin_free(out, pad, 2);
		else
		{
			if (out[0] == '0' && c == '0')
			{
				if (b == 'h' && out[1] == 'x')
				{
					pad = ft_strjoin_free("0x", pad, 2);
					out = ft_strjoin_free(pad, &out[2], 1);
				}
				else
				{
					pad = ft_strjoin_free(ft_strcnew(1, c), pad, 3);
					out = ft_strjoin_free(pad, &out[1], 1);
				}
			}
			else
				out = ft_strjoin_free(pad, out, 1);
		}
	}
	ft_putstr(out);
	ret = ft_strlen(out);
	ft_strdel(&out);
	return (ret);
}

static char	*padd_hash(char *out, size_t len)
{
	char	*ret;
	char	*x;

	x = NULL;
	x = out[1] == 'x' ? ft_strdup("0x") : ft_strdup("0X");
	out = ft_strjoin_free(ft_strcnew(len, '0'), &out[2], 1);
	ret = ft_strjoin_free(x, out, 3);
	return (ret);
}

size_t		precision_base(char *out, t_flags *flgs, char b, char c)
{
	int		len;
	char	*ret;

	ret = NULL;
	if (ft_strcmp("0", out) == 0)
	{
		c = flgs->decimal == 0 ? 32 : c;
		if (flgs->decimal == 0)
		{
			free (out);
			if (flgs->hash && b == 'o')
				return (padd_base(ft_strcnew(1, '0'), flgs, b, c));
			else
				return (padd_base(ft_strcnew(1, '\0'), flgs, b, c));
		}
	}
	if (flgs->hash && out[0] != '0' && b == 'o')
		out = ft_strjoin_free("0", out, 2);
	len = flgs->decimal - ft_strlen(out);
	if (len > 0)
	{
		if ((out[1] == 'x' || out[1] == 'X') && b == 'h' && flgs->hash)
		{
			len += 1;
			ret = padd_hash(out, len);
		}
		else
			ret = ft_strjoin_free(ft_strcnew(len, '0'), out, 1);
	}
	else
		ret = ft_strdup(out);
	ft_strdel(&out);
	return (padd_base(ret, flgs, b, c));
}
