/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 09:52:25 by zraunio           #+#    #+#             */
/*   Updated: 2021/03/05 11:30:47 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	reset_printf(t_print *print, int n)
{
	size_t	i;

	if (n != -1)
	{
		i = print->size;
		ft_arr_free(print->vars);
		ft_memdel((void*)&print->info_str);
		print->size = 0;
		free(print);
	}
	else 
		i = n;
	return (i);
}

static size_t	count_split(const char *str)
{
	size_t	words;
	size_t	i;

	words = 1;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == '%' && str[i] != '\0')
			i++;
		if (str[i])
			words++;
		while (str[i] != '%' && str[i] != '\0')
			i++;
		if (str[i])
			words++;
	}
	return (words);
}

static void 	fill_vars(t_print *print)
{
	size_t	i;
	size_t	j;
	size_t	start;
	size_t	count;

	i = 0;
	j = 0;
	count = count_split(print->info_str);
	while (j <= count && print->info_str[i])
	{
		start = i;
		while (print->info_str[i] != '\0' && print->info_str[i] != '%')
			i++;
		if (start != i)
		{
			if (!(print->vars[j++] = ft_strsub(print->info_str, start, (i - start))))
				return ((void)reset_printf(print, -1));
		}
		if (print->info_str[i] == '%')
		{
			start = i++;
			while (print->info_str[i] != '\0' && ft_strchr("cspdiouxXf%", print->info_str[i]) == NULL)
				i++;
			if (ft_strchr("cspdiouxXf%", print->info_str[i]))
				i++;
			if (!(print->vars[j++] = ft_strsub(print->info_str, start, (i - start))))
				return ((void)reset_printf(print, -1));
		}
	}
	print->vars[j] = NULL;
}

static size_t	ft_print(t_print *print)
{
	size_t	i;

	i = count_split(print->info_str);
	if (!(print->vars = (char**)malloc(sizeof(char*) * (i + 1))))
		return (0);
	fill_vars(print);
	i = 0;
	while (print->vars[i])
	{
		if (print->vars[i][0] == '%')
			print->size += parse(print->vars[i], print->arg);
		else
		{
			ft_putstr(print->vars[i]);
			print->size += ft_strlen(print->vars[i]);
		}
		i++;
	}
	return (reset_printf(print, 1));
}

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
	return (reset_printf(print, -1));
}
//42 checker: l and ll with x/X
//. with x/X working wrong?
