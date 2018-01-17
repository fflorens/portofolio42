/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipeline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 14:45:50 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/27 20:20:09 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "exec.h"
#include "builtins.h"

t_bool		non_fork_builtin(t_builtin *builtin)
{
	if (builtin->type == NOFORK)
		return (TRUE);
	return (FALSE);
}

int			exec_builtin(t_builtin *builtin, t_process *process)
{
	int				old_fd[2];
	int				status;

	old_fd[STDIN_FILENO] = dup(STDIN_FILENO);
	old_fd[STDOUT_FILENO] = dup(STDOUT_FILENO);
	if (build_process(process) == FALSE)
		status = 1;
	else
		status = builtin->exec(process->argv);
	dup2(old_fd[STDIN_FILENO], STDIN_FILENO);
	dup2(old_fd[STDOUT_FILENO], STDOUT_FILENO);
	return (status);
}
