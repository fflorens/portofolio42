/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reseau.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/02 17:22:47 by bgauci            #+#    #+#             */
/*   Updated: 2014/06/24 22:43:24 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESEAU_H
# define RESEAU_H

# include "structs.h"
# include "struct_reseau.h"
# include <stdbool.h>
# include <sys/types.h>

extern int	g_sock;

int		ko(int id);
int		ok(int id, char *txt);
void	co_nbr(int id, int nb);
void	dead(int id);
void	broadcast(int id, char *txt, int direction);
void	debut_elevation(int id);
void	fin_elevation(int id, int lvl);
void	expulser(int id, int direction);
void	connecter_nbclient(int id, int slotsdispo);
void	connecter_taille_map(int id);

void	init_reseau(int port);
int		create_server(int port);
int		fill_fd_set(fd_set *r, fd_set *w, fd_set *e, t_connexion **base);
void	do_select(double time);
void	serveur_new_client(fd_set *rfd, t_connexion **client);
void	serveur_read(fd_set *rfd, t_connexion *client);
void	serveur_write(fd_set *wfd, t_connexion *client);

#endif

