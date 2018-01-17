/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:47:54 by fflorens          #+#    #+#             */
/*   Updated: 2017/03/14 10:55:43 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *out;

	out = (char *)s + ft_strlen(s);
	while (!(out < s))
	{
		if (*out == c)
			return (out);
		out--;
	}
	return (NULL);
}
