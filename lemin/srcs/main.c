/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 03:52:12 by fflorens          #+#    #+#             */
/*   Updated: 2014/03/22 19:20:39 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		<stdlib.h>
#include		<unistd.h>
#include		<lemin.h>

static void		ft_not_so_simple_lemin(t_lemin *lemin)
{
	int			antsd;
	int			nants;
	t_list		*tmp;

	if (lemin->paths)
	{
		antsd = 0;
		nants = lemin->nants;
		while ((antsd < lemin->nants) && lemin->paths)
		{
			tmp = lemin->paths;
			while (tmp)
			{
				ft_move_rec(tmp->data, &antsd, &nants, lemin->nants);
				tmp = tmp->next;
			}
			ft_show_the_magic(NULL);
		}
	}
	else
		ft_error(E_NOSOL);
}

static void		ft_simple_lemin(t_lemin *lemin, t_list *tmp)
{
	int			i;

	if (tmp && !lemin->paths && (ft_lstlen(tmp) <= 2))
	{
		i = 0;
		while (++i <= lemin->nants)
		{
			ROOM(tmp->next->data)->n = i;
			ft_show_the_magic(tmp->next->data);
		}
		ft_show_the_magic(NULL);
	}
	else
		ft_not_so_simple_lemin(lemin);
}

static void		ft_recur_apply(t_list *lst, void (*f)(t_room *))
{
	if (!lst)
		return ;
	f(ROOM(lst->data));
	ft_recur_apply(lst->next, f);
}

static t_map	*ft_map_create(void)
{
	t_map		*new;

	new = (t_map *)ft_malloc_noerror(sizeof(t_map));
	new->graph = NULL;
	new->nnode = 0;
	new->nlink = 0;
	return (new);
}

int				main(void)
{
	t_lemin		lemin;
	t_list		*tmp;

	lemin.map = ft_map_create();
	ft_get_the_infos(&lemin);
	write(1, "\n", 1);
	lemin.paths = NULL;
	if (!(lemin.start = ft_find_room_flagged(lemin.map->graph, STATE_START)))
	{
		ft_error(E_NOSTART);
		ft_destroy_map(lemin.map);
		return (1);
	}
	ft_recur_apply(lemin.map->graph, ft_unset_state_pass);
	while ((tmp = ft_pathfinder(lemin.map, lemin.start))
			&& (ft_lstlen(tmp) > 2))
	{
		lemin.paths = ft_lstpushback(lemin.paths, tmp);
		ft_recur_apply(lemin.map->graph, ft_unset_state_pass);
		ft_recur_apply(tmp, ft_set_state_done);
	}
	ft_simple_lemin(&lemin, tmp);
	ft_destroypaths(lemin.paths);
	ft_destroy_map(lemin.map);
	return (0);
}
