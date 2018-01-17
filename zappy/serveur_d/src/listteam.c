/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listteam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 17:10:59 by dbenoit           #+#    #+#             */
/*   Updated: 2014/06/20 17:11:03 by dbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include "server.h"
#include "libft.h"
#include <stdlib.h>

t_team		*team_new(int maxplayers, char *name)
{
	t_team	*team;

	(void)maxplayers;
	team = (t_team *)malloc(sizeof(t_team));
	team->name = ft_strdup(name);
	team->next = NULL;
	return (team);
}

void		team_add(t_team **list, t_team *item)
{
	t_team	*temp;

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

void		team_delete(t_team **list, t_team *item)
{
	t_team	*temp;

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
	free(item);
}
