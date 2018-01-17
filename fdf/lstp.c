/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 13:50:06 by fflorens          #+#    #+#             */
/*   Updated: 2013/12/22 18:56:29 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

t_lstp		*ft_new_lstp(t_2dp *point)
{
	t_lstp	*new;

	if ((new = (t_lstp *)malloc(sizeof(t_lstp))) == NULL)
		return (NULL);
	new->next = NULL;
	new->p = point;
	return (new);
}

void		ft_add_lstp(t_2dp *point, t_lstp *lst)
{
	t_lstp	*tmp;

	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_new_lstp(point);
}

int			ft_atoi(const char *s)
{
	int		sign;
	int		out;

	out = 0;
	sign = 1;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		sign = ((*s == '+') ? 1 : -1);
		s++;
	}
	while (ft_isdigit(*s))
	{
		out = out * 10 + (*s - '0');
		s++;
	}
	return (out * sign);
}

int			ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9'));
}

void		fdfdestroylst(t_lstp *lst)
{
	if (lst->next)
		fdfdestroylst(lst->next);
	free(lst->next);
	free(lst->p);
	lst->next = NULL;
	lst->p = NULL;
}
