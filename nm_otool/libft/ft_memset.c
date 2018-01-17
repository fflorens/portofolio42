/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 12:43:05 by fflorens          #+#    #+#             */
/*   Updated: 2017/08/08 13:48:56 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp;
	unsigned int	d;

	tmp = b;
	d = (unsigned char)c;
	d |= ((unsigned int)d << 8);
	d |= ((unsigned int)d << 16);
	while (len > sizeof(unsigned int))
	{
		*(unsigned int *)tmp = d;
		tmp += sizeof(unsigned int);
		len -= sizeof(unsigned int);
	}
	while (len--)
		*tmp++ = (unsigned char)d;
	return (b);
}
