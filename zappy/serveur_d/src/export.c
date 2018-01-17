/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 20:58:58 by dbenoit           #+#    #+#             */
/*   Updated: 2014/06/26 20:59:02 by dbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include "server.h"
#include "reseau.h"
#include <stdlib.h>

void	export_map_player_infos(char **str, t_player *player)
{
	int		i;

	ft_strxcat(str, ft_itoa(player->clientid));
	ft_strxcat(str, ":");
	ft_strxcat(str, ft_itoa(player->x));
	ft_strxcat(str, ":");
	ft_strxcat(str, ft_itoa(player->y));
	ft_strxcat(str, ":");
	ft_strxcat(str, ft_itoa(player->angle));
	ft_strxcat(str, ":");
	ft_strxcat(str, ft_itoa(player->level));
	ft_strxcat(str, ":");
	i = 0;
	while (i < 7)
	{
		ft_strxcat(str, ft_itoa(player->res[i]));
		ft_strxcat(str, ":");
		i++;
	}
}

void	export_map_players(char **str)
{
	t_player	*temp;

	temp = g_players;
	if (!temp)
		return ;
	while (temp)
	{
		export_map_player_infos(str, temp);
		(*str)[ft_strlen(*str) - 1] = ',';
		temp = temp->next;
	}
}

void	export_map_cases(char **str)
{
	int		i;
	int		j;
	int		k;

	j = 0;
	while (j < g_map.height)
	{
		i = 0;
		while (i < g_map.width)
		{
			k = 0;
			while (k < 7)
			{
				ft_strxcat(str, ft_itoa(g_map.cases[j][i].res[k]));
				ft_strxcat(str, ":");
				k++;
			}
			(*str)[ft_strlen(*str) - 1] = ',';
			i++;
		}
		j++;
	}
	(*str)[ft_strlen(*str) - 1] = ';';
}

char	*export_map(void)
{
	char	*str;

	str = ft_strnew(34 * g_map.height * g_map.width + 1000);
	ft_strxcat(&str, ft_itoa(g_map.width));
	ft_strxcat(&str, ":");
	ft_strxcat(&str, ft_itoa(g_map.height));
	ft_strxcat(&str, ";");
	export_map_cases(&str);
	export_map_players(&str);
	str[ft_strlen(str) - 1] = '\0';
	ft_strxcat(NULL, NULL);
	return (str);
}
