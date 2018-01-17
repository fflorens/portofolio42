/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execsee.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 20:09:07 by dbenoit           #+#    #+#             */
/*   Updated: 2014/06/26 20:09:11 by dbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include "server.h"
#include "actions.h"
#include <math.h>
#include <stdio.h>

extern char	*g_resnames[7];

void		exec_voir_players(t_player *player, char **str, int x, int y)
{
	t_player	*temp;

	temp = g_players;
	while (temp)
	{
		if (temp != player && temp->x == x && temp->y == y)
			ft_strjcat(str, "joueur ");
		temp = temp->next;
	}
}

void		exec_voir_res(char **str, int x, int y)
{
	int		j;
	int		i;

	j = 0;
	while (j < 7)
	{
		i = g_map.cases[y][x].res[j];
		while (i > 0)
		{
			ft_strjcat(str, g_resnames[j]);
			ft_strjcat(str, " ");
			i--;
		}
		j++;
	}
	if ((*str)[ft_strlen(*str) - 1] == ' ')
	{
		(*str)[ft_strlen(*str) - 1] = ',';
		ft_strjcat(str, " ");
	}
}

void		exec_voir_row(t_player *player, char **str, int row)
{
	int		stx;
	int		sty;
	int		dx;
	int		dy;
	int		i;

	dx = -sin((float)player->angle / 180 * M_PI);
	dy = -cos((float)player->angle / 180 * M_PI);
	stx = (player->x - (row * dy) + (row * dx) + g_map.width) % g_map.width;
	sty = (player->y + (row * dy) + (row * dx) + g_map.height) % g_map.height;
	i = 0;
	while (i < (2 * row + 1))
	{
		exec_voir_players(player, str, stx, sty);
		exec_voir_res(str, stx, sty);
		stx = (stx - dx + g_map.width) % g_map.width;
		sty = (sty - dy + g_map.height) % g_map.height;
		i++;
	}
}

int			exec_voir(int clientid, char *params)
{
	t_player	*player;
	char		*str;
	int			i;

	(void)params;
	ft_putstr("exec_voir\n");
	str = NULL;
	if ((player = get_player_by_id(clientid)) != NULL)
	{
		ft_strjcat(&str, "{");
		i = 0;
		while (i <= player->level)
		{
			exec_voir_row(player, &str, i);
			i++;
		}
		if ((str)[ft_strlen(str) - 1] == ',')
			(str)[ft_strlen(str) - 1] = '}';
		else
			ft_strjcat(&str, "}");
		ok(player->clientid, str);
		free(str);
		return (1);
	}
	return (0);
}
