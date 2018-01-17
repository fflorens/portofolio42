/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_truncate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 13:38:16 by bgauci            #+#    #+#             */
/*   Updated: 2014/06/17 14:59:23 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_truncate(char **s, char c)
{
	char	*begin;
	char	*end;

	if (!s || !(*s))
		return (NULL);
	if (ft_strchr(*s, c) == NULL)
		end = NULL;
	else
		end = ft_strdup(ft_strchr(*s, c) + 1);
	begin = ft_strsub(*s, 0, ft_strlen(*s) - ft_strlen(ft_strchr(*s, c)));
	free(*s);
	*s = begin;
	return (end);
}

char	*ft_fasttruncate(char **s, int s_len, char *tmp)
{
	char	*begin;
	char	*end;

	if (!s || !(*s))
		return (NULL);
	if (tmp == NULL)
		return (NULL);
	end = ft_strfastdup(tmp + 1, (*s + s_len - tmp));
	begin = ft_strfastsub(*s, 0, s_len - (*s + s_len - tmp), s_len);
	free(*s);
	*s = begin;
	return (end);
}
