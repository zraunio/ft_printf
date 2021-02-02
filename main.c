#include <stdio.h>
#include "libft/libft.h"

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
			txt[j] = ft_strsub(str, i, (len - i));
			i = skip_convert(str, len);
		}
		j++;
	}
	txt[j] = NULL;
	return (txt);
}

int		main()
{
	char	**arr;
	size_t	i = 0;

	arr = print_split("hello %s, you are %hh3d years-old and i will kidnap you in\n %.4Lf\n months at %o hours with %c others\n at %p street");
	while (arr[i])
	{
		ft_putstr(arr[i]);
		i++;
	}
	ft_putlong(9223372036854775806);
	return (0);
}
