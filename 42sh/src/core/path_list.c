/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 16:38:51 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/25 15:20:30 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "core.h"

void			core_update_path_list(void)
{
	const char		*path_var;

	core_free_path_list();
	path_var = sh_getvar("PATH");
	g_core.path_list = ft_strsplit(path_var, ':');
}

void			core_free_path_list(void)
{
	if (g_core.path_list != NULL)
		ft_strarrdel(&g_core.path_list, -1);
}
