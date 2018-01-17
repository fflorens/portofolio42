/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 12:43:05 by fflorens          #+#    #+#             */
/*   Updated: 2017/03/14 10:58:36 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

void	*ft_memalloc(size_t size)
{
	char *out;

	if (size)
		out = malloc(size);
	else
		out = NULL;
	if (out)
		ft_bzero(out, size);
	return (out);
}
