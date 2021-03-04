#include "ft_printf.h"
#include <fcntl.h>
#include <stdio.h>
// #include "test_mains.h"

int		main(int ac, char **av)
{
	int	ret_ft = 0;
	int ret_or = 0;
	int fd = 1;

	char	*s1 = "JEPJEP";
	char	*s2 = "JUPJUP";
	char	*s3 = NULL;
	char	*s4 = "NULL";
	
	char c = 's';
	char n = (char)NULL;
	char z = 0;
	
	int i = 125;
	int d = 135468;
	long l = 123249920l;
	long long ll = 21873030953;
	
	unsigned int u = 42;
	unsigned long ul = 102948ul;
	unsigned long long ull = 1984539831ull;
	
	short h = (short)34;
	signed char hh = (signed char)89;

	unsigned short uh = (unsigned short)22;
	unsigned char uhh = (unsigned char)65;

	float f = 34765.929839999999F;
	double db = 42.5;
	long double ldb = 48576.342L;
	
	printf("---EVAL PART 1: spd%%---\n");
	
	char *a1 = "\n%s %p %d";
	char *a2 = "\n%s %s %s %s";
	char *a3 = "\n%p %p %p %p";
	char *a4 = "\n%d %d %d %d";
	char *a5 = "\n%%";
	char *a6 = "\n%d %p %s %%";

	
	printf("\n%s\n", a1);
	ret_ft = ft_printf(a1, s1, &s1, i);
	ret_or = printf(a1, s1, &s1, i);
	printf("\n%d:%d", ret_ft, ret_or);
	
	printf("\n%s\n", a2);
	ret_ft = ft_printf(a2, s1, s2, s3, s4);
	ret_or = printf(a2, s1, s2, s3, s4);
	printf("\n%d:%d", ret_ft, ret_or);

	printf("\n%s\n", a3);
	ret_ft = ft_printf(a3, s1, &n, s4, &f);
	ret_or = printf(a3, s1, &n, s4, &f);
	printf("\n%d:%d", ret_ft, ret_or);
	
	printf("\n%s\n", a4);
	ret_ft = ft_printf(a4, i, d, -10, 0);
	ret_or = printf(a4, i, d, -10, 0);
	printf("\n%d:%d", ret_ft, ret_or);
	
	printf("\n%s\n", "\ndouble percent");
	ret_ft = ft_printf(a5);
	ret_or = printf(a5);
	printf("\n%d:%d", ret_ft, ret_or);
	
	printf("\n%s\n", a6);
	ret_ft = ft_printf(a6, d, &d, s2);
	ret_or = printf(a6, d, &d, s2);
	printf("\n%d:%d", ret_ft, ret_or);
	
	printf("\n\n---EVAL PART 2: types iouxXc---\n");

	char *b1 = "\n%i %u %o %x %X %c %c %c";

	printf("\n%s\n", b1);
	ret_ft = ft_printf(b1, i, u, u, u, u, c, z, n);
	ret_or = printf(b1, i, u, u, u, u, c, z, n);
	printf("\n%d:%d", ret_ft, ret_or);
	
	printf("\n\n---EVAL PART 3 : various combos ---\n");

	char *c1 = "\n%p %c %s %d %i %u %o %x %X %f";
	char *c2 = "\n%u %s %c %i %u %f";
	char *cc = "\n%i %c %d %u %f";
	
	printf("\n%s\n", c1);
	ret_ft = ft_printf(c1, &c, c, s2, d, i, u, u, u, u, f);
	ret_or = printf(c1, &c, c, s2, d, i, u, u, u, u, f);
	printf("\n%d:%d", ret_ft, ret_or);
	
	printf("\n%s\n", c2);
	ret_ft = ft_printf(c2, u, s1, c, i, d, i, u, f);
	ret_or = printf(c2, u, s1, c, i, d, i, u, f);
	printf("\n%d:%d", ret_ft, ret_or);
	
	printf("\n%s\n", cc);
	ret_ft = ft_printf(cc, i, c, d, u, f);
	ret_or = printf(cc, i, c, d, u, f);
	printf("\n%d:%d", ret_ft, ret_or);
	
	printf("\n\n---EVAL PART 4 : flags and width---\n");
	
	char *c3 = "\n%10p %10c %10s %10d %10i %10u %10o %10x %10X %10f";
	char *c4 = "\n%4p %8c %16s %9d %10i %2u %16o %14x %20X %1f";
	char *c5 = "\n%-10p %-10c %-10s %-10d %-10i %-10u %-10o %-10x %-10X %-10f";//all defined
	char *c6 = "\n%010p %010c %010s %010d %010i %010u %010o %010x %010X %010f";//vain diouxxf
	char *c7 = "\n% 10p % 10c % 10s % 10d % 10i % 10u % 10o % 10x % 10X % 10f"; //vain id
	char *c8 = "\n%+10p %+10c %+10s %+10d %+10i %+10u %+10o %+10x %+10X %+10f"; //vain id
	char *c9 = "\n%#10p %#10c %#10s %#10d %#10i %#10u %#10o %#10x %#10X %#10f"; //vain oxX
	char *mix1 = "\n%u, %-12s, %10c, % 5i, %-u, %0o, %-+2d %26f"; //variety
	char *mix2 = "\n%-10p %-10c %-10s %0- 10d %0-+10i %0-10u %#-010o %-#10x %0#10X %+-#25f"; //compos
	char *ff = "\n%u, %-12s, %10c, % 5i, %-u, %0o, %-+d %26f"; //copies the width from last to previous 3
	
	printf("\n%s\n", c3);
	ret_ft = ft_printf(c3, &c, c, s2, d, i, u, u, u, u, f);
	ret_or = printf(c3, &c, c, s2, d, i, u, u, u, u, f);
	printf("\n%d:%d", ret_ft, ret_or);
	
	printf("\n%s\n", c4);
	ret_ft = ft_printf(c4, &c, c, s2, d, i, u, u, u, u, f);
	ret_or = printf(c4, &c, c, s2, d, i, u, u, u, u, f);
	printf("\n%d:%d", ret_ft, ret_or);
	
	printf("\n%s\n", c5); //kaikki
	ret_ft = ft_printf(c5, &c, c, s2, d, i, u, u, u, u, f);
	ret_or = printf(c5, &c, c, s2, d, i, u, u, u, u, f);
	printf("\n%d:%d", ret_ft, ret_or);
	
	printf("\n%s\n", c6); //diouxxf
	ret_ft = ft_printf(c6, &c, c, s2, d, i, u, u, u, u, f);
	ret_or = printf(c6, &c, c, s2, d, i, u, u, u, u, f);
	printf("\n%d:%d", ret_ft, ret_or);
//	printf("\n%010p %010c %010s %010d %010i %010u %010o %010x %010X %010f", &c, c, s2, d, i, u, u, u, u, f);
	
	printf("\n%s\n", c7); //vain id
	ret_ft = ft_printf(c7, &c, c, s2, d, i, u, u, u, u, f);
	ret_or = printf(c7, &c, c, s2, d, i, u, u, u, u, f);
	printf("\n%d:%d", ret_ft, ret_or);
	
	printf("\n%s\n", c8); //vain id
	ret_ft = ft_printf(c8, &c, c, s2, d, i, u, u, u, u, f);
	ret_or = printf(c8, &c, c, s2, d, i, u, u, u, u, f);
	printf("\n%d:%d", ret_ft, ret_or);
	
	printf("\n%s\n", c9); //vain id
	ret_ft = ft_printf(c9, &c, c, s2, d, i, u, u, u, u, f);
	ret_or = printf(c9, &c, c, s2, d, i, u, u, u, u, f);
	printf("\n%d:%d", ret_ft, ret_or);
	
	printf("\n%s\n", mix1);
	ret_ft = ft_printf(mix1, u, s1, c, i, u, u, d, f);
	ret_or = printf(mix1, u, s1, c, i, u, u, d, f);
	printf("\n%d:%d", ret_ft, ret_or);

	printf("\n%s\n", mix2);
	ret_ft = ft_printf(mix2, &c, c, s2, d, i, u, u, u, u, f);
	ret_or = printf(mix2, &c, c, s2, d, i, u, u, u, u, f);
	printf("\n%d:%d", ret_ft, ret_or);
	
	printf("\n%s\n", ff);
	ret_ft = ft_printf(ff, u, s1, c, i, u, u, d, f);
	ret_or = printf(ff, u, s1, c, i, u, u, d, f);
	printf("\n%d:%d", ret_ft, ret_or);

//	printf("\n% 10p % 10c % 10s % 10d % 10i % 10u % 10o % 10x % 10X % 10f", &c, c, s2, d, i, u, u, u, u, f); //example: undefined

	printf("\n\n---EVAL PART 5: length---\n"); //not with types cp or flag 0

	char *e1 = "\n%ld, %li, %lo, %lu, %lx, %lX";
	char *e2 = "\n%lld, %lli, %llo, %llu, %llx, %llX";
	char *e3 = "\n%hd, %hi, %ho, %hu, %hx, %hX";
	char *e4 = "\n%hhd, %hhi, %hho, %hhu, %hhx, %hhX";
	char *e5 = "\n%lf, %Lf";
	char *e6 = "\n%ld, %hhx, %llu, %hi, %Lf, %hho, %hu, %llX, %lf";
	char *e7 = "\n%hhx, %llu, %ld, %hu, %llX, %hi, %Lf, %hho, %lf";
	char *e8 = "\n%15hhx, %6.8llu, %19.9ld, %8hu, %llX, %8.8hi, %10Lf, %hho, %.lf";
	char *e9 = "\n%10hhx, %5llu, %8ld, %4hu, %12llX, %6hi, %12Lf, %6hho, %15lf";
	char *e10 = "\n%0hhx, %-llu, %+ld, %0hu, %#llX, % hi, %0Lf, %hho, % lf";
	char *e11 = "\n%0-#5hhx, %-012llu, %+-15ld, %0-8hu, %0-#8llX, % +8hi, %+ 12Lf, %- 10hho, %012lf";

	printf("\n%s\n", e1);
	ret_ft = ft_printf(e1, l, i, ul, ul, ul, ul);
	ret_or = printf(e1, l, i, ul, ul, ul, ul);
	printf("\n%d:%d", ret_ft, ret_or);
	
	printf("\n%s\n", e2);
	ret_ft = ft_printf(e2, ll, i, ull, ull, ull, ull);
	ret_or = printf(e2, ll, i, ull, ull, ull, ull);
	printf("\n%d:%d", ret_ft, ret_or);
	
	printf("\n%s\n", e3);
	ret_ft = ft_printf(e3, h, h, uh, uh, uh, uh);
	ret_or = printf(e3, h, h, uh, uh, uh, uh);
	printf("\n%d:%d", ret_ft, ret_or);
	
	printf("\n%s\n", e4);
	ret_ft = ft_printf(e4, hh, hh, uhh, uhh, uhh, uhh);
	ret_or = printf(e4, hh, hh, uhh, uhh, uhh, uhh);
	printf("\n%d:%d", ret_ft, ret_or);
	
	printf("\n%s\n", e5);
	ret_ft = ft_printf(e5, db, ldb);
	ret_or = printf(e5, db, ldb);
	printf("\n%d:%d", ret_ft, ret_or);
	
	printf("\n%s\n", e6);
	ret_ft = ft_printf(e6, l, hh, ull, h, ldb, uhh, uh, ll, db);
	ret_or = printf(e6, l, hh, ull, h, ldb, uhh, uh, ll, db);
	printf("\n%d:%d", ret_ft, ret_or);
	
	printf("\n%s\n", e7);
	ret_ft = ft_printf(e7, hh, ull, l, uh, ull, h, ldb, uhh, db);
	ret_or = printf(e7, hh, ull, l, uh, ull, h, ldb, uhh, db);
	printf("\n%d:%d", ret_ft, ret_or);
	
	printf("\n%s\n", e8);
	ret_ft = ft_printf(e8, hh, ull, l, uh, ull, h, ldb, uhh, db);
	ret_or = printf(e8, hh, ull, l, uh, ull, h, ldb, uhh, db);
	printf("\n%d:%d", ret_ft, ret_or);

	printf("\n%s\n", e9);
	ret_ft = ft_printf(e9, hh, ull, l, uh, ull, h, ldb, uhh, db);
	ret_or = printf(e9, hh, ull, l, uh, ull, h, ldb, uhh, db);
	printf("\n%d:%d", ret_ft, ret_or);
	
	printf("\n%s\n", e10);
	ret_ft = ft_printf(e10, hh, ull, l, uh, ull, h, ldb, uhh, db);
	ret_or = printf(e10, hh, ull, l, uh, ull, h, ldb, uhh, db);
	printf("\n%d:%d", ret_ft, ret_or);
	
	printf("\n%s\n", e11);
	ret_ft = ft_printf(e11, hh, ull, l, uh, ull, h, ldb, uhh, db);
	ret_or = printf(e11, hh, ull, l, uh, ull, h, ldb, uhh, db);
	printf("\n%d:%d", ret_ft, ret_or);

	printf("\n\n---EVAL PART 6: precision---\n"); //not with types cp or flag 0

	char *d1 = "\n%.18p %.12c %.3s %.d %.0i %.5u %.18o %.1x %.12X %.12f";
	char *d2 = "\n%p %.12c %.3s %.8d %.1i %u %o %x %.20X %.12f";
	char *d3 = "\n%.10ld, %.10li, %.10lo, %.10lu, %.10lx, %.10lX";
	char *d4 = "\n%.10lld, %.10lli, %.10llo, %.10llu, %.10llx, %.10llX";
	char *d5 = "\n%.10hd, %.10hi, %.10ho, %.10hu, %.10hx, %.10hX";
	char *d6 = "\n%.10hhd, %.10hhi, %.10hho, %.10hhu, %.10hhx, %.10hhX";
	char *d7 = "\n%.10lf, %.10Lf";
	char *mix3 = "\n%.8u, %-12.5s, %10c, % 5.3i, %-.4u, %0.17o, %-+.2d %.16f"; //variety with precision, not cp;
	char *mix4 = "\n%-10.12p %-10.12c %-10.12s %10.12d %0-+10.12i %0-10.12u %#-010.12o %-#10.12x %0#10.12X %+-#10.12f"; //compos
	char *mix5 = "\n%-10.0shappy %0-15.12o %15.9d %0-+15.12i %-15.12u %#-15.12o %-#20.12x %0#20.12X %+-#20.f"; //compos

	printf("\n%s\n", d1); //precision with p-flag
	ret_ft = ft_printf(d1, &i, c, s2, d, i, u, u, u, u, f);
	ret_or = printf(d1, &i, c, s2, d, i, u, u, u, u, f);
	printf("\n%d:%d", ret_ft, ret_or);
	
	printf("\n%s\n", d2);
	ret_ft = ft_printf(d2, &i, c, s2, d, i, u, u, u, u, f);
	ret_or = printf(d2, &i, c, s2, d, i, u, u, u, u, f);
	printf("\n%d:%d", ret_ft, ret_or);
	
		printf("\n%s\n", d3);
	ret_ft = ft_printf(d3, l, i, ul, ul, ul, ul);
	ret_or = printf(d3, l, i, ul, ul, ul, ul);
	printf("\n%d:%d", ret_ft, ret_or);
	
	printf("\n%s\n", d4);
	ret_ft = ft_printf(d4, ll, i, ull, ull, ull, ull);
	ret_or = printf(d4, ll, i, ull, ull, ull, ull);
	printf("\n%d:%d", ret_ft, ret_or);
	
	printf("\n%s\n", d5);
	ret_ft = ft_printf(d5, h, h, uh, uh, uh, uh);
	ret_or = printf(d5, h, h, uh, uh, uh, uh);
	printf("\n%d:%d", ret_ft, ret_or);
	
	printf("\n%s\n", d6);
	ret_ft = ft_printf(d6, hh, hh, uhh, uhh, uhh, uhh);
	ret_or = printf(d6, hh, hh, uhh, uhh, uhh, uhh);
	printf("\n%d:%d", ret_ft, ret_or);
	
	printf("\n%s\n", d7);
	ret_ft = ft_printf(d7, db, ldb);
	ret_or = printf(d7, db, ldb);
	printf("\n%d:%d", ret_ft, ret_or);
	
	printf("\n%s\n", mix3);
	ret_ft = ft_printf(mix3, u, s1, c, i, u, u, d, f);
	ret_or = printf(mix3, u, s1, c, i, u, u, d, f);
	printf("\n%d:%d", ret_ft, ret_or);
	
	printf("\n%s\n", mix4);
	ret_ft = ft_printf(mix4, &i, c, s2, d, i, u, u, u, u, f);
	ret_or = printf(mix4, &i, c, s2, d, i, u, u, u, u, f);
	printf("\n%d:%d", ret_ft, ret_or);

	printf("\n%s\n", mix5);
	ret_ft = ft_printf(mix5, s2, d, i, u, u, u, u, f);
	ret_or = printf(mix5, s2, d, i, u, u, u, u, f);
	printf("\n%d:%d", ret_ft, ret_or);
	
	printf("\n\n---EVAL PART 7: BONUS---\n"); //not with types cp or flag 0
	
	fd = open(av[1], O_APPEND | O_WRONLY | O_CREAT, 0777);
	printf("\n!!fd:%d!!\n", fd);
	ret_ft = ft_printf("{YEL}Lala{MAG}lala, %d%% des {TRY}gens{WHT} qui{BLD} {BLK}parlent{GRN}{#FD} à Ly adorent {#FD}%s. Ou Presque. %p\n", 100, fd, 1, "Ly", &s1);
	ret_or = printf("\x1B[0m""Lalalala, %d%% des gens\x1B[31m qui parlent à Ly adorent %s. Ou Presque. %p\n", 100, "Ly", &s1);
	return (0);
}
