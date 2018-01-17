/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 13:13:55 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/27 14:42:59 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/stat.h>
#include "shell.h"
#include "printf.h"

static int		get_opt(char c, void *container)
{
	char	*opt;

	opt = (char*)container;
	if (c != 'L' && c != 'P')
	{
		ft_dprintf(2, "cd: -%c: invalid option\n", c);
		ft_dprintf(2, "%s: usage: cd [-L|-P] [dir]\n", NAME);
		return (-1);
	}
	*opt = c;
	return (0);
}

static int		check_permissions(char **dir)
{
	struct stat		info;

	if (stat(*dir, &info) == -1)
		ERROR("cd", *dir, ft_strerror(ENOENT));
	else if (!S_ISDIR(info.st_mode))
		ERROR("cd", *dir, ft_strerror(ENOTDIR));
	else if (access(*dir, X_OK) == -1)
		ERROR("cd", *dir, ft_strerror(EACCES));
	else
		return (1);
	ft_strdel(dir);
	return (0);
}

static char		*preprocess_cd(char **newpwd, char **argv, int i)
{
	char		*oldpwd;

	if ((oldpwd = sh_getenv("PWD")) == NULL)
		oldpwd = getcwd(NULL, 0);
	else
		oldpwd = ft_strdup(oldpwd);
	if (*newpwd == NULL && argv[i] && argv[i][0] == '/')
		*newpwd = ft_strdup(argv[i]);
	else if (*newpwd == NULL)
		*newpwd = FT_STRJOIN(oldpwd, "/", argv[i]);
	else
		*newpwd = ft_strdup(*newpwd);
	sh_realpath(newpwd);
	if (!check_permissions(newpwd))
		return (NULL);
	return (oldpwd);
}

static void		finish_cd(char opt, char **newpwd, char *oldpwd)
{
	if (opt == 'P')
	{
		ft_strdel(newpwd);
		*newpwd = getcwd(NULL, 0);
	}
	sh_setenv("PWD", *newpwd, 1);
	sh_setenv("OLDPWD", oldpwd, 1);
}

int				cd_builtin(char **argv)
{
	int		i;
	int		argc;
	char	opt;
	char	*npwd;
	char	*oldpwd;

	opt = '\0';
	argc = ft_strarrlen((const char **)argv);
	if ((i = ft_optiter(argc, argv, get_opt, (void*)&opt)) == -1)
		return (1);
	npwd = NULL;
	if (argv[i] == NULL && (npwd = sh_getenv("HOME")) == NULL)
		return (ERROR("cd", "HOME not set"));
	if (argv[i] && ft_strequ(argv[i], "-") && !(npwd = sh_getenv("OLDPWD")))
		return (ERROR("cd", "OLDPWD not set"));
	if ((oldpwd = preprocess_cd(&npwd, argv, i)) == NULL)
		return (1);
	if (chdir(npwd) == -1 && ERROR("cd", npwd, "Failed to change directory"))
	{
		ft_strdel(&npwd);
		return (1);
	}
	finish_cd(opt, &npwd, oldpwd);
	return (0);
}
