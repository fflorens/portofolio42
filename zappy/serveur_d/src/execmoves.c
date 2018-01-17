/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execmoves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 20:07:19 by dbenoit           #+#    #+#             */
/*   Updated: 2014/06/26 20:07:22 by dbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include "server.h"
#include "actions.h"

int		exec_avance(int clientid, char *params)
{
	t_player	*player;

	(void)params;
	ft_putstr("exec_avance\n");
	if ((player = get_player_by_id(clientid)) != NULL)
	{
		if (player->angle == 0)
			player->x = (player->x + 1) % (g_map.width);
		if (player->angle == 180)
			player->x = (player->x - 1 + g_map.width) % (g_map.width);
		if (player->angle == 90)
			player->y = (player->y - 1 + g_map.height) % (g_map.height);
		if (player->angle == 270)
			player->y = (player->y + 1) % (g_map.height);
		ok(clientid, NULL);
		return (1);
	}
	return (0);
}

int		exec_gauche(int clientid, char *params)
{
	t_player	*player;

	(void)params;
	ft_putstr("exec_gauche\n");
	if ((player = get_player_by_id(clientid)) != NULL)
	{
		player->angle = (player->angle + 90) % 360;
		ok(clientid, NULL);
		return (1);
	}
	return (0);
}

int		exec_droite(int clientid, char *params)
{
	t_player	*player;

	(void)params;
	ft_putstr("exec_droite\n");
	if ((player = get_player_by_id(clientid)) != NULL)
	{
		player->angle = (player->angle - 90 + 360) % 360;
		ok(clientid, NULL);
		return (1);
	}
	return (0);
}
