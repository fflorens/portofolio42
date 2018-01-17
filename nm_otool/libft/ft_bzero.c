/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:45:46 by fflorens          #+#    #+#             */
/*   Updated: 2017/03/14 10:52:40 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	if (n)
	{
		while (n > sizeof(long long))
		{
			*(long long *)s = (long long)0;
			s += sizeof(long long);
			n -= sizeof(long long);
		}
		while (n > sizeof(int))
		{
			*(int *)s = (int)0;
			s += sizeof(int);
			n -= sizeof(int);
		}
		while (n--)
			*(char *)s++ = 0;
	}
}
