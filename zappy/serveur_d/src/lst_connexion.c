/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_connexion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 17:33:12 by bgauci            #+#    #+#             */
/*   Updated: 2014/06/26 16:25:55 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lst_connexion.h"
#include "libft.h"

t_connexion	*connexion_new(int fd)
{
	t_connexion	*res;
	static int	id = 1;

	res = malloc(sizeof(t_connexion));
	if (!res)
		return (NULL);
	res->fd = fd;
	res->buffer_read = NULL;
	res->buffer_write = NULL;
	res->type = NEW;
	res->dead = false;
	res->id = id++;
	res->next = NULL;
	return (res);
}

void		connexion_add(t_connexion **base, t_connexion *new)
{
	t_connexion	*tmp;

	if (base == NULL)
		return ;
	if (*base == NULL)
	{
		*base = new;
		return ;
	}
	tmp = *base;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

void		connexion_del(t_connexion **base, t_connexion *current)
{
	t_connexion	*tmp;

	tmp = *base;
	if (*base == current)
	{
		*base = (*base)->next;
		free(tmp->buffer_read);
		free(tmp->buffer_write);
		free(tmp);
	}
	while (tmp && tmp->next)
	{
		if (tmp && tmp->next == current)
		{
			ft_memdel((void **)&(tmp->next->buffer_read));
			ft_memdel((void **)&(tmp->next->buffer_write));
			tmp->next = tmp->next->next;
			ft_memdel((void **)&(current));
		}
		tmp = tmp->next;
	}
}
