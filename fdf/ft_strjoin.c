/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 18:31:41 by fflorens          #+#    #+#             */
/*   Updated: 2013/12/22 18:55:00 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"
#include "fdf.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;

	if (s1 == NULL && s2)
		out = ft_strdup(s2);
	else if (s2 == NULL && s1)
		out = ft_strdup(s1);
	else if (s2 == NULL && s1 == NULL)
		return (NULL);
	else
	{
		out = ft_strnew(ft_strlen((char *)s1) + ft_strlen((char *)s2));
		if (out)
		{
			out = ft_strcat(out, s1);
			out = ft_strcat(out, s2);
		}
	}
	return (out);
}
