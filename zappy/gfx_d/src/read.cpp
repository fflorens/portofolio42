/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/22 17:30:06 by bgauci            #+#    #+#             */
/*   Updated: 2014/06/26 22:27:02 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reseau.h"
#include <unistd.h>
#include "read.h"
#include "write.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"
#include "fn.h"

#include <string>

using namespace std;

#define NB_COMMAND	1

static t_tab	g_tab[NB_COMMAND] =
{
	{"snapshot", snapshot}
};

void	snapshot(char *txt)
{
	if (!txt)
		return ;
	rcp_map(txt);
}

void	exe(char **buff)
{
	char	*line;
	char	*cmd;
	int		i;

	while (can_exe(*buff))
	{
		cmd = *buff;
		*buff = ft_truncate(&cmd, '\n');
		line = ft_truncate(&cmd, ' ');
		i = 0;
		while (i < NB_COMMAND && strcmp(cmd, g_tab[i].name) != 0)
			i++;
		if (i < NB_COMMAND)
			g_tab[i].fn(line);
		if (line)
			free(line);
		if (cmd)
			free(cmd);
	}
}

bool	can_exe(char *buff)
{
	int	i;

	if (buff == NULL)
		return (false);
	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (true);
		i++;
	}
	return (false);
}

void	read_fd(int fd)
{
	int			r;
	char		buf[1024];
	static char	*buffer = NULL;

	if (fd == -1)
		return ;
	r = read(fd, buf, 1023);
	buf[r] = '\0';
	if (r <= 0)
	{
		if (r == 0)
		{
			printf("La connexion est perdue\n");
			exit(0);
		}
		else
		{
			perror("Read");
			exit(0);
		}
		return ;
	}
	buf[r] = '\0';
	if (buffer == NULL)
		buffer = strdup(buf);
	else 
		ft_strjcat(&(buffer), buf);
	exe(&buffer);
}
