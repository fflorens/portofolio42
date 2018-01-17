/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 16:39:03 by bgauci            #+#    #+#             */
/*   Updated: 2014/05/16 17:24:57 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include "libft.h"

int			gnl(int const fd, char **line)
{
	return (get_next_line(fd, line));
}

int			get_next_line(int const fd, char **line)
{
	static t_static	*static_buff = NULL;
	int				r;

	if (!line || fd < 0)
		return (-1);
	*line = NULL;
	ft_upgrade(&static_buff, fd);
	if (static_buff->buff[fd] == NULL)
	{
		*line = ft_strnew(BUFF_SIZE + 1);
		r = read(fd, *line, BUFF_SIZE);
		if (r < 0)
			return (-1);
		if (r == 0)
			return (0);
	}
	else
		*line = static_buff->buff[fd];
	return (get_next_line2(&(static_buff->buff[fd]), line, fd));
}

static int	get_next_line2(char **buff, char **line, int fd)
{
	char	*tmp;
	char	*tmp3;
	int		r;

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

static void	ft_upgrade(t_static **static_buff, int const fd)
{
	int	i;

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

static void	ft_upgrade2(t_static **static_buff, int const fd)
{
	char	**tmp;
	int		i;

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
