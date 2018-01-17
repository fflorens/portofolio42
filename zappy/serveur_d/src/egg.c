/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   egg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 00:30:32 by dbenoit           #+#    #+#             */
/*   Updated: 2014/06/26 00:30:36 by dbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include "server.h"
#include "libft.h"
#include <stdlib.h>
#include <time.h>

int		egg_random(int num, t_team *team)
{
	int		i;
	int		randx;
	int		randy;

	if (!team)
		return (0);
	randx = 0;
	randy = 0;
	i = 0;
	while (i < num)
	{
		if (g_map.width > 1)
			randx = rand() % (g_map.width - 1);
		if (g_map.height > 1)
			randy = rand() % (g_map.height - 1);
		egg_add(&g_eggs, egg_new(randx, randy, team, 0));
		i++;
	}
	return (1);
}

int		degen_eggs(void)
{
	t_egg	*temp;

	temp = g_eggs;
	while (temp)
	{
		if (temp->turnalive > 0)
			temp->turnalive--;
		else if (temp->turndead > 0)
			temp->turndead--;
		if (temp->turndead <= 0)
			egg_delete(&g_eggs, temp);
		temp = temp->next;
	}
	return (1);
}

int		get_available_eggs(t_team *team)
{
	t_egg	*temp;
	int		count;

	if (!team)
		return (0);
	count = 0;
	temp = g_eggs;
	while (temp)
	{
		if (temp->team == team)
		{
			if (temp->turnalive <= 0 && temp->turndead > 0)
				count++;
		}
		temp = temp->next;
	}
	return (count);
}

t_egg	*get_first_egg(t_team *team)
{
	t_egg	*temp;

	if (!team)
		return (NULL);
	temp = g_eggs;
	while (temp)
	{
		if (temp->team == team)
		{
			if (temp->turnalive <= 0 && temp->turndead > 0)
				return (temp);
		}
		temp = temp->next;
	}
	return (NULL);
}
