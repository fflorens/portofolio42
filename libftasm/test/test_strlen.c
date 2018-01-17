#include <stdio.h>
#include <strings.h>
#include "../libfts.h"

#define S1 "THE CAKE IS A LIE\0NOPE\0"
#define S2 "The night is dark and full of terror\n"
#define S3 "Death solves all problems -- no man, no problem.\n"
#define S4 "\0"

int		main(void)
{
	int i = 0;

	printf("\n ==========[strlen]==========\n");
	if (ft_strlen(S1) != strlen(S1))
		i++;
	if (ft_strlen(S2) != strlen(S2))
		i++;
	if (ft_strlen(S3) != strlen(S3))
		i++;
	if (ft_strlen(S4) != strlen(S4))
		i++;
	printf("%d/4 tests Ok \n", 4 - i);
	return (i);
}


