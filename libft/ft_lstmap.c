/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 12:52:55 by fflorens          #+#    #+#             */
/*   Updated: 2013/11/27 15:39:08 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list *ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *out;
	t_list *tmp;

	if (!lst)
		return (NULL);
	out = f(lst);
	tmp = out;
	while (lst->next)
	{
		lst = lst->next;
		tmp->next = f(lst);
		tmp = tmp->next;
	}
	return (out);
}
