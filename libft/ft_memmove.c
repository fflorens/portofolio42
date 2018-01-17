/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 13:37:50 by fflorens          #+#    #+#             */
/*   Updated: 2013/11/27 16:23:20 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <libft.h>

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	void *s3;

	s3 = ft_memalloc(n);
	ft_memcpy(s3, s2, n);
	ft_memcpy(s1, s3, n);
	free(s3);
	s3 = NULL;
	return (s1);
}
