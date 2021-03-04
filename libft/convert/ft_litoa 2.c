/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 12:55:46 by zraunio           #+#    #+#             */
/*   Updated: 2021/03/03 13:16:19 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char		*ft_litoa(long long int n)
{
	int		num;
	char	*s;

	num = ft_count_digit(n);
	if (!(s = (char*)malloc(sizeof(char) * num + 1)))
		return (NULL);
	if (n < 0)
	{
		s[0] = '-';
		if (n == -9223372036854775807 - 1)
			n = -9223372036854775807;
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
