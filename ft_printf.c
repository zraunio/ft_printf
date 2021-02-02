/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 09:52:25 by zraunio           #+#    #+#             */
/*   Updated: 2021/02/02 11:33:22 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

#include <stdio.h> //!!! fucking delete this you crazy shit

static size_t	skip_convert(const char *str, size_t i)
{
	size_t	j;
	char	*ref;

	ref = "cspdiouxXf";
	j = 0;
	while (str[i])
	{
		j = 0;
		while (ref[j])
		{
			if (str[i] == ref[j])
				return (i + 1);
			else
				j++;
		}
		i++;
	}
	return (i);
}

static char		**print_split(const char *str)
{
	size_t		count;
	size_t		i;
	size_t		j;
	size_t		len;
	char		**txt;

	count = ft_wdcounter(str, '%');
	i = 0;
	j = 0;
	if (!(txt = (char **)malloc(sizeof(char*) * (count + 2))))
		return (NULL);
	while (str[i] && j < count)
	{
		len = i;
		while (str[len] != '%' && str[len])
			len++;
		if (str[len] == '%')
		{
			ft_putchar('.');
			txt[j] = ft_strsub(str, i, (len - i));
			i = skip_convert(str, len);
		}
		j++;
	}
	txt[j + 1] = NULL;
	//CURRENTLY DOESN'T PRINT LAST WORDS AFTER LAST % CONVERSION
	//it seems the functiuon is currently designed to do nothing
	//unless it encounters an %
	//which ultimateluy "forgets" about the last text string
	return (txt);
}

static void		grep_convert(t_print *print)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*temp;
	char	*ref;

	ref = "cspdiouxXf";
	i = 0;
	temp = ft_strtrim_top(print->info_str, '%');
	print->vars = ft_strsplit(temp, '%');
	while (print->vars[i])
	{
		j = 0;
		while (print->vars[i][j])
		{
			k = 0;
			while (ref[k])
			{
				if (print->vars[i][j] == ref[k])
				{
					print->vars[i] = ft_strsub(print->vars[i], 0, j + 1);
					break ;
				}
				else
					k++;
			}
			j++;
		}
		i++;
	}
}

void			ft_print(t_print *print)
{
	char		**arr;
	size_t		i;

	i = 0;
	grep_convert(print);
	if (!(arr = print_split(print->info_str)))
		ft_arr_free(arr);
	while (arr[i])
	{
		ft_putstr(arr[i]);
		//if ft_strlen(itoa(number to write)) < precision
		// while ft_strlen < precision, strlen++, write (what you need 2 write)
		if (print->vars[i])
			parse(print->vars[i], print->arg);
		i++;
	}
}

int				ft_printf(const char *format, ...)
{
	t_print		*print;
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
		va_start(print->arg, format);
		print->info_str = ft_strdup(format);
		ft_print(print);
		va_end(print->arg);
		return (print->size);
	}
	ft_arr_free(print->vars);
	free(print); ///free before you return ???
	return (print->size);
}

int				main()
{
	char *p;

	p = ft_strnew(2);
	//ft_printf("    hello %s, you are %3d years-old and i will kidnap you in\n %.4Lf\n months at %x hours with %c%c%c others\n at %p hey there",
	//"stranger", 34, 4.82749382382, 1600, '\0', '\t', ' ', p);
	//ft_putchar('\n');
	ft_printf("blablbla %li hahaha", 9223372036854775806);
	printf("\n----------\n");
	ft_putlong(9223372036854775806);
	//printf("\n----------\n");
	//printf("blablbla %+li hahaha", 9223372036854775806);
	return (0);
}
//gcc -Wall -Wextra -Werror main.c libft/libft.a -I libft/ -o test
