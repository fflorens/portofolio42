/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzak <jzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 13:30:28 by jzak              #+#    #+#             */
/*   Updated: 2014/03/27 21:42:47 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include "libft.h"
#include "printf.h"
#include "shell.h"
#include "builtins.h"
#include "completion.h"

t_completion	*g_comp = NULL;

static void		load_binary(const char *bin_path)
{
	DIR				*dir;
	char			*result;
	struct dirent	*file;

	if ((dir = opendir(bin_path)) == NULL)
		return ;
	while ((file = readdir(dir)))
	{
		if (!ft_strncmp(file->d_name, ".", 1)
				|| !ft_strncmp(file->d_name, "..", 2))
			continue ;
		if (!access((result = FT_STRJOIN(bin_path, "/", file->d_name)), X_OK))
		{
			if (array_find(g_comp->bin, file->d_name) == -1)
				array_push(g_comp->bin, ft_strdup(file->d_name));
		}
		free(result);
	}
	closedir(dir);
}

static void		load_binary_name(const char **path)
{
	int		i;

	i = 0;
	while (path[i])
	{
		load_binary(path[i]);
		++i;
	}
	i = 0;
	while (g_builtin[i].name != NULL)
	{
		if (array_find(g_comp->bin, g_builtin[i].name) == -1)
			array_push(g_comp->bin, ft_strdup(g_builtin[i].name));
		++i;
	}
}

void			refresh_completion_table(const char **path)
{
	if (g_comp == NULL)
	{
		g_comp = (t_completion*)malloc(sizeof(*g_comp));
		g_comp->path_hash = get_path_hash(path);
		g_comp->bin = init_array(COMP_SIZE_TABLE / 2);
		g_comp->result = init_array(COMP_SIZE_TABLE);
		load_binary_name(path);
		array_sort(g_comp->bin, ft_strcmp);
	}
	else if (g_comp->path_hash != get_path_hash(path))
	{
		array_clear(g_comp->bin, free);
		load_binary_name(path);
		array_sort(g_comp->bin, ft_strcmp);
	}
}

void			free_completion(void)
{
	if (g_comp != NULL)
	{
		destroy_array(g_comp->bin, free);
		destroy_array(g_comp->result, free);
		free(g_comp);
		g_comp = NULL;
	}
}
