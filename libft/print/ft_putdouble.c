/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdouble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 14:17:13 by zraunio           #+#    #+#             */
/*   Updated: 2021/01/20 14:39:30 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putdouble(long double f, int decimal)
{
	ft_putlong((long)f);
	if (decimal == 0)
		return ;
	f -= (long)f;
	if (f < 0)
		f *= -1;
	ft_putchar('.');
	while (decimal-- >= 0)
		f *= 10;
	f /= 10;
	ft_putlong((long)f);
}
