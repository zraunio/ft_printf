/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 10:37:14 by zraunio           #+#    #+#             */
/*   Updated: 2021/02/19 12:37:32 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	get_precision(const char *str)
{
	size_t	i;
	size_t	flg;

	i = 0;
	flg = 0;
	while (!(ft_isdigit(str[i])) && str[i])
	{
		if (str[i] == '.')
			flg = 1;
		i++;
	}
	if (flg)
		return(ft_atoi(&str[i]));
	else
		return (6);
}

static size_t	get_min_width(const char *str)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = 0;
	while (!(ft_isdigit(str[i])))
	{
		i++;
		if (str[i] == '.' || str[i] == '\0')
			return (0);
	}
	res = ft_abs(ft_atoi(&str[i]));
	return (res);
}

static void		fill_struct(const char *str, t_flags *flgs)
{
	size_t		i;

	i = 0;
	while (str[i] == '-' || str[i] == '+' || str[i] == '#' || str[i] == '0'
	|| str[i] == ' ')
	{
		str[i] == '-' ? flgs->left = 1 : 0;
		str[i] == '+' ? flgs->sign = 1 : 0;
		str[i] == '0' ? flgs->zero = 1 : 0;
		str[i] == ' ' ? flgs->spc = 1 : 0;
		str[i] == '#' ? flgs->hash = 1 : 0;
		i++;
	}
	while (str[i] != '\0')
	{
		str[i] == 'l' ? flgs->l = 1 : 0;
		str[i + 1] == 'l' ? flgs->ll = 1 : 0;
		str[i] == 'h' ? flgs->h = 1 : 0;
		str[i + 1] == 'h' ? flgs->hh = 1 : 0;
		str[i] == 'L' ? flgs->lng_f = 1 : 0;
		i++;
	}
}

static void		reset_flags(t_flags *flgs)
{
	flgs->decimal = 0;
	flgs->h = 0;
	flgs->hash = 0;
	flgs->hh = 0;
	flgs->l = 0;
	flgs->lng_f = 0;
	flgs->left = 0;
	flgs->ll = 0;
	flgs->min_wi = 0;
	flgs->sign = 0;
	flgs->spc = 0;
	flgs->zero = 0;
}

void			parse(char *str, va_list *list)
{
	t_flags		*flgs;

	if (!(flgs = (t_flags*)malloc(sizeof(t_flags))))
		return ;
	flgs->decimal = get_precision(str);
	flgs->min_wi = get_min_width(str);
	fill_struct(str, flgs);
	ft_convert(str, list, flgs);
	reset_flags(flgs);
	free(flgs);
}
