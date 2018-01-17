/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 21:43:15 by dbenoit           #+#    #+#             */
/*   Updated: 2014/06/26 21:07:52 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "structs.h"
#include "server.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"

t_team	*init_nom_equipe(int ac, char **av)
{
	int		i;
	t_team	*team;

	i = 1;
	team = NULL;
	while (i < ac)
	{
		if (ft_strcmp(av[i], "-n") == 0)
		{
			i++;
			while (av[i] && av[i][0] != '-')
			{
				team_add(&team, team_new(0, av[i]));
				i++;
			}
			return (team);
		}
		i++;
	}
	return (NULL);
}

int		usage(char *name)
{
	char *txt;

	if (name)
		write(1, name, ft_strlen(name));
	else
		write(1, "NULL", 4);
	txt = ": ./serveur -n <team> [<team>] [<team>] ... ";
	write(1, txt, ft_strlen(txt));
	txt = "[-p <port>] [-x <width>] [-y <height>] [-c <nb>] [-t <t>]";
	write(1, txt, ft_strlen(txt));
	return (-1);
}

int		main(int ac, char **av)
{
	int		c;
	t_team	*tmp;

	srand(time(NULL));
	g_teams = init_nom_equipe(ac, av);
	if (!g_teams)
		return (usage(av[0]));
	c = init_hauteur(ac, av);
	g_map.height = ((c <= 0) ? 30 : c);
	c = init_largeur(ac, av);
	g_map.width = ((c <= 0) ? 1 : c);
	c = init_tempo(ac, av);
	g_map.time = ((c > 0) ? c : 1);
	init_map();
	c = init_nb_client(ac, av);
	tmp = g_teams;
	while (tmp)
	{
		egg_random(c, tmp);
		tmp = tmp->next;
	}
	init_reseau(init_port(ac, av));
	turn_loop();
}
