#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "../libfts.h"

#define S1 "THE CAKE IS A LIE\0NOPE\0"
#define S2 "The night is dark and full of terror\n"
#define S3 "Death solves all problems -- no man, no problem.\n"
#define S4 "\0"

int		main(void)
{
	char	*tmp;
	char	*tmp2;
	int		i = 0;

	printf("\n ==========[strdup]==========\n");
	tmp = ft_strdup(S1);
	tmp2 = strdup(S1);
	if (strcmp(tmp, tmp2))
		i++;
	free(tmp);
	free(tmp2);
	tmp = ft_strdup(S2);
	tmp2 = strdup(S2);
	if (strcmp(tmp, tmp2))
		i++;
	free(tmp);
	free(tmp2);
	tmp = ft_strdup(S3);
	tmp2 = strdup(S3);
	if (strcmp(tmp, tmp2))
		i++;
	free(tmp);
	free(tmp2);
	tmp = ft_strdup(S4);
	tmp2 = strdup(S4);
	if (strcmp(tmp, tmp2))
		i++;
	free(tmp);
	free(tmp2);
	printf("%d/4 tests Ok \n", 4 - i);
	return (i);
}


