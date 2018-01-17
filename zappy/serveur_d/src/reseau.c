/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reseau.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 16:08:53 by bgauci            #+#    #+#             */
/*   Updated: 2014/06/25 20:56:46 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reseau.h"
#include "server.h"
#include <netdb.h>
#include <netinet/in.h>
#include "libft.h"
#include <sys/select.h>

#define R	0
#define W	1
#define E	2

int			g_sock = -1;
t_connexion	*g_connexion = NULL;

int		create_server(int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;

	if ((proto = getprotobyname("tcp")) == 0)
		exit_perror("getprotobyname", -1);
	if ((sock = socket(PF_INET, SOCK_STREAM, proto->p_proto)) < 0)
		exit_perror("socket", -1);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sock, (const struct sockaddr *)&sin, sizeof(sin)) < 0)
		exit_perror("bind", -1);
	if (listen(sock, 42) < 0)
		exit_perror("listen", -1);
	return (sock);
}

int		fill_fd_set(fd_set *r, fd_set *w, fd_set *e, t_connexion **base)
{
	t_connexion	*connexion;
	int			ndfs;

	FD_ZERO(r);
	FD_ZERO(w);
	FD_ZERO(e);
	ndfs = g_sock;
	FD_SET(g_sock, r);
	connexion = *base;
	while (connexion)
	{
		ndfs = ((ndfs < connexion->fd) ? connexion->fd : ndfs);
		if (connexion->fd != -1)
			FD_SET(connexion->fd, r);
		if (connexion->fd != -1 && connexion->buffer_write)
			FD_SET(connexion->fd, w);
		connexion = connexion->next;
	}
	return (ndfs + 1);
}

void	init_reseau(int port)
{
	signal(SIGPIPE, SIG_IGN);
	g_sock = create_server(port);
}

void	do_select(double time)
{
	static fd_set		fd_read;
	static fd_set		fd_write;
	static fd_set		fd_exep;
	int					ndfs;

	ndfs = fill_fd_set(&fd_read, &fd_write, &fd_exep, &g_connexion);
	select(ndfs, &fd_read, &fd_write, &fd_exep, generate_timeval(time));
	serveur_new_client(&fd_read, &g_connexion);
	serveur_read(&fd_read, g_connexion);
	serveur_write(&fd_write, g_connexion);
}
