/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 12:51:29 by zraunio           #+#    #+#             */
/*   Updated: 2021/02/18 14:13:07 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char		*ft_ftoa(long double d, size_t decimal)
{
	char		*res;
	char		*rest;
	long double	f;

	res = ft_litoa((long)d);
	d -= (long)d;
	if (decimal > 0)
	{
		if (decimal >= 20)
			decimal = 19;
		while (decimal--)
			d *= 10;
		f = d;
		if ((f = (f * 10) - d) >= 5)
			d += 1;
		rest = ft_litoa((long)d);
		rest = ft_strjoin(".", rest);
		return (ft_strjoin(res, rest));
	}
	else
		return (res);
}
