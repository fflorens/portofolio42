/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/31 18:37:50 by dbenoit           #+#    #+#             */
/*   Updated: 2014/06/11 19:21:54 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include "server.h"
#include "reseau.h"
#include <stdlib.h>
#include <stdio.h>

int		process_new_turn(int *turn)
{
	get_turn_time_left(1);
	degen_eggs();
	players_new_turn(*turn);
	*turn = (*turn + 1) % 1260000000;
	generate_ressources(0, *turn);
	return (1);
}

int		check_actions(void)
{
	process_actions_requests();
	return (1);
}

int		init_map(void)
{
	int		i;
	int		j;

	g_map.cases = (t_case **)malloc(g_map.height * sizeof(t_case *));
	j = 0;
	while (j < g_map.height)
	{
		g_map.cases[j] = (t_case *)malloc(g_map.width * sizeof(t_case));
		i = 0;
		while (i < g_map.width)
		{
			g_map.cases[j][i].x = i;
			g_map.cases[j][i].y = j;
			g_map.cases[j][i].res[FOOD] = 0;
			g_map.cases[j][i].res[LINEMATE] = 0;
			g_map.cases[j][i].res[DERAUMERE] = 0;
			g_map.cases[j][i].res[SIBUR] = 0;
			g_map.cases[j][i].res[MENDIANE] = 0;
			g_map.cases[j][i].res[PHIRAS] = 0;
			g_map.cases[j][i].res[THYSTAME] = 0;
			i++;
		}
		j++;
	}
	return (1);
}

int		turn_loop(void)
{
	double		timeleft;
	int			turn;

	g_players = NULL;
	g_requests = NULL;
	timeleft = 0;
	turn = 0;
	while (1)
	{
		if (timeleft <= 0)
			process_new_turn(&turn);
		check_actions();
		timeleft = get_turn_time_left(0);
		if (timeleft == -1)
			return (0);
		do_select(timeleft);
	}
	return (1);
}
