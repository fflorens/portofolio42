/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfastsub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 17:24:28 by bgauci            #+#    #+#             */
/*   Updated: 2013/12/16 17:56:40 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline char	*ft_strfastsub	(char *s, size_t start, size_t len, size_t s_len)
{
	unsigned int	i;
	char			*res;

	if (!s)
		return (NULL);
	if (s_len < start + len)
	{
		res = ft_strnew(0);
		return (res);
	}
	res = ft_strnew(len + 1);
	i = 0;
	while (i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	return (res);
}
