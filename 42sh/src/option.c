/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzak <jzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 22:07:51 by jzak              #+#    #+#             */
/*   Updated: 2014/03/26 23:33:26 by jzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nboon.h"
#include "printf.h"
#include "shell.h"
#include "core.h"
#include "exec.h"

int				opt_help(char **av, int ac, void *userdata)
{
	t_core		*core;

	(void)av;
	(void)ac;
	core = (t_core*)userdata;
	destroy_opt(&core->opt);
	help();
	exit(0);
}

int				opt_version(char **av, int ac, void *userdata)
{
	t_core		*core;

	(void)av;
	(void)ac;
	core = (t_core*)userdata;
	destroy_opt(&core->opt);
	ft_dprintf(1, "version 1.0\n");
	exit(0);
}

int				opt_multiline(char **av, int ac, void *userdata)
{
	t_core		*core;

	(void)av;
	(void)ac;
	core = (t_core*)userdata;
	core->multiline = 1;
	return (0);
}

int				opt_history_size(char **av, int ac, void *userdata)
{
	t_core		*core;

	(void)av;
	(void)ac;
	core = (t_core*)userdata;
	if (!ft_getnbr(av[1], &core->history_size))
	{
		ERROR("invalid argument of option history: %s (not a number)\n", av[0]);
		return (1);
	}
	if (core->history_size > MAX_HISTORY_SIZE)
	{
		ft_dprintf(2, "history size is too big:");
		ft_dprintf(2, " %ld (max: %d)\n", core->history_size, MAX_HISTORY_SIZE);
		return (1);
	}
	return (0);
}

int				opt_single_exec(char **av, int ac, void *userdata)
{
	t_command		*command;
	int				ret;
	t_core			*core;

	(void)ac;
	core = (t_core*)userdata;
	command = get_command_list(av[1]);
	ret = exec_command_list(command);
	sh_envmanager(ENV_FREE);
	free_lexer();
	destroy_opt(&core->opt);
	core_free();
	exit(ret);
}
