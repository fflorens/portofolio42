/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/21 21:41:29 by dbenoit           #+#    #+#             */
/*   Updated: 2014/06/21 21:41:33 by dbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include "server.h"

int		imin(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

int		imax(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int		ft_strxcat(char **str, char *add)
{
	static int		i = 0;
	int				j;

	if (!add)
	{
		i = 0;
		return (i);
	}
	j = 0;
	while (add[j])
	{
		(*str)[i] = add[j];
		i++;
		j++;
	}
	return (i);
}
