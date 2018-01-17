/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlstmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 12:27:13 by bgauci            #+#    #+#             */
/*   Updated: 2013/12/22 19:49:26 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_strlist	*ft_strlstmap(t_strlist *lst, t_strlist *(*f)(t_strlist *elem))
{
	t_strlist	*res;
	t_strlist	*tmp;

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
