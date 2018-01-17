/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/22 17:30:06 by bgauci            #+#    #+#             */
/*   Updated: 2014/06/27 07:09:16 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reseau.h"
#include <unistd.h>
#include "read.h"
#include "libft.h"
#include "write.h"
#include "lst_connexion.h"
#include <stdio.h>
#include "server.h"
#include "zappy.h"

#define NB_COMMAND	12

extern t_connexion	*g_connexion;
static t_tab		g_tab[NB_COMMAND] =
{
	{"avance", AVANCE},
	{"gauche", GAUCHE},
	{"droite", DROITE},
	{"voir", VOIR},
	{"inventaire", INVENTAIRE},
	{"prend", PREND},
	{"pose", POSE},
	{"expulse", EXPULSE},
	{"broadcast", BROADCAST},
	{"incantation", INCANTATION},
	{"fork", FORK},
	{"connect_nbr", CONNECTNBR}
};

void	snapshot(void)
{
	t_connexion *tmp;
	char		*txt;
	char		*txt2;

	txt2 = strdup("snapshot ");
	txt = export_map();
	ft_strjcat(&txt2, txt);
	free(txt);
	ft_strjcat(&txt2, "\n");
	tmp = g_connexion;
	while (tmp)
	{
		if (tmp->type == IHM)
			add_write(txt2, tmp);
		tmp = tmp->next;
	}
	free(txt2);
}

void	exe_ihm(t_connexion *current)
{
	char	*line;
	char	*cmd;
	int		i;

	if (current->fd == -1)
		return ;
	while (can_exe(current))
	{
		cmd = current->buffer_read;
		current->buffer_read = ft_truncate(&cmd, '\n');
		line = ft_truncate(&cmd, ' ');
		i = 0;
		if (ft_strcmp(cmd, "snapshot") == 0)
			snapshot();
		free(line);
		free(cmd);
	}
}

void	exe(t_connexion *current)
{
	char	*line;
	char	*cmd;
	int		i;
	t_req	*req;

	if (current->fd == -1)
		return ;
	while (can_exe(current))
	{
		cmd = current->buffer_read;
		current->buffer_read = ft_truncate(&cmd, '\n');
		line = ft_truncate(&cmd, ' ');
		i = 0;
		while (i < NB_COMMAND && ft_strcmp(cmd, g_tab[i].name) != 0)
			i++;
		if (i < NB_COMMAND)
		{
			req = request_new(current->id, g_tab[i].cmd, line);
			request_add(&g_requests, req);
		}
		free(line);
		free(cmd);
	}
}

bool	can_exe(t_connexion *client)
{
	int	i;

	if (client->fd == -1)
		return (false);
	if (client->buffer_read == NULL)
		return (false);
	i = 0;
	while (client->buffer_read[i])
	{
		if (client->buffer_read[i] == '\n')
			return (true);
		i++;
	}
	return (false);
}

void	read_fd(t_connexion *client)
{
	int		r;
	char	buf[1024];

	if (client->fd == -1)
		return ;
	r = read(client->fd, buf, 1023);
	if (r <= 0)
	{
		if (r == 0)
			write(1, "un client est partis\n", 21);
		else
			ft_perror("read");
		client->fd = -1;
		player_delete_by_id(client->id);
		return ;
	}
	buf[r] = '\0';
	if (client->buffer_read == NULL)
	{
		client->buffer_read = ft_strdup(buf);
		return ;
	}
	ft_strjcat(&(client->buffer_read), buf);
}
