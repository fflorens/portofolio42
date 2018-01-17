/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 17:45:55 by fflorens          #+#    #+#             */
/*   Updated: 2017/08/08 13:48:05 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;
	t_list *tmp2;

	if (alst && *alst)
	{
		tmp = *alst;
		while (tmp)
		{
			tmp2 = tmp->next;
			del(tmp->content, tmp->content_size);
			free(tmp);
			tmp = tmp2;
		}
		*alst = NULL;
	}
}
