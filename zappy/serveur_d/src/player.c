/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 23:27:58 by dbenoit           #+#    #+#             */
/*   Updated: 2014/06/08 23:28:02 by dbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include "server.h"
#include "libft.h"
#include <stdlib.h>

t_player	*get_player_by_id(int clientid)
{
	t_player	*temp;

	if (g_players != NULL)
	{
		temp = g_players;
		while (temp)
		{
			if (temp->clientid == clientid)
				return (temp);
			temp = temp->next;
		}
	}
	return (NULL);
}

int			players_new_turn(int turn)
{
	t_player	*temp;

	if (!g_players)
		return (0);
	temp = g_players;
	while (temp)
	{
		if (turn % 126 == 0)
			temp->res[FOOD] -= 1;
		if (temp->res[FOOD] <= 0)
		{
			dead(temp->clientid);
			player_delete(&g_players, temp);
		}
		temp->actionturnleft -= 1;
		if (temp->actionturnleft <= 0)
		{
			execute_player_action(temp);
			temp->actionturnleft = 0;
			temp->actionturnleft = RIEN;
			ft_memdel((void **)&temp->actionparams);
		}
		temp = temp->next;
	}
	return (1);
}

int			player_has_action_by_id(int clientid)
{
	t_player	*temp;

	if ((temp = get_player_by_id(clientid)) != NULL)
	{
		if (temp->action != RIEN)
			return (1);
	}
	return (0);
}

int			player_clear_action_by_id(int clientid)
{
	t_player	*temp;

	if ((temp = get_player_by_id(clientid)) != NULL)
	{
		temp->action = RIEN;
		temp->actionturnleft = 0;
		if (temp->actionparams != NULL)
			free(temp->actionparams);
		temp->actionparams = NULL;
	}
	return (1);
}

int			player_clear_action(t_player *player)
{
	if (!player)
		return (0);
	player->action = RIEN;
	player->actionturnleft = 0;
	if (player->actionparams != NULL)
		free(player->actionparams);
	player->actionparams = NULL;
	return (1);
}
