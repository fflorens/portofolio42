/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 17:21:49 by fflorens          #+#    #+#             */
/*   Updated: 2014/03/22 19:18:06 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include			<unistd.h>
#include			<stdlib.h>
#include			<lemin.h>

static int			gnl_strlen(char *s)
{
	if (!s || !*s)
		return (0);
	return (1 + gnl_strlen(s + 1));
}

static char			*gnl_strjoin(char *s1, char *s2)
{
	int				i;
	int				j;
	int				k;
	char			*out;

	i = gnl_strlen(s1);
	j = gnl_strlen(s2);
	k = 0;
	out = (char *)malloc(i + j + 1);
	while (*s1)
	{
		out[k] = *s1;
		k++;
		s1++;
	}
	while (*s2)
	{
		out[k] = *s2;
		k++;
		s2++;
	}
	out[k] = 0;
	return (out);
}

static int			gnl_end_line(const int fd, char **line)
{
	int				out;
	char			*eol;
	char			*tmp;

	eol = NULL;
	out = ft_gnl(fd, &eol);
	if (eol)
	{
		tmp = gnl_strjoin(*line, eol);
		ft_strdel(line);
		ft_strdel(&eol);
		*line = tmp;
		tmp = NULL;
	}
	return (out);
}

static char			*gnl_alloc(char **ptr)
{
	char			*buffer;

	if (ptr)
	{
		ft_strdel(ptr);
		return (NULL);
	}
	buffer = (char *)malloc(BUFF_SIZE + 1);
	if (!buffer)
		return (NULL);
	buffer[0] = 0;
	return (buffer);
}

int					ft_gnl(const int fd, char **line)
{
	static t_gnl	cbuff = {0, 0};
	int				j;

	cbuff.buffer = ((cbuff.buffer) ? cbuff.buffer : gnl_alloc(NULL));
	if (fd < 0 || !BUFF_SIZE || !line || !cbuff.buffer)
		return (-1);
	if (!cbuff.buffer[cbuff.i])
	{
		cbuff.i = 0;
		j = read(fd, cbuff.buffer, BUFF_SIZE);
		if (j <= 0 && !gnl_alloc(&(cbuff.buffer)))
			return (j);
		cbuff.buffer[j] = 0;
	}
	if (!(*line = (char *)malloc(BUFF_SIZE - cbuff.i + 1)))
		return (-1);
	j = 0;
	while (cbuff.buffer[cbuff.i] && cbuff.buffer[cbuff.i] != '\n')
		(*line)[j++] = cbuff.buffer[(cbuff.i)++];
	(*line)[j] = 0;
	if (cbuff.buffer[cbuff.i] == '\n')
		(cbuff.i)++;
	else
		return (gnl_end_line(fd, line));
	return (1);
}
