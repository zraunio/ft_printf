/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 12:44:50 by zraunio           #+#    #+#             */
/*   Updated: 2021/01/20 12:47:44 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t		ft_strstr_len(const char *haystack, const char *needle)
{
	size_t	j;
	size_t	k;

	j = 0;
	if (needle[j] == '\0')
		return (0);
	while (haystack[j] != '\0')
	{
		k = 0;
		while (needle[k] == haystack[j + k])
		{
			k++;
			if (needle[k] == '\0')
				return (j);
		}
		j++;
	}
	return (0);
}
