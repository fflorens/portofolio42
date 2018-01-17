/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 13:26:22 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/27 21:32:22 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "printf.h"
#include "shell.h"

static int		pwd_o(char c, void *container)
{
	char		*opt;

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

int				pwd_builtin(char **av)
{
	char		*pwd;
	char		o;

	o = '\0';
	if (ft_optiter(ft_strarrlen((const char **)av), av, pwd_o, (void*)&o) == -1)
		return (1);
	if (o != 'P')
	{
		if ((pwd = sh_getenv("PWD")) == NULL)
			pwd = getcwd(NULL, 0);
		else
			pwd = ft_strdup(pwd);
	}
	else
		pwd = getcwd(NULL, 0);
	if (pwd == NULL)
		return (ERROR("pwd", "Cannot get current working directory"));
	ft_putendl(pwd);
	free(pwd);
	return (0);
}
