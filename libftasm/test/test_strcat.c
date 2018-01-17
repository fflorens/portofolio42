#include <stdio.h>
#include <strings.h>
#include "../libfts.h"

#define S1 "THE CAKE IS A LIE\0NOPE\0"
#define S2 "The night is dark and full of terror\n"
#define S3 "Death solves all problems -- no man, no problem.\n"
#define S4 "\0"

int		main(void)
{
	char	buff[255];
	char	buf[0xFF];
	int		i = 0;

	printf("\n ==========[strcat]==========\n");
	bzero(buff, 255);
	bzero(buf, 0xFF);
	ft_strcat(buf, S1);
	strcat(buff, S1);
	if (memcmp(buf, buff, 255))
		i++;
	bzero(buff, 255);
	bzero(buf, 0xFF);
	ft_strcat(buf, S2);
	strcat(buff, S2);
	if (memcmp(buf, buff, 255))
		i++;
	bzero(buff, 255);
	bzero(buf, 0xFF);
	ft_strcat(buf, S3);
	strcat(buff, S3);
	if (memcmp(buf, buff, 255))
		i++;
	bzero(buff, 255);
	bzero(buf, 0xFF);
	ft_strcat(buf, S1);
	strcat(buff, S1);
	ft_strcat(buf, S2);
	strcat(buff, S2);
	ft_strcat(buf, S3);
	strcat(buff, S3);
	if (memcmp(buf, buff, 255))
		i++;
	bzero(buff, 255);
	bzero(buf, 0xFF);
	ft_strcat(buf, S4);
	strcat(buff, S4);
	if (memcmp(buf, buff, 255))
		i++;
	printf("%d/5 tests Ok \n", 5 - i);
	return (i);
}


