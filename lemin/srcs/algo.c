/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 03:49:41 by fflorens          #+#    #+#             */
/*   Updated: 2014/02/23 06:23:45 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <lemin.h>

static int		ft_islinked(t_room *room, t_link *link)
{
	while (link)
	{
		if ((link->room->state & STATE_PASSED) && (link->room == room))
			return (1);
		link = link->next;
	}
	return (0);
}

static t_list	*ft_findbackway(t_map *map, t_room *end, t_list *save)
{
	t_room		*room;
	t_list		*tmp;

	if (!end)
		return (NULL);
	tmp = save;
	while (tmp)
	{
		if (ft_islinked(tmp->data, end->link))
		{
			room = tmp->data;
			ft_lstdestroy(tmp->next);
			tmp->next = NULL;
			if (room->state & STATE_START)
			{
				ft_lstdestroy(save);
				return (ft_lstnewappend(room, ft_lstnewappend(end, NULL)));
			}
			return (ft_lstpushback(ft_findbackway(map, room, save), end));
		}
		tmp = tmp->next;
	}
	return (NULL);
}

static t_link	*ft_linklooping(t_link *lnk, t_list *path)
{
	if (!(lnk->room->state & (STATE_PASSED | STATE_OK)))
	{
		ft_set_state_pass(lnk->room);
		path = ft_lstpushback(path, lnk->room);
	}
	return (lnk->next);
}

t_list			*ft_pathfinder(t_map *map, t_room *start)
{
	t_list		*path;
	t_list		*tmp;
	t_link		*l;
	t_list		*sv;

	ft_set_state_pass(start);
	path = ft_lstpushback(NULL, start);
	sv = NULL;
	while (path)
	{
		tmp = path;
		l = ROOM(tmp->data)->link;
		sv = ft_lstpushback(sv, tmp->data);
		while (l && l->room)
		{
			if (l->room->state & STATE_END)
				return (ft_lstdestroy(tmp) + ft_findbackway(map, l->room, sv));
			l = ft_linklooping(l, tmp);
		}
		tmp = path->next;
		free(path);
		path = tmp;
	}
	tmp = (t_list *)NULL + ((ft_lstdestroy(path) + ft_lstdestroy(sv)));
	return (NULL);
}
