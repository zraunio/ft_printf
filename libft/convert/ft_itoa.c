/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 10:46:20 by zraunio           #+#    #+#             */
/*   Updated: 2021/02/11 14:35:08 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char		*ft_itoa(int n)
{
	int		num;
	char	*s;

	num = ft_count_digit(n);
	if (!(s = (char*)malloc(sizeof(char) * num + 2)))
		return (NULL);
	if (n < 0)
	{
		s[0] = '-';
		if (n == -2147483648)
			n = -2147483647;
		n *= -1;
	}
	s[num--] = '\0';
	while (num >= 0 && s[num] != '-')
	{
		s[num--] = (char)(n % 10 + '0');
		n /= 10;
	}
	return (s);
}
