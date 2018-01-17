/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:03:15 by fflorens          #+#    #+#             */
/*   Updated: 2013/11/25 23:07:51 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char		*ft_strdup(const char *s1)
{
	int		i;
	char	*out;

	i = 2;
	while (s1[i - 2] != '\0')
		i++;
	out = (char *)malloc(sizeof(char) * (i - 1));
	if (out == NULL)
		return (NULL);
	while (--i >= 0)
		out[i] = s1[i];
	return (out);
}
