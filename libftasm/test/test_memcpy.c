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

	printf("\n ==========[memcpy]==========\n");
	bzero(buff, 255);
	bzero(buf, 0xFF);
	ft_memcpy(buf, S1, 10);
	memcpy(buff, S1, 10);
	if (memcmp(buf, buff, 255))
		i++;
	bzero(buff, 255);
	bzero(buf, 0xFF);
	ft_memcpy(buf, S2, 15);
	memcpy(buff, S2, 15);
	if (memcmp(buf, buff, 255))
		i++;
	bzero(buff, 255);
	bzero(buf, 0xFF);
	ft_memcpy(buf, S3, 12);
	memcpy(buff, S3, 12);
	if (memcmp(buf, buff, 255))
		i++;
	bzero(buff, 255);
	bzero(buf, 0xFF);
	ft_memcpy(buf, S1, 10);
	memcpy(buff, S1, 10);
	ft_memcpy(buf + 10, S2, 15);
	memcpy(buff + 10, S2, 15);
	ft_memcpy(buf + 25, S3, 12);
	memcpy(buff + 25, S3, 12);
	if (memcmp(buf, buff, 255))
		i++;
	bzero(buff, 255);
	bzero(buf, 0xFF);
	ft_memcpy(buf, S4, 1);
	memcpy(buff, S4, 1);
	if (memcmp(buf, buff, 255))
		i++;
	printf("%d/5 tests Ok \n", 5 - i);
	return (i);
}


