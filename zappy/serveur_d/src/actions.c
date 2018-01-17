/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 17:28:38 by dbenoit           #+#    #+#             */
/*   Updated: 2014/06/06 17:28:58 by dbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include "server.h"
#include "actions.h"
#include "stdlib.h"
#include <stdio.h>

t_chk	g_fcts[14] =
{
	exec_rien,
	exec_connect,
	exec_avance,
	exec_gauche,
	exec_droite,
	exec_voir,
	exec_inv,
	exec_prend,
	exec_pose,
	exec_expulse,
	exec_broadcast,
	exec_inc,
	exec_fork,
	exec_conbr
};

int		g_fctsturns[14] =
{
	0,
	0,
	7,
	7,
	7,
	7,
	1,
	7,
	7,
	7,
	7,
	300,
	42,
	0
};

int		check_team_victory(t_team *team)
{
	t_player	*player;
	int			count;

	if (!team)
		return (0);
	count = 0;
	player = g_players;
	while (player)
	{
		if (player->team == team && player->level == 8)
			count++;
		player = player->next;
	}
	if (count >= 6)
	{
		ft_putstr("\n------------------------------\nTEAM '");
		ft_putstr(team->name);
		ft_putstr("' WINS !\n------------------------------\n");
	}
	return (1);
}

int		set_player_action(int clientid, int cmd, char *params)
{
	t_player	*temp;

	temp = g_players;
	while (temp)
	{
		if (temp->clientid == clientid)
		{
			temp->action = cmd;
			if (temp->actionparams != NULL)
				free(temp->actionparams);
			temp->actionparams = NULL;
			if (cmd >= 0 && cmd < 14)
				temp->actionturnleft = g_fctsturns[cmd];
			if (params != NULL)
				temp->actionparams = ft_strdup(params);
		}
		temp = temp->next;
	}
	return (1);
}

int		chk_has_action(t_player *player)
{
	if (!player || player_has_action_by_id(player->clientid))
	{
		ko(player->clientid);
		return (0);
	}
	return (1);
}

int		execute_player_action(t_player *player)
{
	if (player && (int)player->action >= 0 && (int)player->action < 14)
	{
		g_fcts[player->action](player->clientid, player->actionparams);
		player_clear_action(player);
	}
	return (1);
}
