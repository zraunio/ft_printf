/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 09:52:25 by zraunio           #+#    #+#             */
/*   Updated: 2021/03/02 21:15:44 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void 	fill_vars(t_print *print, char *temp)
{
    size_t	i;
    size_t	j;
    size_t	start;
	size_t	count;

    i = 0;
    j = 0;
	count = ft_wdcounter(temp, '%');
    while (j < count && temp[i] != '\0')
    {
        start = i;
        while (temp[i] != '\0' && temp[i] != '%')
            i++;
        if (start != i)
            print->vars[j++] = ft_strsub(temp, start, (i - start));
        if (temp[i] == '%')
        {
            start = i++;
            while (temp[i] != '\0' && ft_strchr("cspdiouxXf%", temp[i]) == NULL)
                i++;
            if (ft_strchr("cspdiouxXf%", temp[i]))
                i++;
            print->vars[j++] = ft_strsub(temp, start, (i - start));
        }
    }
    print->vars[j] = NULL;
}

static size_t	reset_printf(t_print *print)
{
	size_t	i;

	i = print->size;
	ft_arr_free(print->vars);
	ft_memdel((void*)&print->info_str);
	print->size = 0;
	return (i);
}

static size_t	ft_print(t_print *print)
{
	size_t	i;
	char	*temp;

	temp = ft_strdup(print->info_str);
	i = ft_wdcounter(temp, '%');
	if (!(print->vars = (char**)malloc(sizeof(char*) * (i + 1))))
		return (0);
	fill_vars(print, temp);
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
		//ft_putendl(print->vars[i]);
		i++;
	}
	free(temp);
	return (reset_printf(print));
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
		print->size = ft_print(print);
		va_end(arg);
		return (print->size);
	}
	reset_printf(print);
	free(print);
	return (-1);
}
//42 checker: l and ll with x/X
//. with x/X working wrong?
