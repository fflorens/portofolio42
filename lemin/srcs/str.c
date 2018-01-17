/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 03:52:20 by fflorens          #+#    #+#             */
/*   Updated: 2014/02/23 15:17:04 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	<lemin.h>

int			ft_strlen(const char *s)
{
	if (!s || !*s)
		return (0);
	return (1 + ft_strlen((char *)(s + 1)));
}

int			ft_strcmp(const char *s1, const char *s2)
{
	if (!s1)
		return (-1);
	if (!s2)
		return (1);
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int			ft_flexstrcmp(char *line, char *s)
{
	if (!line || !s)
		return (1);
	while (*line && (*line == ' ' || *line == '\t'))
		line++;
	while (*line && (*line == *s))
	{
		line++;
		s++;
	}
	while (*line && (*line == ' ' || *line == '\t'))
		line++;
	return (*line - *s);
}

char		*ft_strdup(const char *s)
{
	char	*new;
	int		i;

	if (!s)
		return (NULL);
	new = ft_malloc_noerror(ft_strlen(s) + 1);
	i = -1;
	while (s[++i])
		new[i] = s[i];
	new[i] = 0;
	return (new);
}

char		*ft_strchr(char *s, char c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (NULL);
}
