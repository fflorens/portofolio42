#include <stdio.h>
#include <ctype.h>
#include <strings.h>
#include "../libfts.h"

int		main(void)
{
	int c = 0;
	int i = 0;

	printf("\n ==========[is_ascii]==========\n");
	while (c < 127)
	{
		if (ft_isascii(c) != isascii(c))
			i++;
		c++;
	}
	printf("%d/127 tests Ok \n", 127 - i);
	return (i);
}


