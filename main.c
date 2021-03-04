#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

/*static size_t	skip_convert(const char *str, size_t i)
{
	size_t	j;
	char	*ref;

	ref = "cspdiouxXf%";
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
	return (ft_strlen(str));
}

static char		**print_split(char *str)
{
	size_t		i;
	size_t		j;
	size_t		len;
	char		**txt;

	i = 0;
	j = 0;
	if (!(txt = (char **)malloc(sizeof(char*) * (ft_wdcounter(str, '%') + 2))))
		return (NULL);
	while (str[i] && j < ft_wdcounter(str, '%'))
	{
		len = i;
		if (str[len] == '%' && str[len])
		{
			len++;
			i = skip_convert(str, len);
		}
		if (str[len] != '%')
		{
			while (str[len] != '%' && str[len])
				len++;
			txt[j] = ft_strsub(str, i, (len - i));
			if ((i = skip_convert(str, len)) >= ft_strlen(str))
				break ;
		}
		j++;
	}
	txt[j + 1] = NULL;
	j = 0;
	while (txt[j])
		ft_putendl(txt[j++]);
	return (txt);
}

static size_t	ft_countwords(char const *s, char c)
{
	size_t	count;
	int		i;

	count = 0;
	i = 0;
	while (*s)
	{
		if (i == 1 && *s == c)
			i = 0;
		if (i == 0 && *s != c)
		{
			i = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static char		*make_word(char const *s, char c, size_t i)
{
	int		len;
	char	*word;

	if (s[i] == c)
		len = i + 1;
	else 
		len = i;
	while (s[len] != c && s[len] != '\0')
		len++;
	if (!(word = ft_strsub(s, i, (len - i))))
		free(word);
	return (word);
}

static char		**split_string(char const *s, size_t count)
{
	size_t		j;
	size_t		i;
	char		**words;

	i = 0;
	j = 0;
	if (!(words = (char **)malloc(sizeof(char*) * (count + 1))))
		return (NULL);
	while (s[i] && j < count)
	{
		if (s[i] == '%' && s[i] != '\0')
			i++;
		if ((s[i] != '%' || s[i + 1] != '%') && s[i] != '\0')
		{
			words[j] = make_word(s, '%', i);
			i = i + ft_strlen(words[j]);
			i++;
		}
		j++;
	}
	words[j] = NULL;
	return (words);
}

char			**ft_strsoft_split(char const *s)
{
	size_t	count;
	char	**words;

	if (!s)
		return (NULL);
	count = ft_countwords(s, '%');
	if (!(words = split_string(s, count)))
		ft_arr_free(words);
	return (words);
}
*/

int		main()
{
	ft_putendl(ft_itoa(22222222));
	ft_putendl(ft_itoa(3));
	ft_putendl(ft_itoa(-22222222));
	ft_putendl(ft_ftoa(193849248.00028384l, 12));
	ft_putendl(ft_ftoa(1948092784.00008284l, 12));
	ft_putendl(ft_ftoa(88742222.1111119l, 12));
	ft_putendl(ft_ftoa(193849248.00028384l, 12));
	ft_putendl(ft_ftoa(1948092784.00008284l, 12));
	ft_putendl(ft_ftoa(88742222.1111119l, 12));
	ft_putendl(ft_ftoa(193849248.00028384l, 12));
	ft_putendl(ft_ftoa(1948092784.00008284l, 12));
	ft_putendl(ft_ftoa(88742222.1111119l, 19));
	return (0);
}
//gcc -Wall -Wextra -Werror main.c libft/libft.a -I libft/ -o test
//gcc -Wall -Wextra -Werror main.c -L./ -lftprintf -I./ -L libft/ -lft  -o test
