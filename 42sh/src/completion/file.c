/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzak <jzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 00:29:45 by jzak              #+#    #+#             */
/*   Updated: 2014/03/27 21:43:56 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include "libft.h"
#include "dynbuf.h"
#include "completion.h"

static char			*get_path(const char *path, size_t n)
{
	size_t	i;
	char	*dir;

	dir = ft_strdup(path);
	i = 0;
	while (i < n)
	{
		if (dir[i] == '/')
		{
			dir[i + 1] = '\0';
			break ;
		}
		i++;
	}
	if (access(dir, R_OK) != 0)
	{
		free(dir);
		dir = ft_strdup(".");
	}
	return (dir);
}

static const char	*get_name(const char *path, size_t n)
{
	while (n != 0)
	{
		--n;
		if (path[n] == '/')
			return (&path[n + 1]);
	}
	return (path);
}

static void			get_file(t_array *arr, char *dir, const char *w, size_t n)
{
	DIR				*fd;
	struct dirent	*file;

	if ((fd = opendir(dir)) == NULL)
		return ;
	while ((file = readdir(fd)))
	{
		if (ft_strncmp(w, file->d_name, n) == 0
			&& ft_strncmp(file->d_name, ".", 1) != 0
			&& ft_strncmp(file->d_name, "..", 2) != 0)
		{
			if ((file->d_type & DT_DIR) && *dir == '.')
				array_push(arr, FT_STRJOIN(file->d_name, "/"));
			else if (file->d_type & DT_DIR)
				array_push(arr, FT_STRJOIN(dir, file->d_name, "/"));
			else
				array_push(arr, FT_STRJOIN(dir, file->d_name));
		}
	}
	closedir(fd);
}

void				complete_file(t_array *arr, const char *path, size_t n)
{
	char			*dir;
	const char		*word;

	dir = get_path(path, n);
	word = get_name(path, n);
	get_file(arr, dir, word, ft_strlen(word));
	free(dir);
}
