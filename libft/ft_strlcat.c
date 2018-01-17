/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:21:06 by fflorens          #+#    #+#             */
/*   Updated: 2013/11/27 15:41:07 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t ret;
	size_t i;
	size_t j;

	if (dst == NULL)
		return (0);
	i = ft_strlen(dst);
	if (i > size)
		return (size + ft_strlen(src));
	ret = i + ft_strlen(src);
	j = 0;
	while ((i + j) < (size - 1) && src[j] != '\0')
	{
		dst[i + j] = src[j];
		j++;
	}
	return (ret);
}
