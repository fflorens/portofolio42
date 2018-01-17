/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zappy.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/31 18:28:06 by dbenoit           #+#    #+#             */
/*   Updated: 2014/05/31 18:28:48 by dbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZAPPY_H
# define ZAPPY_H

# define FOOD			0
# define LINEMATE		1
# define DERAUMERE		2
# define SIBUR			3
# define MENDIANE		4
# define PHIRAS			5
# define THYSTAME		6

typedef struct timeval	t_tval;

enum					e_cmd
{
	RIEN = 0,
	CONNECT = 1,
	AVANCE = 2,
	GAUCHE = 3,
	DROITE = 4,
	VOIR = 5,
	INVENTAIRE = 6,
	PREND = 7,
	POSE = 8,
	EXPULSE = 9,
	BROADCAST = 10,
	INCANTATION = 11,
	FORK = 12,
	CONNECTNBR = 13
};

#endif
