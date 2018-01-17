/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/27 05:35:47 by dbenoit           #+#    #+#             */
/*   Updated: 2014/06/27 05:35:50 by dbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include "server.h"
#include "libft.h"
#include <stdlib.h>

int		player_delete_by_id(int clientid)
{
	t_player	*pl;

	if ((pl = get_player_by_id(clientid)) != NULL)
	{
		player_delete(&g_players, pl);
		return (1);
	}
	return (0);
}
