/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 11:09:23 by fflorens          #+#    #+#             */
/*   Updated: 2017/05/30 09:57:33 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <mach-o/loader.h>
#include <mach-o/nlist.h>
#include <mach-o/fat.h>
#include <mach-o/ranlib.h>
#include <ar.h>
#include "libft.h"
#include "ft_nm_otool.h"
#define PROT_MMAP (PROT_READ | PROT_WRITE)

char		*g_arch = NULL;

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
	if (munmap(*ptr, file->size))
		return (ft_error("Unable to unmap: ", file->name));
	if (close(*fd))
		return (ft_error("Unable to close: ", file->name));
	return (ret);
}

static int	check_arch_arg(int ac, char **av)
{
	NXArchInfo	*info;

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
	int			i;
	int			fd;
	void		*ptr;
	t_stat		buf;
	t_file		file;

	if (ac < 2)
		return (ft_error("Missing arguments.\n", NULL));
	i = check_arch_arg(ac, av);
	if (!ft_strcmp(av[i], "-arch"))
		return (ft_error("Missing parameters for -arch.\n", NULL));
	while (++i < ac)
	{
		if (open_file(av[i], &ptr, &fd, &buf) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
		ft_bzero(&file, sizeof(t_file));
		file.size = buf.st_size;
		file.name = av[i];
		file.ptr = ptr;
		if (ft_otool(&file) != EXIT_SUCCESS)
			return (close_file(&file, &ptr, &fd, EXIT_FAILURE));
		if (close_file(&file, &ptr, &fd, EXIT_SUCCESS) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
