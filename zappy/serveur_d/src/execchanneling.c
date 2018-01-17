/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execchanneling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 20:20:10 by dbenoit           #+#    #+#             */
/*   Updated: 2014/06/26 20:20:13 by dbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include "server.h"
#include "actions.h"
#include <stdio.h>

extern int	g_inclevels[7][8];

int			check_start_inc(t_player *pl)
{
	t_player	*temp;
	int			i;
	int			lvl;

	i = 0;
	lvl = pl->level - 1;
	temp = g_players;
	while (temp)
	{
		if (temp->x == pl->x && temp->y == pl->y && temp->level == pl->level)
			i++;
		temp = temp->next;
	}
	if (i < g_inclevels[lvl][0])
		return (0);
	i = 0;
	while (i < 7)
	{
		if (g_map.cases[pl->y][pl->x].res[i] < g_inclevels[lvl][i + 1])
			return (0);
		i++;
	}
	return (1);
}

int			set_start_inc(t_player *pl)
{
	t_player	*temp;

	temp = g_players;
	while (temp)
	{
		if (temp->x == pl->x && temp->y == pl->y && temp->level == pl->level)
		{
			set_player_action(temp->clientid, INCANTATION, "");
			ok(temp->clientid, "elevation en cours");
		}
		temp = temp->next;
	}
	return (1);
}

int			exec_start_inc(int clientid, char *params)
{
	t_player	*pl;

	(void)params;
	ft_putstr("exec_start_inc\n");
	if ((pl = get_player_by_id(clientid)) != NULL)
	{
		if (check_start_inc(pl) == 0)
			ko(clientid);
		else
			set_start_inc(pl);
	}
	else
		ko(clientid);
	return (1);
}

int			exec_inc(int clientid, char *params)
{
	t_player	*pl;

	(void)params;
	ft_putstr("exec_inc\n");
	if ((pl = get_player_by_id(clientid)) != NULL)
	{
		pl->level += 1;
		check_team_victory(pl->team);
		fin_elevation(clientid, pl->level);
	}
	else
		ko(clientid);
	return (1);
}
