/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ressources.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 18:01:52 by dbenoit           #+#    #+#             */
/*   Updated: 2014/06/07 18:02:20 by dbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include "server.h"
#include "structs.h"
#include "libft.h"

static void	generate_random(int resnum, int num)
{
	int		*res;
	int		randx;
	int		randy;

	randx = rand() % g_map.width;
	randy = rand() % g_map.height;
	res = g_map.cases[randy][randx].res;
	if (resnum == FOOD)
		res[resnum] = imin(res[resnum] + num, 30);
	else
		res[resnum] = imin(res[resnum] + num, 10);
}

static void	generate_pattern1(int turn)
{
	int		i;
	int		j;
	int		*res;

	(void)turn;
	j = 0;
	while (j < g_map.height)
	{
		i = 0;
		while (i < g_map.width)
		{
			if (i % 2 == 0)
			{
				res = g_map.cases[j][i].res;
				res[FOOD] = imin(res[FOOD] + 2, 30);
				res[LINEMATE] = imin(res[LINEMATE] + 2, 10);
				res[DERAUMERE] = imin(res[DERAUMERE] + 1, 10);
			}
			i++;
		}
		j++;
	}
}

static void	generate_pattern2(int turn)
{
	int		i;
	int		j;
	int		*res;

	(void)turn;
	j = 0;
	while (j < g_map.height)
	{
		i = 0;
		while (i < g_map.width)
		{
			if (i % 2 == 1)
			{
				res = g_map.cases[j][i].res;
				res[SIBUR] = imin(res[SIBUR] + 2, 10);
				res[MENDIANE] = imin(res[MENDIANE] + 1, 10);
			}
			i++;
		}
		j++;
	}
}

static void	generate_pattern3(int turn)
{
	int		i;
	int		j;
	int		*res;

	(void)turn;
	j = g_map.height / 4;
	while (j < (3 * g_map.height / 4))
	{
		i = g_map.width / 4;
		while (i < (3 * g_map.width / 4))
		{
			if (i % 2 == 1)
			{
				res = g_map.cases[j][i].res;
				res[FOOD] = imin(res[FOOD] + 3, 30);
				res[LINEMATE] = imin(res[LINEMATE] + 2, 10);
				res[DERAUMERE] = imin(res[DERAUMERE] + 2, 10);
				res[PHIRAS] = imin(res[PHIRAS] + 2, 10);
				res[THYSTAME] = imin(res[THYSTAME] + 1, 10);
			}
			i++;
		}
		j++;
	}
}

int			generate_ressources(int pattern, int turn)
{
	(void)pattern;
	if (turn % 70 == 10)
		generate_pattern1(turn);
	if (turn % 190 == 90)
		generate_pattern2(turn);
	if (turn % 350 == 190)
		generate_pattern3(turn);
	if (turn % 1700 == 1699)
		generate_random(MENDIANE, 10);
	if (turn % 4000 == 3999)
		generate_random(THYSTAME, 5);
	return (1);
}
