/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listreq.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 18:35:14 by dbenoit           #+#    #+#             */
/*   Updated: 2014/06/09 18:35:19 by dbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include "server.h"
#include "libft.h"
#include <stdlib.h>

t_req		*request_new(int clientid, enum e_cmd cmd, char *params)
{
	t_req	*request;

	request = (t_req *)malloc(sizeof(t_req));
	request->clientid = clientid;
	request->cmd = cmd;
	request->params = ft_strdup(params);
	request->next = NULL;
	return (request);
}

void		request_add(t_req **list, t_req *item)
{
	t_req	*temp;

	if (!list || !item)
		return ;
	if (*list == NULL)
		*list = item;
	else
	{
		temp = *list;
		while (temp->next)
			temp = temp->next;
		temp->next = item;
	}
}

void		request_delete(t_req **list, t_req *item)
{
	t_req	*temp;

	if (!list || !item)
		return ;
	temp = *list;
	if (temp == item)
		*list = temp->next;
	else
	{
		while (temp->next != item)
			temp = temp->next;
		temp->next = item->next;
	}
	free(item->params);
	free(item);
}
