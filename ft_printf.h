/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 09:52:43 by zraunio           #+#    #+#             */
/*   Updated: 2021/02/01 12:52:24 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct	s_print
{
	char		**vars;
	char		*info_str;
	va_list		arg;
	int			size;

}				t_print;

typedef struct	s_flags
{
	int		h;
	int		hh;
	int		l;
	int		ll;
	int		l_f;
	int		lft;
	int		zero;
	int		sign;
	int		spc;
	int		hash;
	int		decimal;
	int		max_wi;
}				t_flags;

/*
** vars - variables given in format; preci(sion) in char form
** info_str - the content of "format" if % is present
** arg: list of arguments using stdarg lib
** size - data used for return value for ft_printf
*/

void			ft_convert(char *str, va_list list, t_flags *flg);
void			parse(char *str, va_list list);
void			ft_print(t_print *print);
int				ft_printf(const char *format, ...);

#endif

