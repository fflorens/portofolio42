/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 03:48:46 by fflorens          #+#    #+#             */
/*   Updated: 2014/02/23 06:01:54 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	<lemin.h>

t_room		*ft_newroom(char *name, unsigned int state)
{
	t_room	*new;

	new = (t_room *)ft_malloc_noerror(sizeof(t_room));
	new->name = name;
	new->state = state;
	new->n = 0;
	new->link = NULL;
	return (new);
}

t_link		*ft_newlink(t_room *room, t_link *next)
{
	t_link	*new;

	new = (t_link *)ft_malloc_noerror(sizeof(t_link));
	new->room = room;
	new->next = next;
	return (new);
}
