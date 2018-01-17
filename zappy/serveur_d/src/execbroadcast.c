/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execbroadcast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 20:18:11 by dbenoit           #+#    #+#             */
/*   Updated: 2014/06/26 20:18:14 by dbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include "server.h"
#include "actions.h"

int		get_br_angle(int destx, int desty, int srcx, int srcy)
{
	int		minx;
	int		miny;

	minx = imin(abs(srcx - destx), g_map.width - abs(srcx - destx));
	miny = imin(abs(srcy - desty), g_map.height - abs(srcy - desty));
	if (minx > miny && srcx > destx)
		return (1);
	else if (minx > miny && srcx < destx)
		return (5);
	else if (minx < miny && srcy > desty)
		return (7);
	else if (minx < miny && srcy < desty)
		return (3);
	else if (minx == miny && srcx > destx && srcy > desty)
		return (8);
	else if (minx == miny && srcx > destx && srcy < desty)
		return (2);
	else if (minx == miny && srcx < destx && srcy > desty)
		return (4);
	else if (minx == miny && srcx < destx && srcy < desty)
		return (8);
	return (0);
}

int		get_br_num(t_player *dest, t_player *src)
{
	int		angle;
	int		destx;
	int		desty;

	destx = dest->x;
	if (abs(src->x - dest->x) > g_map.width - abs(src->x - dest->x))
		destx = dest->x - g_map.width;
	desty = dest->y;
	if (abs(src->y - dest->y) > g_map.height - abs(src->y - dest->y))
		desty = dest->y - g_map.height;
	angle = get_br_angle(destx, desty, src->x, src->y);
	angle = (angle - 1 + 8 - (int)((float)dest->angle / 360 * 4 * 2)) % 8 + 1;
	return (angle);
}

int		exec_broadcast(int clientid, char *params)
{
	t_player	*player;
	t_player	*temp;
	int			angle;

	ft_putstr("exec_broadcast\n");
	if ((player = get_player_by_id(clientid)) != NULL)
	{
		temp = g_players;
		while (temp)
		{
			if (temp != player)
			{
				if (temp->x == player->x && temp->y == player->y)
					broadcast(temp->clientid, params, 0);
				else
				{
					angle = get_br_num(temp, player);
					broadcast(temp->clientid, params, angle);
				}
			}
			temp = temp->next;
		}
		ok(player->clientid, NULL);
	}
	return (1);
}
