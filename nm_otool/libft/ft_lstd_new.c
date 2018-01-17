/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstd_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 11:29:00 by fflorens          #+#    #+#             */
/*   Updated: 2017/03/14 10:58:26 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

t_lstd	*ft_lstd_new(void	const *content, size_t content_size)
{
	t_lstd *out;

	if ((out = (t_lstd *)malloc(sizeof(t_lstd))) == NULL)
		return (NULL);
	if (content)
	{
		out->content = ft_memalloc(content_size);
		if (out->content)
		{
			out->content = ft_memcpy(out->content, content, content_size);
			out->content_size = content_size;
		}
	}
	else
	{
		out->content = NULL;
		out->content_size = 0;
	}
	out->next = NULL;
	out->prev = NULL;
	return (out);
}
