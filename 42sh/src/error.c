/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 14:38:35 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/27 23:19:06 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "shell.h"
#include "nboon.h"
#include "lexer.h"
#include "core.h"
#include "completion.h"

void		help(void)
{
	ft_dprintf(2, "Usage: 42sh [-c command]     Run single command\n");
	ft_dprintf(2, "            [-history size]  Set the size of the history\n");
	ft_dprintf(2, "            [-m -multiline]  Active the");
	ft_dprintf(2, " multiline edition\n");
	ft_dprintf(2, "            [-r -rebuildenv] Toggle off minimal environ");
	ft_dprintf(2, "nement rebuilding\n");
	ft_dprintf(2, "            [-h -help]       Print this message\n");
	ft_dprintf(2, "            [-v -version]    Display version info\n");
}

int			sh_exit(int status)
{
	nb_history_save(sh_getvar("SH_HISTFILE"));
	nb_history_free();
	free_completion();
	sh_envmanager(ENV_FREE);
	free_lexer();
	core_free();
	exit(status);
	return (status);
}

void		*ft_xmalloc_catch(void *ptr)
{
	return (ptr);
}

void		ft_xmalloc_error(void)
{
	FATAL_ERROR("Fatal error", ENOMEM);
}
