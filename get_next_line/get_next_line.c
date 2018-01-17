/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 16:55:46 by fflorens          #+#    #+#             */
/*   Updated: 2015/02/06 16:56:40 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

static char		g_gnlbuf[BUFF_SIZE + 1] = {0};
static int		g_gnli = 0;

static int		ft_strlen(char const *str)
{
	int			i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

static char		*ft_strxjoin(char const *s1, char const *s2)
{
	int			s1_len;
	int			s2_len;
	char		*str;

	if ((str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)) == NULL)
		return (NULL);
	s1_len = -1;
	while (s1[++s1_len])
		str[s1_len] = s1[s1_len];
	s2_len = -1;
	while (s2[++s2_len])
		str[s1_len + s2_len] = s2[s2_len];
	str[s1_len + s2_len] = 0;
	free((void *)s1);
	free((void *)s2);
	return (str);
}

static int		complete_line(int const fd, char **line)
{
	int			ret;
	char		*new_line;

	new_line = NULL;
	ret = get_next_line(fd, &new_line);
	if (new_line != NULL)
		*line = ft_strxjoin(*line, new_line);
	return (ret);
}

int				get_next_line(int const fd, char **line)
{
	int			j;

	if (line == NULL)
		return (-1);
	*line = 0;
	if (!g_gnlbuf[g_gnli])
	{
		g_gnlbuf[0] = 0;
		if ((g_gnli = read(fd, g_gnlbuf, BUFF_SIZE)) <= 0)
			return (g_gnli);
		g_gnlbuf[g_gnli] = 0;
		g_gnli = 0;
	}
	if ((*line = (char *)malloc(BUFF_SIZE + 1)) == NULL)
		return (-1);
	j = 0;
	while (g_gnlbuf[g_gnli] && g_gnlbuf[g_gnli] != '\n' && j < BUFF_SIZE)
		(*line)[j++] = g_gnlbuf[g_gnli++];
	(*line)[j] = 0;
	if (g_gnlbuf[g_gnli] == '\n')
		++g_gnli;
	else
		return (complete_line(fd, line));
	return (1);
}
