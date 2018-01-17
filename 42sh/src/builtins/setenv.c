/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 14:57:07 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/26 19:10:04 by jzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "builtins.h"
#include "core.h"

int		setenv_builtin(char **argv)
{
	int		argc;
	char	*val;

	if ((argc = ft_strarrlen((const char**)argv)) == 1)
		return (env_builtin(argv));
	if (argc > 3)
		return (ERROR("setenv", "Too many arguments."));
	if (ft_strchr(argv[1], '='))
		return (ERROR("setenv", "Syntax Error."));
	val = (argv[2] != NULL ? argv[2] : "");
	sh_setenv(argv[1], val, 1);
	if (ft_strequ(argv[1], "PATH"))
		core_update_path_list();
	return (0);
}
