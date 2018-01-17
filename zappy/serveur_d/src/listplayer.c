/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listplayer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 22:53:43 by dbenoit           #+#    #+#             */
/*   Updated: 2014/06/08 22:53:46 by dbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include "server.h"
#include "libft.h"
#include <stdlib.h>

t_player	*player_new(int clientid, char *name)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	player->clientid = clientid;
	player->name = ft_strdup(name);
	player->team = NULL;
	player->level = 1;
	player->x = 10;
	player->y = 10;
	player->angle = 0;
	player->action = RIEN;
	player->actionturnleft = 0;
	player->actionparams = NULL;
	player->res[FOOD] = 10;
	player->res[LINEMATE] = 0;
	player->res[DERAUMERE] = 0;
	player->res[SIBUR] = 0;
	player->res[MENDIANE] = 0;
	player->res[PHIRAS] = 0;
	player->res[THYSTAME] = 0;
	player->next = NULL;
	return (player);
}

void		player_add(t_player **list, t_player *item)
{
	t_player	*temp;

	if (!list || !item)
		return ;
	if (*list == NULL)
		*list = item;
	else
	{
		temp = *list;
		while (temp->next)
			temp = temp->next;
		temp->next = item;
	}
}

void		player_delete(t_player **list, t_player *item)
{
	t_player	*temp;

	if (!list || !item)
		return ;
	temp = *list;
	if (temp == item)
		*list = temp->next;
	else
	{
		while (temp->next != item)
			temp = temp->next;
		temp->next = item->next;
	}
	free(item->name);
	free(item->actionparams);
	free(item);
}
