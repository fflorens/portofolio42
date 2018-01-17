/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 11:04:28 by fflorens          #+#    #+#             */
/*   Updated: 2017/05/30 10:20:12 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <mach-o/arch.h>
#include <mach-o/loader.h>
#include <mach-o/nlist.h>
#include <mach-o/fat.h>
#include <mach-o/ranlib.h>
#include <ar.h>
#include "libft.h"
#include "ft_nm_otool.h"
#define PROT_MMAP (PROT_READ | PROT_WRITE)

char	*g_arch = NULL;

static int	open_file(char *name, void **ptr, int *fd, t_stat *buf)
{
	if ((*fd = open(name, O_RDONLY)) < 0)
		return (ft_error("Unable to open: ", name));
	if (fstat(*fd, buf) < 0)
	{
		close(*fd);
		return (ft_error("Unable to stat: ", name));
	}
	*ptr = mmap(NULL, buf->st_size, PROT_MMAP, MAP_PRIVATE, *fd, 0);
	if (*ptr == MAP_FAILED)
	{
		close(*fd);
		return (ft_error("Unable to map: ", name));
	}
	return (EXIT_SUCCESS);
}

static int	close_file(t_file *file, void **ptr, int *fd, int ret)
{
	if (file->sym)
		free(file->sym);
	if (file->sec)
		free(file->sec);
	if (munmap(*ptr, file->size))
		return (ft_error("Unable to unmap: ", file->name));
	if (close(*fd))
		return (ft_error("Unable to close: ", file->name));
	return (ret);
}

static int	check_arch_arg(int ac, char **av)
{
	NXArchInfo	*info;

	if (!ft_strcmp(av[1], "--"))
		return (1);
	if (!ft_strcmp(av[1], "-arch") && ac < 3)
		return (1);
	if (ac < 3 || ft_strcmp(av[1], "-arch"))
		return (0);
	else if (!ft_strcmp(av[2], "all"))
	{
		g_arch = av[2];
		return (2);
	}
	else
	{
		if (!ft_strcmp(av[2], "armv5e"))
			av[2][5] = '\0';
		if ((info = (NXArchInfo *)NXGetArchInfoFromName(av[2])) == NULL)
			return (1);
		g_arch = av[2];
	}
	return (2);
}

int			main(int ac, char **av)
{
	int			i[3];
	void		*ptr;
	t_stat		buf;
	t_file		file;

	if (ac < 2)
		return (ft_error("Missing arguments.\n", NULL));
	i[0] = check_arch_arg(ac, av);
	if ((i[2] = i[0] + 1) && !ft_strcmp(av[i[0]], "-arch"))
		return (ft_error("Missing parameters for -arch.\n", NULL));
	while (++i[0] < ac)
	{
		if (open_file(av[i[0]], &ptr, &i[1], &buf) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
		ft_bzero(&file, sizeof(t_file));
		file.size = buf.st_size;
		file.first = ((i[2] != i[0] && i[2] != ac) ? 1 : 0);
		file.name = av[i[0]];
		file.ptr = ptr;
		if (ft_nm(&file) != EXIT_SUCCESS)
			return (close_file(&file, &ptr, &i[1], EXIT_FAILURE));
		if (close_file(&file, &ptr, &i[1], EXIT_SUCCESS) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
