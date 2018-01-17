/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 03:54:47 by fflorens          #+#    #+#             */
/*   Updated: 2014/02/23 06:17:56 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<lemin.h>
#include	<stdlib.h>

void		ft_strdel(char **as)
{
	if (as && *as)
	{
		free(*as);
		*as = NULL;
	}
}

void		ft_destroypaths(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst->next;
		ft_lstdestroy((t_list *)lst->data);
		free(lst);
		lst = tmp;
	}
}

t_room		*ft_destroy_room(t_room *room)
{
	t_link	*tmp;

	free(room->name);
	while (room->link)
	{
		tmp = room->link->next;
		free(room->link);
		room->link = tmp;
	}
	free(room);
	return (NULL);
}

t_map		*ft_destroy_map(t_map *map)
{
	t_list	*tmp;

	while (map->graph)
	{
		tmp = map->graph->next;
		ft_destroy_room(ROOM(map->graph->data));
		free(map->graph);
		map->graph = tmp;
	}
	free(map);
	return (NULL);
}

int			ft_lstdestroy(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
	return (0);
}

