/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:56:28 by fflorens          #+#    #+#             */
/*   Updated: 2017/08/08 13:48:44 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *s1, const void *s2, int c, register size_t n)
{
	register unsigned char			*t1;
	register unsigned const char	*t2;

	if (n)
	{
		t1 = s1;
		t2 = s2;
		while (n--)
			if ((*t1++ = *t2++) == (unsigned char)c)
				return (t1);
	}
	return (NULL);
}
