/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_truncate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 13:38:16 by bgauci            #+#    #+#             */
/*   Updated: 2014/06/25 14:41:48 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

int		ft_strlen(char *s)
{
	if (!s)
		return (0);
	else
		return (strlen(s));
}

char	*ft_truncate(char **s, char c)
{
	char	*begin;
	char	*end;

	if (!s || !(*s))
		return (NULL);
	if (strchr(*s, c) == NULL)
		end = NULL;
	else
		end = strdup(strchr(*s, c) + 1);
	begin = strsub(*s, 0, ft_strlen(*s) - ft_strlen(strchr(*s, c)));
	free(*s);
	*s = begin;
	return (end);
}
