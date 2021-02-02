/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 10:37:14 by zraunio           #+#    #+#             */
/*   Updated: 2021/02/02 10:54:55 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		get_precision(const char *str)
{
	size_t	i;
	int		res;

	i = 0;
	res = 0;
	while (!(ft_isdigit(str[i])))
	{
		i++;
		if (str[i] == '\0')
			return (0);
	}
	if (str[i - 1] == '.')
		res = ft_atoi(&str[i]);
	return (res);
}

/*static int		get_min_width(char *str)
{
	size_t	i;
	int		res;

	i = 0;
	res = 0;
	while (str[i] < '0' && str[i] > '9' && str[i] != '\0')
	{
		i++;
		if (str[i] == '.')
			return (0);
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res);
}*/

static t_flags	*fill_struct(const char *str)
{
	t_flags		*flgs;
	size_t		i;

	i = 0;
	if (!(flgs = (t_flags*)malloc(sizeof(t_flags))))
		return (NULL);
	flgs->decimal = get_precision(str);
	//flgs->max_wi = get_min_width(str);
	while (str[i] != '\0')
	{
		str[i] == 'l' ? flgs->l = 1: 0;
		/*if (str[i + 1] == 'l')
		{
			flgs->ll = 1;
			flgs->l = 0;
		}*/
		if (str[i] == 'h')
		{
			if (str[i + 1] == 'h')
				flgs->ll = 1;
			else
				flgs->l = 1;
		}
		str[i] == 'L' ? flgs->l_f = 1 : 0;
		str[i] == '-' ? flgs->lft = 1 : 0;
		str[i] == '+' ? flgs->sign = 1 : 0;
		str[i] == '0' ? flgs->zero = 1 : 0;
		str[i] == ' ' ? flgs->spc = 1 : 0;
		str[i] == '#' ? flgs->hash = 1 : 0;
		i++;
	}
	return (flgs);
}

void		parse(char *str, va_list list)
{
	t_flags		*flgs;

	if (!(flgs = fill_struct(str)))
		return ;
	ft_convert(str, list, flgs);
	free(flgs);
}
