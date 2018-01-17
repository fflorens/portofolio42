/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/22 17:10:55 by bgauci            #+#    #+#             */
/*   Updated: 2014/06/26 17:35:58 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reseau.h"
#include "write.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"
#include <zproject.h>

#include <string>

using namespace std;

extern int g_sock;

void	snapshot(void)
{
	string t = "snapshot\n";
	write(g_sock, t.c_str(), t.length());
}

void	add_write(char	*txt)
{
	if (g_buff_write == NULL)
	{
		g_buff_write = strdup(txt);
		return ;
	}
	ft_strjcat(&(g_buff_write), txt);
}

void	write_fd(int fd)
{
	int		r;
	int		i;
	char	*tmp;

	if (fd == -1 || g_buff_write == NULL)
		return ;
	i = strlen(g_buff_write);
	if ((r = write(fd, g_buff_write, i)) == -1)
	{
		perror("write");
		fd = -1;
		return ;
	}
	if (r == (int)strlen(g_buff_write))
	{
		free(g_buff_write);
		g_buff_write = NULL;
		return ;
	}
	tmp = strsub(g_buff_write, 0, r);
	free(g_buff_write);
	g_buff_write = tmp;
}
