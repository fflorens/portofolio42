/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 03:52:26 by fflorens          #+#    #+#             */
/*   Updated: 2014/03/22 19:17:47 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		<unistd.h>
#include		<stdlib.h>
#include		<lemin.h>

static int		ft_atoi(char *s)
{
	int			sign;
	int			out;

	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (!(out = 0) && (sign = 1) && (*s == '-' || *s == '+'))
		sign = ((*s++ == '+') ? sign : -1);
	while (*s <= '9' && *s >= '0')
		out = out * 10 + (*s++ - '0');
	return (out * sign);
}

static t_map	*ft_addlink(t_map *mp, char *n1, char *n2)
{
	t_room		*r1;
	t_room		*r2;

	if (!(r1 = ft_getroom(mp->graph, n1)) || !(r2 = ft_getroom(mp->graph, n2)))
		ft_error(W_LINK_ERROR, W_LINK_ERROR1, n1, n2, W_LINK_ERROR2);
	else
	{
		if (!ft_existlink(r1->link, r2))
			r1->link = ft_newlink(r2, r1->link);
		else
			ft_error(W_LINK_EXIST, n1, n2, W_LINK_EXIST2);
		if (!ft_existlink(r2->link, r1))
			r2->link = ft_newlink(r1, r2->link);
		else
			ft_error(W_LINK_EXIST, n2, n1, W_LINK_EXIST2);
		mp->nlink++;
	}
	return (mp);
}

static t_map	*ft_addroom(t_map *mp, char *name, unsigned int s)
{
	if (!ft_roomexist(mp->graph, name))
	{
		mp->graph = ft_lstnewappend(ft_newroom(ft_strdup(name), s), mp->graph);
		mp->nnode++;
	}
	else
		ft_error(E_ROOM_EXIST, name);
	return (mp);
}

static void		ft_parse_it(char *line, t_lemin *lemin)
{
	char		*tmp;
	static int	state = 0;

	if (!ft_flexstrcmp(line, FLAG_START))
		state = STATE_START;
	else if (!ft_flexstrcmp(line, FLAG_END))
		state = STATE_END;
	else if (*line != COMMENT)
	{
		if ((tmp = ft_strchr(line, '-')))
		{
			*tmp = 0;
			ft_addlink(lemin->map, line, tmp + 1);
		}
		else
		{
			if ((tmp = ft_strchr(line, ' ')) || (tmp = ft_strchr(line, '\t')))
				*tmp = 0;
			ft_addroom(lemin->map, line, state);
		}
		state = 0;
	}
}

void			ft_get_the_infos(t_lemin *lemin)
{
	char		*line;
	char		*tmp;

	line = NULL;
	if (ft_gnl(0, &line))
	{
		ft_putendl(line);
		lemin->nants = ft_atoi(line);
		ft_strdel(&line);
	}
	while (ft_gnl(0, &line))
	{
		ft_putendl(line);
		tmp = line;
		while (*tmp && (*tmp == ' ' || *tmp == '\t'))
			tmp++;
		if (*tmp)
			ft_parse_it(tmp, lemin);
		ft_strdel(&line);
	}
		ft_strdel(&line);
}
