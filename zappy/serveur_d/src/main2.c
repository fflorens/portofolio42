/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 21:43:15 by dbenoit           #+#    #+#             */
/*   Updated: 2014/06/26 21:49:43 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "structs.h"
#include "server.h"
#include <stdio.h>
#include <unistd.h>
#include "main.h"

int		init_port(int ac, char **av)
{
	int		i;
	char	*txt;

	i = 1;
	txt = "DEFAULT VALUE PORT : ";
	while (i < ac)
	{
		if (ft_strcmp(av[i], "-p") == 0)
			return (ft_atoi(av[i + 1]));
		i++;
	}
	write(1, txt, ft_strlen(txt));
	write(1, ft_itoa(DEFAULT_PORT), ft_strlen(ft_itoa(DEFAULT_PORT)));
	write(1, "\n", 1);
	return (DEFAULT_PORT);
}

int		init_largeur(int ac, char **av)
{
	int		i;
	char	*txt;

	i = 1;
	txt = "DEFAULT VALUE LARGEUR : ";
	while (i < ac)
	{
		if (ft_strcmp(av[i], "-x") == 0)
			return (ft_atoi(av[i + 1]));
		i++;
	}
	write(1, txt, ft_strlen(txt));
	write(1, ft_itoa(DEFAULT_LARGEUR), ft_strlen(ft_itoa(DEFAULT_LARGEUR)));
	write(1, "\n", 1);
	return (DEFAULT_LARGEUR);
}

int		init_hauteur(int ac, char **av)
{
	int		i;
	char	*txt;

	i = 1;
	txt = "DEFAULT VALUE HAUTEUR : ";
	while (i < ac)
	{
		if (ft_strcmp(av[i], "-y") == 0)
			return (ft_atoi(av[i + 1]));
		i++;
	}
	write(1, txt, ft_strlen(txt));
	write(1, ft_itoa(DEFAULT_HAUTEUR), ft_strlen(ft_itoa(DEFAULT_HAUTEUR)));
	write(1, "\n", 1);
	return (DEFAULT_HAUTEUR);
}

int		init_tempo(int ac, char **av)
{
	int		i;
	char	*txt;

	i = 1;
	txt = "DEFAULT VALUE TEMPS : ";
	while (i < ac)
	{
		if (ft_strcmp(av[i], "-t") == 0)
			return (ft_atoi(av[i + 1]));
		i++;
	}
	write(1, txt, ft_strlen(txt));
	write(1, ft_itoa(DEFAULT_TEMPO), ft_strlen(ft_itoa(DEFAULT_TEMPO)));
	write(1, "\n", 1);
	return (DEFAULT_TEMPO);
}

int		init_nb_client(int ac, char **av)
{
	int		i;
	char	*txt;

	i = 1;
	txt = "DEFAULT VALUE NB CLIENT : ";
	while (i < ac)
	{
		if (ft_strcmp(av[i], "-c") == 0)
			return (ft_atoi(av[i + 1]));
		i++;
	}
	write(1, txt, ft_strlen(txt));
	write(1, ft_itoa(DEFAULT_NB_CLIENT), ft_strlen(ft_itoa(DEFAULT_NB_CLIENT)));
	write(1, "\n", 1);
	return (DEFAULT_NB_CLIENT);
}
