/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 10:38:57 by zraunio           #+#    #+#             */
/*   Updated: 2021/02/19 16:34:13 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		output_str(char *out, t_flags *flg, char c)
{
	char	*pad;

	if (flg->min_wi > ft_strlen(out))
	{
		pad = ft_strcnew(flg->min_wi - ft_strlen(out), c);
		if (flg->left)
		{
			ft_putstr(out);
			ft_putstr(pad);
			ft_memdel((void*)&pad);
			return ;
		}
		else
		{
			ft_putstr(pad);
			ft_memdel((void*)&pad);
		}
	}
	ft_putstr(out);
}

void		nbr_check_flags(t_flags *flgs, int nb, char *str)
{
	char	c;

	c = 32;
	flgs->zero == 1 ? c = 48 : 32;
	flgs->left == 1 ? c = 32 : 48;
	if ((flgs->spc || flgs->sign) && nb > 0)
	{
		if (flgs->sign)
			ft_putchar('+');
		else
			ft_putchar(' ');
	}
	output_str(str, flgs, c);
}

static	void	float_nbr(va_list *list, t_flags *flg)
{
	double f;

	f = va_arg(*list, double);
	if (flg->lng_f)
		nbr_check_flags(flg, (int)f, ft_ftoa((long double)f, flg->decimal));
	else if (flg->l)
		nbr_check_flags(flg, (int)f, ft_ftoa(f, flg->decimal));
	else
		nbr_check_flags(flg, (int)f, ft_ftoa(f, flg->decimal));
}

void			ft_convert(char *str, va_list *list, t_flags *flg)
{
	if (str[ft_strlen(str) - 1] == 's')
		output_str(va_arg(*list, char *), flg, ' ');
	else if (str[ft_strlen(str) - 1] == 'c')
		ft_putchar(va_arg(*list, int));
	else if (str[ft_strlen(str) - 1] == 'p')
		output_str(ft_itoa_base(va_arg(*list, unsigned long), 16), flg, ' ');
	else if (str[ft_strlen(str) - 1] == 'f')
		float_nbr(list, flg);
	else if (str[ft_strlen(str) - 1] == 'd' || str[ft_strlen(str) - 1] == 'i' ||
	str[ft_strlen(str) - 1] == 'u')
		convert_diu(str, list, flg);
	else
		convert_oxX(str, list, flg);
}
