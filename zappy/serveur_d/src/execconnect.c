/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execconnect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 20:03:26 by dbenoit           #+#    #+#             */
/*   Updated: 2014/06/26 20:03:29 by dbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include "server.h"
#include "actions.h"
#include <stdlib.h>

int		connect_new_player(int clientid, t_team *team)
{
	t_player	*player;
	t_egg		*egg;

	egg = get_first_egg(team);
	if (!egg)
		return (0);
	player = player_new(clientid, "Bobby");
	player->x = egg->x;
	player->y = egg->y;
	player->team = team;
	player->angle = (rand() % 4) * 90;
	player_add(&g_players, player);
	egg_delete(&g_eggs, egg);
	return (1);
}

int		exec_connect(int clientid, char *params)
{
	t_team		*team;
	int			slotsleft;

	ft_putstr("exec_connect\n");
	team = get_team_by_name(params);
	if (!team)
		ko(clientid);
	else
	{
		slotsleft = get_available_eggs(team);
		if (slotsleft > 0)
		{
			connecter_nbclient(clientid, slotsleft - 1);
			if (connect_new_player(clientid, team) != 0)
				connecter_taille_map(clientid);
			else
				ko(clientid);
		}
		else
			ko(clientid);
	}
	return (1);
}
