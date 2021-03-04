/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 09:52:43 by zraunio           #+#    #+#             */
/*   Updated: 2021/03/04 14:58:49 by zraunio          ###   ########.fr       */
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
	int			size;
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
	int		z;
	size_t	decimal;
	size_t	min_wi;
}				t_flags;

/*
** vars - variables given in format; preci(sion) in char form
** info_str - the content of "format" if % is present
** arg: list of arguments using stdarg lib
** size - data used for return value for ft_printf
*/

size_t			ft_convert(char *str, va_list *list, t_flags *flg);
size_t			parse(char *str, va_list *list);
size_t			padd_str(char *out, t_flags *flg, char c);
size_t			convert_oxx(char *str, va_list *list, t_flags *flg);
size_t			precision_base(char *out, t_flags *flgs, char b, char c);
size_t			convert_diu(char *str, va_list *list, t_flags *flg);
size_t			convert_spc(char *str, va_list *list, t_flags *flg);
size_t			nbr_check_flags(t_flags *flgs, int nb, char *str);
int				ft_printf(const char *format, ...);

#endif
