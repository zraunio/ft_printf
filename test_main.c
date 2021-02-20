#include "ft_printf.h"
#include <stdio.h>
//REMOVE THIS FROM MAKEFILE 

/*void			overwhelm_it(void)
{
	char *p;

	p = ft_strnew(3);
	ft_printf("    hello %s, you are %3d years-old and i will kidnap you in\n %.4Lf\n months at %x hours with %c%c%c others\n at %p\n",
	"stranger", 34, 4.82749382382, 1600, '\0', '\t', ' ', p);
	ft_printf("blablbla %-20s hahaha", "32769");
	ft_printf("\n----------\n");
	printf("blablbla %-20s %d hahaha\n", "32769", 75);
	ft_printf("blablbla %-20s hahaha\n", "32769");
	ft_printf("blablbla %-20s hahaha\n", "32769");
	ft_printf("blablbla %-20s hahaha\n", "32769");
	ft_printf("blablbla %-20s hahaha\n", "32769");
	ft_printf("blablbla %-20s hahaha\n", "32769");
	ft_printf("    hello %s, you are %3d years-old and i will kidnap you in\n %.4Lf\n months at %x hours with %c%c%c others\n at %p\n",
	"stranger", 34, 4.82749382382, 1600, '\0', '\t', ' ', p);
	ft_printf("    hello %s, you are %3d years-old and i will kidnap you in\n %.4Lf\n months at %x hours with %c%c%c others\n at %p\n",
	"stranger", 34, 4.82749382382, 1600, '\0', '\t', ' ', p);
	ft_memdel((void*)&p);
}*/

void			basic_tests(void)
{
	char	*p;
	char	*s;
	int		d;
	unsigned int		lu;
	unsigned long int	lo;

	p = ft_strnew(3);
	s = ft_strdup("and IIIIIIIIIIIiIIIII will aLLLLways\n");
	d = 2345678;
	lu = 2345678; 
	lo = 4294967295;

	ft_printf("hello %c that was a NULL char", 0);
	ft_printf("\n----------\n");
	ft_printf("hello %c that was another char", 123);
	ft_printf("\n----------\n");
	ft_printf("this is s %s\nthis is s with precision %60s\nthis is s with '-' precision %-60s I LOVE BIG butts AND I CANNOT LIE", s, s, s);
	ft_printf("\n----------\n");
	ft_printf("this is p %p\nthis is p with precision %20p\nthis is p with '-' precision %-20p%p", p, p, p, s);
	ft_printf("\n----------\n");
	ft_printf("this is d %d, then i %i\nthis is d with l %ld and ll %lld\n same for i %li and %lli", d, d, lu, lu, lo, lo);
	ft_printf("\n----------\n");
	ft_printf("this is d with precision %20d\n one with 0 %020d\nand one with '-' %-20d\n one where '-' and 0 are present (0 is ignored) %-020d", d, d, d, d);
	ft_printf("\n----------\n");
	ft_printf("this is d with '+' %+d\nthen same with precision (spc ignored) %+ 20d\nthe same with 0 %+020d", 56, 56, 56);
	ft_printf("\n----------\n");
	ft_printf("this is u %u\nthis is u with l %lu\n and ll %llu\n", lu, (lo * 3), (lo * 3));
	ft_printf("\n----------\n");
	ft_printf("this is u with h %hu\nand here it is with hh %hhu", (lu / 2), (lu / 2));
	ft_printf("\n----------\n");
	ft_printf("this is an o %o with an l %lo and an ll %llo", d, d, d);
	ft_printf("\n----------\n");
	ft_printf("this is an o with 0 %020o and a - %-20o", d, d);
	ft_printf("\n----------\n");
	ft_printf("this is an x %X with l %lX and ll %llX", 63, 63, 63);
	ft_printf("\n----------\n");
	ft_printf("this is an x %X with l %lX and ll %llX", 63, (long)63, (long long)63);
	ft_printf("\n----------\n");
	ft_printf("an x with  a # %#X and same with 0 pad %07x and '-' %-7x" , 63, 63, 63);
	ft_printf("this is d with h %hd\nand here is i %hi", (d / 2), (d / 2));
	ft_printf("this is f %f\n and f with l %lf and L %Lf", (d / 0.233), (d / 0.233), (d / 0.233));
	ft_printf("this is f with precision 9 %.9f\nwith 0 %.0f\nwith just . %.f\n", (d / 0.233), (d / 0.233), (d / 0.233));
	ft_memdel((void*)&p);
}

/*problems uncovered:
a '-' is written with d before the number
currently, the d, i, and u values get lost at some point for a mysterious reason

hh is having a bit of trouble for int and unsigned
h gives funky values with anything and everything
real printf doesn't do the same if it's ' ' and min_midth
with HEX it gives me trouble with 0 padding
must delete strtrim_end and _start. useless rn, i don't use them
*/

void			ll_tests(void)
{
	int				d = 0;
	int				i = -12345678;
	long long int	l = 4294967295;
	unsigned long	ll = 8294967295;

	ft_printf("d and i with l\n%ld\n%li", d, i);
	ft_printf("\n----------\n");
	ft_printf("d and i with ll\n%lld\n%lli", l, l);
	ft_printf("\n----------\n");
	ft_printf("u with l and ll\n%lu\n%llu", l, ll);
	ft_printf("\n----------\n");
	ft_printf("o with l and ll\n%lo\n%llo", i, i);
	ft_printf("\n----------\n");
	/*for (d = 0; d <= 20; d++)
		ft_printf("%d\n", d);
	for (d = 0; d >= -20; d--)
		ft_printf("%d\n", d);*/
}


int				main(void)
{
	ll_tests();
	basic_tests();
	return (0);
}
