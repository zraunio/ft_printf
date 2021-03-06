/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 10:37:14 by zraunio           #+#    #+#             */
/*   Updated: 2021/03/06 14:07:44 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		get_precision(const char *str)
{
	size_t	i;

	i = 1;
	while (str[i] != '.' && str[i])
		i++;
	if (str[i] == '.')
	{
		if (ft_isdigit(str[i + 1]))
			return (ft_atoi(&str[i + 1]));
		else
			return (0);
	}
	else if (str[ft_strlen(str) - 1] == 'f')
		return (6);
	else
		return (-1);
}

static size_t	get_min_width(const char *str)
{
	size_t	i;
	size_t	res;

	i = 1;
	res = 0;
	while (str[i] == '-' || str[i] == '+' || str[i] == '#' || str[i] == '0'
	|| str[i] == ' ')
		i++;
	while (!(ft_isdigit(str[i])))
	{
		if (str[i] == '.' || str[i] == '\0')
			return (0);
		i++;
	}
	res = ft_abs(ft_atoi(&str[i]));
	return (res);
}

static void		fill_struct(const char *str, t_flags *flgs)
{
	size_t		i;

	i = 1;
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
		str[i] == 'z' ? flgs->z = 1 : 0;
		i++;
	}
	flgs->cnvrsn = str[ft_strlen(str) - 1];
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
	flgs->z = 0;
	flgs->min_wi = 0;
	flgs->sign = 0;
	flgs->spc = 0;
	flgs->zero = 0;
	flgs->padd_c = 0;
	flgs->cnvrsn = 0;
}

size_t			parse(char *str, va_list *list)
{
	t_flags		*flgs;
	size_t		ret;

	if (!(flgs = (t_flags*)malloc(sizeof(t_flags))))
		return (0);
	reset_flags(flgs);
	fill_struct(str, flgs);
	flgs->decimal = get_precision(str);
	flgs->min_wi = get_min_width(str);
	flgs->padd_c = 32;
	flgs->padd_c = flgs->zero == 1 ? 48 : flgs->padd_c;
	flgs->padd_c = flgs->left == 1 ? 32 : flgs->padd_c;
	if (flgs->zero == 1 && flgs->decimal != (size_t)-1 &&
	(flgs->cnvrsn == 'u' || flgs->cnvrsn == 'i' || flgs->cnvrsn == 'd'))
		flgs->padd_c = 32;
	ret = ft_convert(str, list, flgs);
	free(flgs);
	return (ret);
}
