/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execinv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 20:11:27 by dbenoit           #+#    #+#             */
/*   Updated: 2014/06/26 20:11:32 by dbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include "server.h"
#include "actions.h"

void	exec_inv2(t_player *player, char **str)
{
	ft_strjcat(str, ", linemate ");
	ft_strjcat(str, ft_itoa(player->res[LINEMATE]));
	ft_strjcat(str, ", deraumere ");
	ft_strjcat(str, ft_itoa(player->res[DERAUMERE]));
	ft_strjcat(str, ", sibur ");
	ft_strjcat(str, ft_itoa(player->res[SIBUR]));
	ft_strjcat(str, ", mendiane ");
	ft_strjcat(str, ft_itoa(player->res[MENDIANE]));
	ft_strjcat(str, ", phiras ");
	ft_strjcat(str, ft_itoa(player->res[PHIRAS]));
	ft_strjcat(str, ", thystame ");
	ft_strjcat(str, ft_itoa(player->res[THYSTAME]));
	ft_strjcat(str, "}");
}

int		exec_inv(int clientid, char *params)
{
	t_player	*player;
	char		*str;

	(void)params;
	ft_putstr("exec_inv\n");
	str = NULL;
	if ((player = get_player_by_id(clientid)) != NULL)
	{
		ft_strjcat(&str, "{nourriture ");
		ft_strjcat(&str, ft_itoa(player->res[FOOD]));
		exec_inv2(player, &str);
		ok(player->clientid, str);
		return (1);
	}
	return (0);
}
