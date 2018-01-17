/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 13:00:10 by fflorens          #+#    #+#             */
/*   Updated: 2013/11/25 23:05:55 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char		*tmp;
	const char	*tmp2;

	if (n && s1 != s2)
	{
		tmp = s1;
		tmp2 = s2;
		if (s1 < s2)
			while (n--)
				*tmp++ = *tmp2++;
		else
		{
			tmp += n;
			tmp2 += n;
			while (n--)
				*--tmp = *--tmp2;
		}
	}
	return (s1);
}
