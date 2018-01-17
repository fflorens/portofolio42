/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:50:13 by fflorens          #+#    #+#             */
/*   Updated: 2013/11/25 23:05:47 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t i;

	i = 0;
	if (s)
	{
		while (i < n)
		{
			if (*((unsigned char *)s + i) == (unsigned char)c)
			{
				return ((unsigned char *)s + i);
			}
			i++;
		}
	}
	return (NULL);
}
