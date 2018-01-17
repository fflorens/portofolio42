/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 03:48:46 by fflorens          #+#    #+#             */
/*   Updated: 2014/02/23 15:16:48 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	<lemin.h>

t_room		*ft_getroom(t_list *lst, char *name)
{
	while (lst)
	{
		if (lst->data && !ft_strcmp(ROOM(lst->data)->name, name))
			return (lst->data);
		lst = lst->next;
	}
	return (NULL);
}

int			ft_roomexist(t_list *lst, char *name)
{
	if (ft_getroom(lst, name))
		return (1);
	return (0);
}

int			ft_existlink(t_link *link, t_room *room)
{
	while (link)
	{
		if (link->room == room)
			return (1);
		link = link->next;
	}
	return (0);
}

t_room		*ft_find_room_flagged(t_list *lst, unsigned int flag)
{
	while (lst)
	{
		if (ROOM(lst->data)->state & flag)
			return (lst->data);
		lst = lst->next;
	}
	return (NULL);
}
