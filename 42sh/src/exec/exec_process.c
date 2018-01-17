/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 20:44:56 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/27 21:39:37 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/stat.h>
#include "shell.h"
#include "exec.h"
#include "builtins.h"
#include "core.h"
#include "sigconf.h"

static t_bool		bin_is_valid(char *name)
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

static int			expand_bin_path(char **name)
{
	char			*result;
	int				i;

	result = NULL;
	i = -1;
	while (g_core.path_list[++i] != NULL)
	{
		result = FT_STRJOIN(g_core.path_list[i], "/", *name);
		if (bin_is_valid(result))
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

static void			run_process(char *name, char **argv)
{
	int				err;
	struct stat		info;

	err = 0;
	if (stat(name, &info) < 0)
		err = ERROR(name, ERRNO);
	else if (S_ISDIR(info.st_mode))
		err = ERROR(name, ft_strerror(EISDIR));
	else if (access(name, X_OK) < 0)
		err = ERROR(name, ft_strerror(EACCES));
	else if (execve(name, argv, sh_envmanager(ENV_GETPTR)) == -1)
		err = ERROR(name, ERRNO);
	if (err)
	{
		ft_strdel(&name);
		sh_exit(err);
	}
}

void				exec_process(t_process *process, int stdin, int stdout)
{
	char			*name;
	t_builtin		*builtin;
	int				ret;

	ret = 1;
	sigconf(SIGS_ALL, SIG_DFL);
	if (stdin != STDIN_FILENO)
		dup2(stdin, STDIN_FILENO);
	if (stdout != STDOUT_FILENO)
		dup2(stdout, STDOUT_FILENO);
	name = ft_strdup(process->argv[0]);
	if ((builtin = builtin_load(name)) != NULL)
	{
		ft_strdel(&name);
		ret = builtin->exec(process->argv);
	}
	else if (!ft_strchr(name, '/') && expand_bin_path(&name) < 0)
		ret = 127;
	else
		run_process(name, process->argv);
	ft_strdel(&name);
	sh_exit(ret);
}
