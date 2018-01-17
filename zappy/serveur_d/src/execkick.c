/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execkick.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 20:15:13 by dbenoit           #+#    #+#             */
/*   Updated: 2014/06/26 20:15:16 by dbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include "server.h"
#include "actions.h"

int		get_num_by_angle(t_player *player, int angle)
{
	if (angle == player->angle)
		return (5);
	else if (angle == (player->angle + 90) % 360)
		return (7);
	else if (angle == (player->angle + 180) % 360)
		return (1);
	else if (angle == (player->angle + 270) % 360)
		return (3);
	return (-1);
}

int		exec_expulse2(t_player *pl)
{
	t_player	*temp;
	int			count;

	count = 0;
	temp = g_players;
	while (temp)
	{
		if (temp != pl && temp->x == pl->x && temp->y == pl->y)
		{
			if (pl->angle == 0)
				temp->x = (temp->x + 1) % (g_map.width);
			if (pl->angle == 180)
				temp->x = (temp->x - 1 + g_map.width) % (g_map.width);
			if (pl->angle == 90)
				temp->x = (temp->y - 1 + g_map.height) % (g_map.height);
			if (pl->angle == 270)
				temp->x = (temp->y + 1) % (g_map.height);
			expulser(temp->clientid, get_num_by_angle(pl, pl->angle));
			count++;
		}
		temp = temp->next;
	}
	return (count);
}

int		exec_expulse(int clientid, char *params)
{
	t_player	*player;

	(void)params;
	ft_putstr("exec_expulse\n");
	if ((player = get_player_by_id(clientid)) != NULL)
	{
		if (exec_expulse2(player) == 0)
			ko(player->clientid);
		else
			ok(player->clientid, NULL);
		return (1);
	}
	return (0);
}
