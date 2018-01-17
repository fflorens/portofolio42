/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   levelup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 18:24:07 by fflorens          #+#    #+#             */
/*   Updated: 2014/06/24 18:37:54 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		<string.h>

/*
** evolution tab {nb player, linemate, deraubere,sibur,mendiane,phiras,thystame}
*/

int				g_evol[8][8] = {{1, 1, 0, 0, 0, 0, 0},
								{2, 1, 1, 1, 0, 0, 0},
								{2, 2, 0, 1, 0, 2, 0},
								{4, 1, 1, 2, 0, 1, 0},
								{4, 1, 2, 1, 3, 0, 0},
								{6, 1, 2, 3, 0, 1, 0},
								{6, 2, 2, 2, 2, 2, 1}};

const char		*g_rs[6] = {"linemate", "deraubere", "sibur",
							"mendiane", "phiras", "thystame"};

const char		*get_ressource(int nb)
{
	return (g_rs[nb - 1]);
}

int				get_resnb(char *str)
{
	int			i;

	i = 0;
	while (i < 6 && strcmp(g_rs[i], str))
		i++;
	if (i == 6)
		return (-1);
	return (i + 1);
}
