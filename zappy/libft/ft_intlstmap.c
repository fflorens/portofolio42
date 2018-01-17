/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlstmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 13:44:25 by bgauci            #+#    #+#             */
/*   Updated: 2013/12/29 13:44:27 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_intlist	*ft_intlstmap(t_intlist *lst, t_intlist *(*f)(t_intlist *elem))
{
	t_intlist	*res;
	t_intlist	*tmp;

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
