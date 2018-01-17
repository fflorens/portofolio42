/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfastdup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 17:24:17 by bgauci            #+#    #+#             */
/*   Updated: 2013/12/16 17:53:58 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline char	*ft_strfastdup(const char *s1, const int s1_len)
{
	char *res;

	if (!s1)
		return (NULL);
	res = ft_strfastnew(s1_len);
	if (res == 0)
		return (NULL);
	ft_strcpy(res, s1);
	return (res);
}
