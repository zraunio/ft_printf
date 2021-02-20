/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 09:52:43 by zraunio           #+#    #+#             */
/*   Updated: 2021/02/19 12:53:48 by zraunio          ###   ########.fr       */
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
	va_list		*arg;
	size_t		size;
}				t_print;

typedef struct	s_flags
{
	int		h;
	int		hh;
	int		l;
	int		ll;
	int		lng_f;
	int		left;
	int		zero;
	int		sign;
	int		spc;
	int		hash;
	size_t	decimal;
	size_t	min_wi;
}				t_flags;

/*
** vars - variables given in format; preci(sion) in char form
** info_str - the content of "format" if % is present
** arg: list of arguments using stdarg lib
** size - data used for return value for ft_printf
*/

void			ft_convert(char *str, va_list *list, t_flags *flg);
void			parse(char *str, va_list *list);
void			output_str(char *out, t_flags *flg, char c);
void			convert_oxX(char *str, va_list *list, t_flags *flg);
void			convert_diu(char *str, va_list *list, t_flags *flg);
void			nbr_check_flags(t_flags *flgs, int nb, char *str);
int				ft_printf(const char *format, ...);

#endif

