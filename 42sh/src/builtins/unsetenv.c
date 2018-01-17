/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 14:57:09 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/26 19:10:16 by jzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		unsetenv_builtin(char **argv)
{
	int		i;

	if ((ft_strarrlen((const char**)argv)) == 1)
		return (ERROR("unsetenv", "Too few arguments."));
	i = 1;
	while (argv[i] != NULL)
	{
		sh_unsetenv(argv[i]);
		i++;
	}
	return (0);
}
