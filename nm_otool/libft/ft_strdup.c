/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:03:15 by fflorens          #+#    #+#             */
/*   Updated: 2017/08/08 13:49:21 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*out;
	char	*tmp;

	tmp = (char *)s1;
	while (*tmp++)
		;
	out = (char *)malloc(sizeof(char) * (tmp - s1));
	if (out == NULL)
		return (NULL);
	tmp = out;
	while (*s1)
		*tmp++ = *s1++;
	*tmp = 0;
	return (out);
}

char		*ft_strndup(const char *s1, size_t n)
{
	char	*out;
	size_t	len;

	len = ft_strnlen(s1, n);
	if ((out = malloc(len + 1)) == NULL)
		return (NULL);
	out[0] = 0;
	return (ft_strncat(out, s1, len));
}
