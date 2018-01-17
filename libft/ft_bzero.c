/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:45:46 by fflorens          #+#    #+#             */
/*   Updated: 2013/11/27 14:39:25 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	size_t i;

	i = 0;
	if (s != NULL)
	{
		while (i < n)
		{
			*((char *)s + i) = 0;
			i++;
		}
	}
}
