/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   team.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/21 22:58:51 by dbenoit           #+#    #+#             */
/*   Updated: 2014/06/21 22:58:54 by dbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include "server.h"
#include "structs.h"

t_team		*get_team_by_name(char *name)
{
	t_team	*temp;

	if (g_teams != NULL)
	{
		temp = g_teams;
		while (temp)
		{
			if (!ft_strcmp(temp->name, name))
				return (temp);
			temp = temp->next;
		}
	}
	return (NULL);
}

int			team_get_num_players(t_team *team)
{
	t_player	*temp;
	int			num;

	if (!team)
		return (0);
	num = 0;
	temp = g_players;
	while (temp)
	{
		if (temp->team == team)
			num++;
		temp = temp->next;
	}
	return (num);
}
