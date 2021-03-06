/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 09:52:25 by zraunio           #+#    #+#             */
/*   Updated: 2021/03/06 09:00:27 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *format, ...)
{
	t_print		*print;
	va_list		arg;
	int			i;

	i = 0;
	print = NULL;
	if (!(ft_strchr(format, '%')))
	{
		ft_putstr(format);
		return (ft_strlen(format));
	}
	else if (format)
	{
		if (!(print = (t_print*)malloc(sizeof(t_print))))
			return (0);
		va_start(arg, format);
		print->arg = &arg;
		print->info_str = ft_strdup(format);
		i = ft_print(print);
		va_end(arg);
		return (i);
	}
	return (-1);
}
