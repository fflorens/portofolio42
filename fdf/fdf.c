/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 14:45:25 by fflorens          #+#    #+#             */
/*   Updated: 2013/12/22 18:54:17 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "fdf.h"
#include "gnl.h"
#include <mlx.h>


int			main(int ac, char **av)
{
	t_fdf	*fdf;
	int		fd;

	if (ac != 2)
		return (usage(av[0], 0));
	if ((fdf = fdfinit()) == NULL)
		return (usage(av[0], -1));
	if ((fd = ft_open(av[1])) < 0)
		return (fd);
	fdf_fill_list(fdf, fd);
	fdf_list_resize(fdf);
	mlx_expose_hook(fdf->win, expose_hook, fdf);
	mlx_key_hook(fdf->win, key_hook, fdf);
	mlx_loop(fdf->mlx);
	fdfdestroy(&fdf);
	return (0);
}

int			usage(char *name, int status)
{
	if (status == -1)
	{
		write(1, "error initalizing mlx", 21);
		return (-1);
	}
	write(1, "usage : ", 8);
	write(1, name, ft_strlen(name));
	write(1, " map_to_display\n", 17);
	return (1);
}

size_t		ft_strlen(char *str)
{
	if (!str || !*str)
		return (0);
	return (ft_strlen(str + 1) + 1);
}

t_fdf		*fdfinit(void)
{
	t_fdf	*fdf;

	if ((fdf = (t_fdf *)malloc(sizeof(t_fdf))) == NULL)
		return (NULL);
	if ((fdf->mlx = mlx_init()) == NULL)
		return (NULL);
	if ((fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, TITLE)) == NULL)
		return (NULL);
	fdf->x2dmax = 0;
	fdf->x2dmin = 0;
	fdf->y2dmax = 0;
	fdf->y2dmin = 0;
	fdf->z3dmax = 0;
	fdf->z3dmin = 0;
	fdf->list = NULL;
	return (fdf);
}

void		fdfdestroy(t_fdf **fdf)
{
	if (!fdf || !*fdf)
		return ;
	fdfdestroylst((*fdf)->list);
	(*fdf)->list = NULL;
	free((*fdf)->mlx);
	free((*fdf)->win);
	(*fdf)->mlx = NULL;
	(*fdf)->win = NULL;
	free(*fdf);
	*fdf = NULL;
}
