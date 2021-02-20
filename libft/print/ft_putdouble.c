/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdouble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 14:17:13 by zraunio           #+#    #+#             */
/*   Updated: 2021/02/18 14:13:14 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putdouble(long double f, int decimal)
{
	long double	d;

	ft_putlong((long)f);
	if (decimal == 0)
		return ;
	if (decimal >= 20)
		decimal = 19;
	f -= (long)f;
	if (f < 0)
		f *= -1;
	ft_putchar('.');
	while (decimal-- > 0)
		f *= 10;
	d = f;
	if ((d = (d * 10) - f) >= 5)
		f += 1;
	ft_putlong((long)f);
}
