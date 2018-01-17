/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 13:26:35 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/26 19:09:44 by jzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shell.h"

int		exit_builtin(char **argv)
{
	int		status;

	if (ft_strarrlen((const char**)argv) > 2)
		return (ERROR("exit", "too many arguments"));
	ft_putendl("exit");
	if (argv[1] == NULL)
		status = 0;
	else if (!ft_getnbr(argv[1], &status))
		status = 255 * ERROR("exit", argv[1], "numeric argument required");
	while (status < 0)
		status += 255;
	while (status > 255)
		status -= 256;
	return (sh_exit(status));
}
