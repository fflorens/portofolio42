/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 10:19:22 by bgauci            #+#    #+#             */
/*   Updated: 2014/01/06 12:40:53 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*res;

	if (!s1)
		return (NULL);
	res = ft_strnew(ft_strlen(s1));
	if (res == 0)
		return (NULL);
	ft_strcpy(res, s1);
	return (res);
}

char	*ft_strndup(const char *s1, int nb)
{
	char	*res;
	int		len_res;

	if (!s1)
		return (NULL);
	len_res = ft_strlen(s1);
	len_res = ((len_res > nb) ? nb : len_res);
	res = ft_strnew(len_res);
	if (res == 0)
		return (NULL);
	ft_strncpy(res, s1, len_res);
	return (res);
}
