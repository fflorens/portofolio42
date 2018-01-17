/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_truncate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 13:38:16 by bgauci            #+#    #+#             */
/*   Updated: 2013/12/22 18:55:14 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "fdf.h"

char		*ft_truncate(char **s, int s_len, char *tmp)
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
