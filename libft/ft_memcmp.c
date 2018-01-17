/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:38:20 by fflorens          #+#    #+#             */
/*   Updated: 2013/11/25 23:06:25 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;

	i = 0;
	if (s2 && s1)
	{
		while (i < n)
		{
			if (*((unsigned char*)s1 + i) != *((unsigned char*)s2 + i))
				return (*((unsigned char*)s1 + i) - *((unsigned char*)s2 + i));
			i++;
		}
	}
	return (0);
}
