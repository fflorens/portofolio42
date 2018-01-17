#include <stdio.h>
#include <ctype.h>
#include <strings.h>
#include "../libfts.h"

int		main(void)
{
	int c = 0;
	int i = 0;

	printf("\n ==========[is_print]==========\n");
	while (c < 127)
	{
		if (ft_isprint(c) != isprint(c))
			i++;
		c++;
	}
	printf("%d/127 tests Ok \n", 127 - i);
	return (i);
}


