/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:44:03 by bgauci            #+#    #+#             */
/*   Updated: 2013/12/22 19:50:54 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	j;
	int				bol;

	i = 0;
	while (s1[i] != '\0' && i < n)
	{
		j = 0;
		bol = 0;
		while (s2[j] != '\0' && bol == 0 && (i + j) < n)
		{
			if (s1[i + j] != s2[j])
				bol = 1;
			j++;
		}
		if (s2[j] == '\0' && bol == 0)
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}
