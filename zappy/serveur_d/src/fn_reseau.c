/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_reseau.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 15:51:38 by bgauci            #+#    #+#             */
/*   Updated: 2014/06/27 05:06:02 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "reseau.h"
#include <netinet/in.h>
#include <sys/socket.h>
#include "lst_connexion.h"
#include <stdio.h>
#include "write.h"
#include "read.h"
#include "libft.h"
#include "server.h"

void	serveur_new_client(fd_set *rfd, t_connexion **base)
{
	int					new_fd;
	struct sockaddr_in	csin;
	unsigned int		cslen;
	t_connexion			*connexion;

	if (g_sock < 0 || !FD_ISSET(g_sock, rfd))
		return ;
	new_fd = accept(g_sock, (struct sockaddr*)&csin, &cslen);
	connexion = connexion_new(new_fd);
	connexion_add(base, connexion);
	add_write("BONJOUR\n", connexion);
}

void	new_client(t_connexion *client)
{
	t_req	*req;

	if (can_exe(client))
	{
		if (ft_strcmp(client->buffer_read, "IHM\n") == 0)
		{
			client->type = IHM;
			free(client->buffer_read);
			client->buffer_read = NULL;
			snapshot();
		}
		else
		{
			client->type = IA;
			client->buffer_read[ft_strlen(client->buffer_read) - 1] = '\0';
			req = request_new(client->id, CONNECT, client->buffer_read);
			free(client->buffer_read);
			client->buffer_read = NULL;
			request_add(&g_requests, req);
		}
	}
}

void	serveur_read(fd_set *rfd, t_connexion *client)
{
	while (client)
	{
		if (client->fd != -1 && FD_ISSET(client->fd, rfd))
		{
			read_fd(client);
			if (client->type == IA)
				exe(client);
			else if (client->type == IHM)
				exe_ihm(client);
			else
				new_client(client);
		}
		client = client->next;
	}
}

void	serveur_write(fd_set *wfd, t_connexion *client)
{
	while (client)
	{
		if (client->fd != -1 && FD_ISSET(client->fd, wfd))
			write_fd(client);
		client = client->next;
	}
}
