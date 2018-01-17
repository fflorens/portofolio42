/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   requestsfunctions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 23:24:05 by dbenoit           #+#    #+#             */
/*   Updated: 2014/06/09 23:24:09 by dbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include "server.h"

int		chk_connect(t_req *request)
{
	(void)request;
	return (1);
}

int		chk_prend(t_req *request)
{
	set_player_action(request->clientid, request->cmd, request->params);
	return (1);
}

int		chk_pose(t_req *request)
{
	set_player_action(request->clientid, request->cmd, request->params);
	return (1);
}

int		chk_expulse(t_req *request)
{
	set_player_action(request->clientid, request->cmd, request->params);
	return (1);
}
