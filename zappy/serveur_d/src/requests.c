/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   requests.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 20:40:01 by dbenoit           #+#    #+#             */
/*   Updated: 2014/06/26 20:40:06 by dbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include "server.h"
#include "actions.h"
#include "stdlib.h"

int		delete_first_request(void)
{
	request_delete(&g_requests, g_requests);
	return (1);
}

int		process_first_request2(t_req *req)
{
	if (req->cmd == CONNECT)
		exec_connect(req->clientid, req->params);
	else if (req->cmd == PREND)
		chk_prend(req);
	else if (req->cmd == POSE)
		chk_pose(req);
	else if (req->cmd == EXPULSE)
		chk_expulse(req);
	else if (req->cmd == INCANTATION)
		exec_start_inc(req->clientid, "");
	else
		return (0);
	return (1);
}

int		process_first_request(void)
{
	t_req	*temp;

	temp = g_requests;
	if ((int)temp->cmd >= 0 && (int)temp->cmd < 14)
	{
		if (player_has_action_by_id(temp->clientid))
			return (ko(temp->clientid));
		if (temp->cmd != PREND && temp->cmd != POSE && temp->cmd != EXPULSE
			&& temp->cmd != CONNECT && temp->cmd != INCANTATION)
			set_player_action(temp->clientid, temp->cmd, temp->params);
		else if (process_first_request2(temp))
			;
		else
			return (0);
	}
	else
		return (0);
	return (1);
}

int		process_actions_requests(void)
{
	if (!g_requests)
		return (1);
	while (g_requests)
	{
		process_first_request();
		delete_first_request();
	}
	return (1);
}
