#include <stdio.h>
#include <strings.h>
#include "../libfts.h"

#define S1 "THE CAKE IS A LIE\0NOPE\0"
#define S2 "The night is dark and full of terror\0"
#define S3 "Death solves all problems -- no man, no problem.\0"
#define S4 "\0"

int		main(void)
{
	printf("\n ==========[puts]==========\n");
	puts(S1);
	ft_puts(S1);
	puts(S2);
	ft_puts(S2);
	puts(S3);
	ft_puts(S3);
	puts((void *)0x0);
	ft_puts((void *)0x0);
	return (0);
}


