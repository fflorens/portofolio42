/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 09:59:59 by bgauci            #+#    #+#             */
/*   Updated: 2013/12/22 19:38:43 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	char			*tmp;

	tmp = malloc(sizeof(char) * n);
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		tmp[i] = ((char *)s2)[i];
		i++;
	}
	while (--i)
		((char *)s1)[i] = tmp[i];
	((char *)s1)[i] = tmp[i];
	free(tmp);
	return (s1);
}
