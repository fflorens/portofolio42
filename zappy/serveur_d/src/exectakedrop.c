/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exectakedrop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 20:12:57 by dbenoit           #+#    #+#             */
/*   Updated: 2014/06/26 20:13:01 by dbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include "server.h"
#include "actions.h"

extern char	*g_resnames[7];

int			exec_prend(int clientid, char *params)
{
	t_player	*pl;
	int			i;

	if ((pl = get_player_by_id(clientid)) != NULL)
	{
		i = 0;
		while (i < 7)
		{
			if (!ft_strcmp(g_resnames[i], params))
			{
				if (g_map.cases[pl->x][pl->y].res[i] > 0)
				{
					g_map.cases[pl->x][pl->y].res[i] -= 1;
					pl->res[i] += 1;
					ok(pl->clientid, NULL);
				}
				else
					ko(pl->clientid);
				return (1);
			}
			i++;
		}
		return (ko(pl->clientid));
	}
	return (ko(pl->clientid));
}

int			exec_pose(int clientid, char *params)
{
	t_player	*pl;
	int			i;

	if ((pl = get_player_by_id(clientid)) != NULL)
	{
		i = 0;
		while (i < 7)
		{
			if (!ft_strcmp(g_resnames[i], params))
			{
				if (pl->res[i] > 0)
				{
					pl->res[i] -= 1;
					g_map.cases[pl->x][pl->y].res[i] += 1;
					ok(pl->clientid, NULL);
				}
				else
					ko(pl->clientid);
				return (1);
			}
			i++;
		}
		return (ko(pl->clientid));
	}
	return (ko(pl->clientid));
}
