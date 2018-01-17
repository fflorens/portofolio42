/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_serveur.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/21 23:09:04 by bgauci            #+#    #+#             */
/*   Updated: 2014/06/27 03:25:58 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reseau.h"
#include "write.h"
#include "stdio.h"
#include "libft.h"
#include "server.h"

void	fin_elevation(int id, int lvl)
{
	char		*res;

	res = ft_strjoin("niveau actuel : ", ft_itoa(lvl));
	ft_strjcat(&res, "\n");
	send_data(id, res);
	free(res);
}

void	expulser(int id, int direction)
{
	char		*res;

	res = ft_strjoin("expulser ", ft_itoa(direction));
	ft_strjcat(&res, "\n");
	send_data(id, res);
	free(res);
}

void	connecter_nbclient(int id, int slotsdispo)
{
	char		*res;

	res = ft_strjoin("connecter_nbclient ", ft_itoa(slotsdispo));
	ft_strjcat(&res, "\n");
	send_data(id, res);
	free(res);
}

void	connecter_taille_map(int id)
{
	char		*res;

	res = ft_strjoin("connecter_taille_map ", ft_itoa(g_map.width));
	res = ft_strjoin(res, " ");
	res = ft_strjoin(res, ft_itoa(g_map.height));
	ft_strjcat(&res, "\n");
	send_data(id, res);
	free(res);
}
