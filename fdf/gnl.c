/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 18:52:40 by fflorens          #+#    #+#             */
/*   Updated: 2013/12/22 18:59:40 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "fdf.h"
#include "gnl.h"

int					gnl(int const fd, char **line)
{
	static t_static	*static_buff = NULL;
	int				r;

	if (!line || fd < 0)
		return (-1);
	if (*line)
	{
		free(*line);
		*line = NULL;
	}
	ft_upgrade(&static_buff, fd);
	if (static_buff->buff[fd] == NULL)
	{
		*line = ft_strnew(BUFF_SIZE);
		r = read(fd, *line, BUFF_SIZE);
		if (r < 0)
			return (-1);
		if (r == 0)
			return (0);
	}
	else
		*line = static_buff->buff[fd];
	return (gnl2(&(static_buff->buff[fd]), line, fd));
}

int				gnl2(char **buff, char **line, int fd)
{
	char		*tmp;
	char		*tmp3;
	int			r;

	tmp = ft_strnew(1);
	r = 1;
	while (r != 0)
	{
		tmp3 = *line;
		*line = ft_strjoin(tmp3, tmp);
		free(tmp3);
		free(tmp);
		if (ft_strchr(*line, '\n') != NULL)
		{
			if ((*buff = ft_truncate(line, '\n')) == NULL)
				return (-1);
			return (1);
		}
		tmp = ft_strnew(BUFF_SIZE + 1);
		if ((r = read(fd, tmp, BUFF_SIZE)) < 0)
			return (-1);
	}
	free(tmp);
	*buff = NULL;
	return (1);
}

void			ft_upgrade(t_static **static_buff, int const fd)
{
	int			i;

	i = -1;
	if (!static_buff)
		return ;
	if (*static_buff == NULL)
	{
		*static_buff = malloc(sizeof(t_static));
		if (*static_buff == NULL)
			return ;
		(*static_buff)->nb_buff = fd;
		(*static_buff)->buff = malloc(sizeof(char *) * fd + 1);
		if ((*static_buff)->buff == NULL)
			return ;
		while (++i < fd + 1)
			(*static_buff)->buff[i] = NULL;
		return ;
	}
	if ((*static_buff)->nb_buff < fd)
		ft_upgrade2(static_buff, fd);
}

void			ft_upgrade2(t_static **static_buff, int const fd)
{
	char		**tmp;
	int			i;

	i = -1;
	tmp = malloc(sizeof(char*) * fd + 1);
	while (++i <= (*static_buff)->nb_buff)
		tmp[i] = (*static_buff)->buff[i];
	while (i < fd + 1)
	{
		tmp[i] = NULL;
		i++;
	}
	free((*static_buff)->buff);
	(*static_buff)->buff = tmp;
	(*static_buff)->nb_buff = fd;
}

char			*ft_truncate(char **s, char c)
{
	char		*begin;
	char		*end;

	if (!s || !(*s))
		return (NULL);
	if (ft_strchr(*s, c) == NULL)
		return (NULL);
	end = ft_strdup(ft_strchr(*s, c) + 1);
	begin = ft_strsub(*s, 0, ft_strlen(*s) - ft_strlen(ft_strchr(*s, c)));
	free(*s);
	*s = begin;
	return (end);
}
