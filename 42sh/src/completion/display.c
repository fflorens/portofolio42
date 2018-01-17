/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzak <jzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 12:51:49 by jzak              #+#    #+#             */
/*   Updated: 2014/03/27 21:43:40 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/stat.h>
#include "array.h"
#include "builtins.h"
#include "core.h"
#include "exec.h"
#include "shell.h"
#include "sigconf.h"

static t_bool		comp_is_valid(char *name)
{
	struct stat		info;

	if (stat(name, &info) < 0)
		return (FALSE);
	if (S_ISDIR(info.st_mode))
		return (FALSE);
	if (access(name, X_OK) < 0)
		return (FALSE);
	return (TRUE);
}

static int			expand_bin(char **name)
{
	char			*result;
	int				i;

	result = NULL;
	i = -1;
	while (g_core.path_list[++i] != NULL)
	{
		result = FT_STRJOIN(g_core.path_list[i], "/", *name);
		if (comp_is_valid(result))
			break ;
		ft_strdel(&result);
	}
	if (result == NULL)
	{
		ERROR(*name, "command not found");
		ft_strdel(name);
		return (-1);
	}
	ft_strdel(name);
	*name = result;
	return (0);
}

static void			free_array(char **arr)
{
	int				i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		++i;
	}
	free(arr);
}

static char			**array_dup(t_array *arr)
{
	size_t			i;
	char			**new;

	new = malloc(sizeof(*new) * (arr->used * 2));
	new[0] = ft_strdup("echo");
	i = 1;
	while (i < arr->used)
	{
		if (i == 1)
			new[1] = FT_STRJOIN(" ", arr->data[0]);
		else
			new[i] = ft_strdup(arr->data[i - 1]);
		++i;
	}
	new[i] = NULL;
	return (new);
}

void				completion_display(t_array *arr)
{
	t_pipeline		pipe;
	t_process		column;
	t_process		more;
	t_process		echo;

	write(1, "\n", 1);
	more.argv = ft_strsplit("more", ' ');
	more.first_redirector = NULL;
	more.next = NULL;
	column.argv = ft_strsplit("column", ' ');
	column.first_redirector = NULL;
	column.next = &more;
	echo.argv = array_dup(arr);
	echo.first_redirector = NULL;
	echo.next = &column;
	pipe.operator = EOL;
	pipe.first_process = &echo;
	pipe.next = NULL;
	if (!(expand_bin(&(column.argv[0])) + expand_bin(&(more.argv[0]))))
		exec_pipeline(&pipe);
	free_array(echo.argv);
	free_array(more.argv);
	free_array(column.argv);
}
