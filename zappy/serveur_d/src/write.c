/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/22 17:10:55 by bgauci            #+#    #+#             */
/*   Updated: 2014/06/27 05:35:21 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reseau.h"
#include "write.h"
#include "libft.h"
#include "server.h"
#include <unistd.h>
#include <stdio.h>

extern int			g_sock;
extern t_connexion	*g_connexion;

void	send_data(int id, char *txt)
{
	t_connexion *tmp;

	tmp = g_connexion;
	while (tmp)
	{
		if (tmp->id == id)
			add_write(txt, tmp);
		tmp = tmp->next;
	}
}

void	dead(int id)
{
	t_connexion *tmp;

	send_data(id, "mort\n");
	tmp = g_connexion;
	while (tmp)
	{
		if (tmp->id == id)
			tmp->dead = true;
		tmp = tmp->next;
	}
}

void	add_write(char	*txt, t_connexion *client)
{
	if (client->fd == -1)
		return ;
	if (client->buffer_write == NULL)
	{
		client->buffer_write = ft_strdup(txt);
		return ;
	}
	ft_strjcat(&(client->buffer_write), txt);
}

void	write_fd(t_connexion *client)
{
	int		r;
	int		i;
	char	*tmp;

	if (client->fd == -1)
		return ;
	if (client->buffer_write == NULL)
		return ;
	i = ft_strlen(client->buffer_write);
	if ((r = write(client->fd, client->buffer_write, i)) == -1 || client->dead)
	{
		if (client->dead)
			close(client->fd);
		else
			ft_perror("write");
		client->fd = -1;
		player_delete_by_id(client->id);
		return ;
	}
	if (r == (int)ft_strlen(client->buffer_write))
		tmp = NULL;
	else
		tmp = ft_strsub(client->buffer_write, 0, r);
	free(client->buffer_write);
	client->buffer_write = tmp;
}
