/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 14:57:05 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/27 22:12:59 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "exec.h"
#include "printf.h"

static void			clear_process(t_pipeline **process)
{
	t_process		*proc;
	char			**argv;

	if (!*process)
		return ;
	proc = (*process)->first_process;
	argv = proc->argv;
	ft_strarrdel(&argv, -1);
	ft_memdel((void **)&proc);
	ft_memdel((void **)process);
}

static int			add_to_env(char **argv, int i)
{
	char			*tmp1;
	char			*tmp2;

	while (argv[i] && (tmp1 = ft_strchr(argv[i], '=')))
	{
		tmp2 = tmp1 + 1;
		*tmp1 = 0;
		sh_setenv(argv[i], tmp2, 1);
		i++;
	}
	return (0);
}

static int			prepare_env(char **argv, t_pipeline **process)
{
	int				i;
	int				j;

	i = 1;
	while (argv[i] && (argv[i][0] == '-'))
	{
		if (!ft_strcmp(argv[i], "-i"))
			sh_envmanager(ENV_FREE);
		else if (argv[i][0] == '-' && !ft_strequ(argv[i], "--"))
		{
			clear_process(process);
			j = 0;
			while (argv[i][j] == '-')
				j++;
			if (argv[i][j])
			{
				ft_dprintf(2, "env: illegal option -- %c\n", argv[i][j]);
				ft_dprintf(2, "usage: env [-i] [name=value ...]");
				ft_dprintf(2, "[utility [argument ...]]\n");
			}
			return (1);
		}
		i++;
	}
	return (add_to_env(argv, i));
}

static t_pipeline	*build_env_process(char **argv)
{
	int				i;
	t_process		*process;
	t_pipeline		*out;

	i = 1;
	while (argv[i] && (argv[i][0] == '-'))
		i++;
	while (argv[i] && ft_strchr(argv[i], (int)'='))
		i++;
	if (argv[i] == NULL)
		return (NULL);
	process = process_new();
	process->first_redirector = NULL;
	process->argv = ft_strarrdup(argv + i, -1);
	process->next = NULL;
	out = pipeline_new();
	out->first_process = process;
	out->next = NULL;
	return (out);
}

int					env_builtin(char **argv)
{
	t_pipeline		*process;
	char			**env;

	process = build_env_process(argv);
	if (prepare_env(argv, &process) == 1)
		return (1);
	if (process)
	{
		exec_pipeline(process);
		clear_process(&process);
		return (0);
	}
	env = sh_envmanager(ENV_GETPTR);
	if (env)
		while (*env)
			ft_putendl(*env++);
	return (0);
}
