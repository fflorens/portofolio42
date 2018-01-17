/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 16:49:18 by fflorens          #+#    #+#             */
/*   Updated: 2013/11/27 15:39:13 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

t_list *ft_lstnew(void	const *content, size_t content_size)
{
	t_list *out;

	if ((out = (t_list *)malloc(sizeof(t_list))) == NULL)
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
	return (out);
}
