/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_oxx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 10:11:20 by zraunio           #+#    #+#             */
/*   Updated: 2021/03/06 17:47:31 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*skip_zeroex(t_flags *flg, char *pad, char *out)
{
	char	*temp;
	char	c;

	c = flg->padd_c;
	if ((flg->cnvrsn == 'x' || flg->cnvrsn == 'X')
	&& out[1] == 'x')
	{
		pad = ft_strjoin_free("0x", pad, 2);
		temp = ft_strjoin_free(pad, &out[2], 1);
	}
	else
	{
		pad = ft_strjoin_free(ft_strcnew(1, c), pad, 3);
		temp = ft_strjoin_free(pad, &out[1], 1);
	}
	ft_strdel(&out);
	return (temp);
}

static size_t		padd_base(char *out, t_flags *flg)
{
	char	*pad;
	char	c;
	size_t	ret;

	c = flg->padd_c;
	if (flg->min_wi > ft_strlen(out))
	{
		pad = ft_strcnew(flg->min_wi - ft_strlen(out), c);
		if (flg->left)
			out = ft_strjoin_free(out, pad, 3);
		else
		{
			if (out[0] == '0' && c == '0')
				out = skip_zeroex(flg, pad, out);
			else
				out = ft_strjoin_free(pad, out, 3);
		}
	}
	ft_putstr(out);
	ret = ft_strlen(out);
	ft_strdel(&out);
	return (ret);
}

static size_t		base_zero(t_flags *flgs, char *out)
{
	int		len;

	len = flgs->decimal - ft_strlen(out);
	if (flgs->decimal == 0)
	{
		flgs->padd_c = flgs->decimal == 0 ? 32 : flgs->padd_c;
		ft_strdel(&out);
		if (flgs->hash && flgs->cnvrsn == 'o')
			return (padd_base(ft_strcnew(1, '0'), flgs));
		else
			return (padd_base(ft_strcnew(1, '\0'), flgs));
	}
	else if (len > 0)
		out = ft_strjoin_free(ft_strcnew(len, '0'), out, 3);
	return (padd_base(out, flgs));
}

size_t				precision_base(char *out, t_flags *flgs)
{
	int		len;
	char	*ret;

	ret = NULL;
	if (ft_strcmp("0", out) == 0)
		return (base_zero(flgs, out));
	if (flgs->hash && out[0] != '0' && flgs->cnvrsn == 'o')
		out = ft_strjoin_free("0", out, 2);
	len = flgs->decimal - ft_strlen(out);
	if (len > 0)
		ret = ft_strjoin_free(ft_strcnew(len, '0'), out, 1);
	else
		ret = ft_strdup(out);
	ft_strdel(&out);
	if (flgs->hash == 1 && flgs->cnvrsn == 'x')
		ret = ft_strjoin_free("0x", ret, 2);
	else if (flgs->hash == 1 && flgs->cnvrsn == 'X')
		ret = ft_strjoin_free("0X", ret, 2);
	return (padd_base(ret, flgs));
}
