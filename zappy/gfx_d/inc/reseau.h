/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reseau.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/02 17:22:47 by bgauci            #+#    #+#             */
/*   Updated: 2014/06/20 16:54:22 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESEAU_H
# define RESEAU_H

# include "struct_reseau.h"
# include <sys/types.h>

extern int	g_sock;
extern char *g_buff_write;

void	init_reseau(int port);
int		create_server(int port);
int		fill_fd_set(fd_set *r, fd_set *w, fd_set *e, t_connexion **base);
void	*network(void *ptr);
void	serveur_new_client(fd_set *rfd, t_connexion **client);
void	serveur_read(fd_set *rfd, t_connexion *client);
void	serveur_write(fd_set *wfd, t_connexion *client);

#endif

