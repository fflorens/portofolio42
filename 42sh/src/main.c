/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 15:05:46 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/27 23:14:02 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sigconf.h"
#include "shell.h"
#include "printf.h"
#include "core.h"
#include "exec.h"
#include "nboon.h"
#include "completion.h"

static void		init_shell(void)
{
	sigconf(SIGS_ALL ^ SIGS_ERROR ^ SIG_QUIT, sigmode_shell);
	sigconf(SIG_WINCH, nb_refresh_size);
	if (g_core.history_size == -1)
		g_core.history_size = ft_atoi(sh_getvar("SH_HISTSIZE"));
	nb_history_init(g_core.history_size);
	nb_history_load(sh_getvar("SH_HISTFILE"));
	refresh_completion_table((const char **)g_core.path_list);
	nb_set_completion_callback(autocomplete_line);
	if (g_core.multiline || *sh_getvar("SH_MULTILINE") == '1')
		nb_set_refresh_callback(nb_refresh_multi_line);
}

static t_bool	line_isempty(char *line)
{
	while (*line)
	{
		if (*line != ' ' && *line != '\t')
			return (FALSE);
		line++;
	}
	return (TRUE);
}

static void		exec_line(char *cmdline)
{
	t_command		*command;

	command = get_command_list(cmdline);
	refresh_completion_table((const char **)g_core.path_list);
	g_core.current_cmdline = cmdline;
	exec_command_list(command);
	nb_history_add(cmdline);
	ft_strdel(&g_core.current_cmdline);
	if (*sh_getvar("SH_MULTILINE") == '1')
		nb_set_refresh_callback(nb_refresh_multi_line);
}

static void		init_option(int ac, char **av)
{
	t_opt		*opt;

	if ((opt = init_opt(NULL, ac, av)) == NULL)
		return ;
	g_core.opt = opt;
	add_opt(opt, "c", 1, opt_single_exec);
	add_opt(opt, "m", 0, opt_multiline);
	add_opt(opt, "multiline", 0, opt_multiline);
	add_opt(opt, "history", 1, opt_history_size);
	add_opt(opt, "h", 0, opt_help);
	add_opt(opt, "help", 0, opt_help);
	add_opt(opt, "v", 0, opt_version);
	add_opt(opt, "version", 0, opt_version);
	add_opt(opt, "r", 0, opt_rebuild);
	add_opt(opt, "rebuildenv", 0, opt_rebuild);
	if (parse_opt(opt, &g_core))
	{
		help();
		destroy_opt(&opt);
		exit(1);
	}
	destroy_opt(&opt);
}

int				main(int ac, char **av)
{
	char		*cmdline;
	int			status;

	core_init(av[0]);
	init_option(ac, av);
	init_shell();
	while ((status = nb_get_line(sh_getvar("PS1"), &cmdline)) != NB_EXIT)
	{
		if (status == NB_ERROR)
		{
			ft_dprintf(2, "%s\n", nb_get_error());
			if (g_nb_error == ERR_NO_TERM)
				sh_exit(0);
		}
		else if (status != NB_INTERRUPT && !line_isempty(cmdline))
			exec_line(cmdline);
	}
	return (sh_exit(0));
}
