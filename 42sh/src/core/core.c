/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 14:01:48 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/27 23:11:25 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <unistd.h>
#include "core.h"
#include "utils.h"

t_core			g_core;

static char		*core_self_bin(char *bin)
{
	char		*out;
	char		*cwd;

	if (bin == NULL)
		return (NULL);
	if ((cwd = getcwd(NULL, 0)) == NULL)
		return (NULL);
	if ((out = (char *)malloc(ft_strlen(bin) + ft_strlen(cwd) + 2)) == NULL)
	{
		ft_strdel(&cwd);
		return (NULL);
	}
	out[0] = 0;
	ft_strcat(out, cwd);
	ft_strcat(out, "/");
	ft_strcat(out, bin);
	ft_strdel(&cwd);
	sh_realpath(&out);
	return (out);
}

void			core_init(char *bin_name)
{
	ft_bzero(&g_core, sizeof(g_core));
	sh_envmanager(ENV_INIT);
	sh_rebuildenv();
	if (time(&g_core.birth_time) < 0)
		g_core.birth_time = 0;
	g_core.history_size = -1;
	g_core.last_status = 0;
	g_core.current_cmdline = NULL;
	g_core.current_cmdlist = NULL;
	g_core.self_bin = core_self_bin(bin_name);
	core_update_path_list();
}

void			core_free(void)
{
	core_free_path_list();
	ft_strdel(&(g_core.self_bin));
	ft_strdel(&g_core.current_cmdline);
	command_del_list(&g_core.current_cmdlist);
}
