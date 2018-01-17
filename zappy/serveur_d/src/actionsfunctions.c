/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actionsfunctions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 15:49:24 by dbenoit           #+#    #+#             */
/*   Updated: 2014/06/18 15:49:29 by dbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include "server.h"
#include "actions.h"
#include <math.h>
#include <stdio.h>

char	*g_resnames[7] =
{
	"nourriture",
	"linemate",
	"deraumere",
	"sibur",
	"mendiane",
	"phiras",
	"thystame"
};

int		g_inclevels[7][8] =
{
	{ 1, 0, 1, 0, 0, 0, 0, 0},
	{ 2, 0, 1, 1, 1, 0, 0, 0},
	{ 2, 0, 2, 0, 1, 0, 2, 0},
	{ 4, 0, 1, 1, 2, 0, 1, 0},
	{ 4, 0, 1, 2, 1, 3, 0, 0},
	{ 6, 0, 1, 2, 3, 0, 1, 0},
	{ 6, 0, 2, 2, 2, 2, 2, 1}
};

int		exec_rien(int clientid, char *params)
{
	(void)clientid;
	(void)params;
	return (1);
}

int		exec_fork(int clientid, char *params)
{
	t_player	*pl;

	(void)params;
	ft_putstr("exec_fork\n");
	if ((pl = get_player_by_id(clientid)) != NULL)
	{
		egg_add(&g_eggs, egg_new(pl->x, pl->y, pl->team, 1));
		if (pl->team == NULL)
			return (ko(clientid));
		ok(clientid, NULL);
	}
	else
		ko(clientid);
	return (1);
}

int		exec_conbr(int clientid, char *params)
{
	t_team		*team;
	t_player	*player;
	int			slotsleft;

	(void)params;
	if ((player = get_player_by_id(clientid)) != NULL)
	{
		ft_putstr("exec_conbr\n");
		team = player->team;
		if (team)
		{
			slotsleft = get_available_eggs(team);
			co_nbr(clientid, slotsleft);
		}
		else
		{
			ko(clientid);
		}
	}
	else
		ko(clientid);
	return (1);
}
