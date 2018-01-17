/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_serveur2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 21:04:03 by bgauci            #+#    #+#             */
/*   Updated: 2014/06/27 05:06:11 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reseau.h"
#include "write.h"
#include "stdio.h"
#include "libft.h"
#include "server.h"

int		ko(int id)
{
	send_data(id, "ko\n");
	return (0);
}

int		ok(int id, char *txt)
{
	char		*res;

	res = ft_strjoin("ok ", txt);
	ft_strjcat(&res, "\n");
	send_data(id, res);
	free(res);
	return (1);
}

void	broadcast(int id, char *txt, int direction)
{
	char		*res;

	res = ft_strjoin("message ", ft_itoa(direction));
	ft_strjcat(&res, ", ");
	ft_strjcat(&res, txt);
	ft_strjcat(&res, "\n");
	send_data(id, res);
	free(res);
}

void	debut_elevation(int id)
{
	send_data(id, "elevation en cours\n");
}

void	co_nbr(int id, int nb)
{
	char		*res;

	res = ft_strjoin("connect_nbr ", ft_itoa(nb));
	ft_strjcat(&res, "\n");
	send_data(id, res);
	free(res);
}
