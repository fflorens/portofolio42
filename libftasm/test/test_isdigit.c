#include <stdio.h>
#include <ctype.h>
#include <strings.h>
#include "../libfts.h"

int		main(void)
{
	int c = 0;
	int i = 0;

	printf("\n\n ==========[is_digit]==========\n");
	while (c < 127)
	{
		if (ft_isdigit(c) != isdigit(c))
			i++;
		c++;
	}
	printf("\n\n %d/127 tests Ok \n", 127 - i);
	return (i);
}


