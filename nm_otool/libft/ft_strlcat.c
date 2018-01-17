/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:21:06 by fflorens          #+#    #+#             */
/*   Updated: 2017/03/14 10:54:41 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t ret;
	size_t i;
	size_t j;

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
	dst[i + j] = 0;
	return (ret);
}
