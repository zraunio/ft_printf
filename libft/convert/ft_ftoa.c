/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 12:51:29 by zraunio           #+#    #+#             */
/*   Updated: 2021/03/02 16:22:22 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char		*ft_ftoa(long double d, size_t decimal)
{
	char		*res;
	char		*rest;
	long double	f;

	f = d - (long)d;
	if (decimal == 0 && (f * 10) > 5)
		d += 1;
	res = ft_litoa((long)d);
	if (decimal > 0)
	{
		d -= (long)d;
		res = ft_strjoin(res, ".");
		if (decimal >= 20)
			decimal = 19;
		while (decimal--)
		{
			d *= 10;
			if (decimal && (int)d == 0)
				res = ft_strjoin(res, "0");
		}
		f = d - (long)d;
		if ((f * 10) >= 5)
			d += 1;
		rest = ft_sizetoa((size_t)d);
		return (ft_strjoin(res, rest));
	}
	else
		return (res);
}
