/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listegg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 23:51:36 by dbenoit           #+#    #+#             */
/*   Updated: 2014/06/25 23:51:39 by dbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include "server.h"
#include "libft.h"
#include <stdlib.h>

t_egg		*egg_new(int x, int y, t_team *team, int type)
{
	t_egg	*egg;

	egg = (t_egg *)malloc(sizeof(t_egg));
	egg->x = x;
	egg->y = y;
	egg->team = team;
	if (type == 0)
	{
		egg->turnalive = 0;
		egg->turndead = 1000000;
	}
	else
	{
		egg->turnalive = 600;
		egg->turndead = 1200;
	}
	egg->next = NULL;
	return (egg);
}

void		egg_add(t_egg **list, t_egg *item)
{
	t_egg	*temp;

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

void		egg_delete(t_egg **list, t_egg *item)
{
	t_egg	*temp;

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
	free(item);
}
