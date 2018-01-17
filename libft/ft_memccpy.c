/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:56:28 by fflorens          #+#    #+#             */
/*   Updated: 2013/11/25 23:00:15 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		*((unsigned char *)s1 + i) = *((unsigned char *)s2 + i);
		if (*((unsigned char *)s1 + i) == (unsigned char)c)
		{
			return (((unsigned char *)s1 + i + 1));
		}
		i++;
	}
	return (NULL);
}
