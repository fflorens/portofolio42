/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:03:15 by fflorens          #+#    #+#             */
/*   Updated: 2013/12/22 18:54:56 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "fdf.h"

char		*ft_strdup(const char *s1)
{
	int		i;
	char	*out;

	i = ft_strlen((char *)s1);
	out = ft_strnew(i);
	if (i)
	{
		while (i)
		{
			out[i - 1] = (char) s1[i - 1];
			i--;
		}
	}
	return (out);
}
