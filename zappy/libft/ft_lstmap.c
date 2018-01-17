/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 13:39:06 by bgauci            #+#    #+#             */
/*   Updated: 2013/12/22 19:27:46 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	res = f(lst);
	lst = lst->next;
	tmp = res;
	while (lst != NULL)
	{
		tmp->next = f(lst);
		if (!(tmp->next))
			return (NULL);
		lst = lst->next;
		tmp = tmp->next;
	}
	return (res);
}
