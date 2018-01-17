/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 16:49:18 by fflorens          #+#    #+#             */
/*   Updated: 2017/03/14 10:58:47 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

t_list	*ft_lstnew(void	const *content, size_t content_size)
{
	t_list *out;

	if ((out = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content)
	{
		if ((out->content = malloc(content_size)) != NULL)
		{
			ft_memcpy(out->content, content, content_size);
			out->content_size = content_size;
			out->next = NULL;
			return (out);
		}
		free(out);
		return (NULL);
	}
	out->content = NULL;
	out->content_size = 0;
	out->next = NULL;
	return (out);
}
