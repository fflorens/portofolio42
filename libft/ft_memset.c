/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 12:43:05 by fflorens          #+#    #+#             */
/*   Updated: 2013/11/27 15:37:31 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t i;

	i = 0;
	if (b)
	{
		while (i < len)
		{
			*((unsigned char *)b + i) = (unsigned char)c;
			i++;
		}
	}
	return (b);
}
