#include <stdio.h>
#include <strings.h>
#include "../libfts.h"

int		main(void)
{
	char t1[] = "chaussette";
	char t2[] = "chaussette";
	char t3[] = "";
	char t4[] = "";
	char *t5 = "savonette";
	char *t6 = "savonette";
	int i = 0;

	printf("\n\n ==========[bzero]==========\n");
	ft_bzero(t1, 2);
	bzero(t2, 2);
	if (memcmp(t1, t2, sizeof(*t1)))
		i++;
	ft_bzero(t3, 1);
	bzero(t4, 1);
	if (memcmp(t3, t4, sizeof(*t3)))
		i++;
	ft_bzero(t5, 0);
	bzero(t6, 0);
	if (memcmp(t5, t6, sizeof(*t3)))
		i++;
	printf("%d/3 tests Ok \n", 3 - i);
	return (0);
}


