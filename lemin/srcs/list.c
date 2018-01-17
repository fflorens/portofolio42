/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 03:52:07 by fflorens          #+#    #+#             */
/*   Updated: 2014/02/23 15:12:57 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		<stdlib.h>
#include		<lemin.h>

t_list			*ft_lstnewappend(void *data, t_list *next)
{
	t_list		*new;

	new = (t_list *)ft_malloc_noerror(sizeof(t_list));
	new->data = data;
	new->next = next;
	return (new);
}

t_list			*ft_lstpushback(t_list *lst, void *new)
{
	if (!lst)
		return (ft_lstnewappend(new, NULL));
	lst->next = ft_lstpushback(lst->next, new);
	return (lst);
}

unsigned int	ft_lstlen(t_list *lst)
{
	if (!lst)
		return (0);
	return (1 + ft_lstlen(lst->next));
}
