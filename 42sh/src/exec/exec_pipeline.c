/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipeline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 16:10:02 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/27 21:39:23 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"
#include "exec.h"
#include "builtins.h"

static int			wait_child_status(pid_t pid)
{
	int				tmp;
	int				ret;
	int				status;

	status = 1;
	while ((ret = waitpid(-1, &tmp, WUNTRACED)) >= 0)
	{
		if (WIFSIGNALED(tmp))
			sigmode_error((status = 128 + WTERMSIG(tmp)) - 128);
		else if (WIFSTOPPED(tmp))
			status = 128 + WSTOPSIG(tmp);
		else if (ret == pid)
			status = tmp;
		else
			continue ;
		if (WIFSTOPPED(tmp))
			kill(0, SIGCONT);
		else
			kill(0, SIGTERM);
	}
	if (errno != ECHILD)
		return (ERROR(NAME, ERRNO));
	return (status);
}

static int			run_single_process(t_process *process)
{
	t_builtin		*builtin;
	t_redirector	*r;
	int				t[2];
	int				pid;

	builtin = builtin_load(process->argv[0]);
	t[0] = -1;
	if ((t[1] = -1) && builtin != NULL && non_fork_builtin(builtin))
		return (exec_builtin(builtin, process));
	if ((r = process->first_redirector) && r->heredoc_label && pipe(t) < 0)
		return (ERROR(NAME, "Can't create pipeline", ERRNO));
	else if ((pid = fork()) < 0)
		return (ERROR(process->argv[0], ERRNO));
	else if (pid == 0)
	{
		if (build_process(process) == FALSE)
			sh_exit(1);
		if (t[1] != -1)
			close(t[1]);
		exec_process(process, t[0], STDOUT_FILENO);
	}
	if (r && r->heredoc_label && build_process_heredoc(process, t[1]) == FALSE)
		return (ERROR(NAME, ERRNO));
	sh_closepipe(t);
	return (wait_child_status(pid));
}

static void			run_child(t_process *process, int *t, int *tube)
{
	if (build_process(process) == FALSE)
		sh_exit(1);
	if (t[1] != -1)
		close(t[1]);
	if (process->next == NULL)
		exec_process(process, t[0], STDOUT_FILENO);
	close(tube[0]);
	exec_process(process, t[0], tube[1]);
}

static int			run_pipelined_process(t_process *process, int stdin, int i)
{
	pid_t			pid;
	int				tube[2];
	int				t[2];
	t_redirector	*r;

	t[0] = stdin;
	t[1] = -1;
	if (process->next != NULL && pipe(tube) < 0)
		return (ERROR(NAME, "Can't create pipeline", ERRNO));
	if (i && (r = process->first_redirector) && r->heredoc_label && pipe(t) < 0)
		return (ERROR(NAME, "Can't create pipeline", ERRNO));
	if ((pid = fork()) < 0)
		return (ERROR(NAME, "Can't fork subprocess", ERRNO));
	if (pid == 0)
		run_child(process, t, tube);
	if (i && r && r->heredoc_label)
		if (build_process_heredoc(process, t[1]) == FALSE)
			return (ERROR(NAME, ERRNO));
	sh_closepipe(t);
	if (process->next == NULL)
		return (wait_child_status(pid));
	close(tube[1]);
	return (run_pipelined_process(process->next, tube[0], 0));
}

int					exec_pipeline(t_pipeline *pipeline)
{
	t_process		*process;
	int				status;

	process = pipeline->first_process;
	if (process == NULL)
		status = 0;
	else if (process->next == NULL)
		status = run_single_process(process);
	else
		status = run_pipelined_process(process, STDIN_FILENO, 1);
	return (status);
}
