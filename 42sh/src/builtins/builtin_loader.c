/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_loader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 20:11:40 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/27 21:33:46 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "builtins.h"

t_builtin	g_builtin[] = {
	{ ":q!", builtin_qexclamation, NOFORK },
	{ ":qw", exit_builtin, NOFORK },
	{ ":wq", exit_builtin, NOFORK },
	{ ":w", wsavehist_builtin, NOFORK },
	{ "exit", exit_builtin, NOFORK },
	{ "pwd", pwd_builtin, FORK },
	{ "cd", cd_builtin, NOFORK },
	{ "env", env_builtin, FORK },
	{ "setenv", setenv_builtin, NOFORK },
	{ "unsetenv", unsetenv_builtin, NOFORK },
	{ "echo", echo_builtin, FORK },
	{ "history", history_builtin, FORK },
	{ "yes", yes_builtin, FORK },
	{ NULL, NULL, NOFORK }
};

t_builtin	*builtin_load(char *name)
{
	int					i;

	i = 0;
	while (g_builtin[i].name != NULL)
	{
		if (ft_strcmp(g_builtin[i].name, name) == 0)
			return (&(g_builtin[i]));
		i++;
	}
	return (NULL);
}
