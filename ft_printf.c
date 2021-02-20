/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 09:52:25 by zraunio           #+#    #+#             */
/*   Updated: 2021/02/19 12:41:47 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

/*static void		grep_convert(t_print *print)
{
	size_t	i;
	size_t	j;
	char	*temp;
	char	*str;

	i = 0;
	while (print->info_str[i] != '%')
		i++;
	ft_putstr(ft_strsub(print->info_str, 0, i));
	temp = ft_strsub(print->info_str, i, ft_strlen(print->info_str));
	print->vars = ft_strsplit(temp, '%');
	i = 0;
	while (print->vars[i])
	{
		j = ft_strstr_start(print->vars[i], "cspdiouxXf");
		str = ft_strsub(print->vars[i], j + 1, ft_strlen(print->vars[i]));
		print->vars[i] = ft_strsub(print->vars[i], 0, j + 1);
		parse(print->vars[i], print->arg);
		ft_putstr(str);
		i++;
		ft_memdel((void*)&str);
	}
	free(temp);
}*/

static void			reset_printf(t_print *print)
{
	ft_arr_free(print->vars);
	ft_memdel((void*)&print->info_str);
	print->size = 0;
}

static void			ft_print(t_print *print)
{
	size_t	i;
	size_t	j;
	char	*temp;
	char	*str;

	i = 0;
	while (print->info_str[i] != '%')
		i++;
	ft_putstr(ft_strsub(print->info_str, 0, i));
	temp = ft_strsub(print->info_str, i, ft_strlen(print->info_str));
	print->vars = ft_strsplit(temp, '%');
	i = 0;
	while (print->vars[i])
	{
		j = ft_strstr_start(print->vars[i], "cspdiouxXf");
		str = ft_strsub(print->vars[i], j + 1, ft_strlen(print->vars[i]));
		print->vars[i] = ft_strsub(print->vars[i], 0, j + 1);
		parse(print->vars[i], print->arg);
		ft_putstr(str);
		i++;
		ft_memdel((void*)&str);
	}
	reset_printf(print);
	free(temp);
}

int				ft_printf(const char *format, ...)
{
	t_print		*print;
	va_list		arg;
	size_t		i;

	i = 0;
	if (!(print = (t_print *)ft_memalloc(sizeof(t_print))))
		return (0);
	if (!(ft_strchr(format, '%')))
	{
		ft_putstr(format);
		return (ft_strlen(format));
	}
	else if (format)
	{
		va_start(arg, format);
		print->arg = &arg;
		print->info_str = ft_strdup(format);
		ft_print(print);
		va_end(arg);
		free(print);
		return (print->size);
	}
	reset_printf(print);
	free(print);
	return (-1);
}
	//if printf == 1, write NO FORMAT GIVEN, 
	//ft_printf needs at least one argument
	//usage: 
