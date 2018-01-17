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

	printf("\n\n ==========[memset]==========\n");
	ft_memset(t1, 'q', 2);
	memset(t2, 'q', 2);
	if (memcmp(t1, t2, sizeof(*t1)))
		i++;
	ft_memset(t3, '1', 1);
	memset(t4, '1', 1);
	if (memcmp(t3, t4, sizeof(*t3)))
		i++;
	ft_memset(t5, 'c', 0);
	memset(t6, 'd', 0);
	if (memcmp(t5, t6, sizeof(*t3)))
		i++;
	printf("%d/3 tests Ok \n", 3 - i);
	return (0);
}


