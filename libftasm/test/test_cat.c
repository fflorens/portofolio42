#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "../libfts.h"

int		main(void)
{
	char	buff[0xFFFF];
	int		i, fd;

	printf("\n ==========[ft_cat]==========\n");
	printf("Write the name of the file to cat, or press Ctrl+D to read from stdin\n");
	i = read(0, buff, 0xFFFF);
	if (i > 0)
	{
		buff[i - 1] = '\0';
		fd = open(buff, O_RDONLY);
		if (fd > 0)
		{
			printf("reading from %s\n\n\n", buff);
			ft_cat(fd);
			close(fd);
		}
		else
			perror("open");
	}
	else
	{
		printf("ft_cat on STDIN\n\n\n");
		ft_cat(0);
	}
	return (0);
}


