/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 18:57:32 by bgauci            #+#    #+#             */
/*   Updated: 2014/06/24 19:14:32 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERFACE_H
# define INTERFACE_H

/*
** IA
*/

void	init(int nb_client, int x, int y);

void	ok(char *);
void	ko(void);
void	debut_elevation(void);
//void	new_tour(void);
void	dead(void);
void	broadcast(char *, int direction);

/*
** reseaux (thread a part)
*/

/*
** main reseau
*/
void	connect(char *addr, int port);

void	avance(void);
void	droite(void);
void	gauche(void);
void	voir(void);
void	inventaire(void);
void	prend(char *txt);
void	pose(char *txt);
void	expulse(void);
void	broadcast(char *txt);
void	incantation(void);
void	fork(void);
void	connect_nbr(void);

#endif
