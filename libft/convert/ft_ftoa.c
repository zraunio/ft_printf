/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 12:51:29 by zraunio           #+#    #+#             */
/*   Updated: 2021/03/05 19:28:33 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char		*ft_ftoa(long double d, size_t decimal)
{
	char		*res;
	char		*rest;
	long double	f;

	f = d - (long long)d;
	if (decimal == 0 && (f * 10) > 5)
		d += 1;
	res = ft_litoa((long long)d);
	if (decimal > 0)
	{
		d -= (long long)d;
		res = ft_strjoin_free(res, ".", 1);
		if (decimal >= 20)
			decimal = 19;
		while (decimal--)
		{
			d *= 10;
			if (decimal && (int)d == 0)
				res = ft_strjoin_free(res, "0", 1);
		}
		f = d - (long long)d;
		if ((f * 10) >= 5)
			d += 1;
		d = d > 0 ? d : -d;
		rest = ft_litoa((long long)d);
		res = ft_strjoin_free(res, rest, 3);
	}
	return (res);
}
