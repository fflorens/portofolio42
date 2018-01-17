/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 23:35:01 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/27 16:05:26 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "structs.h"
# include "parser.h"
# include "builtins.h"

# define GLOB_CHARS "*?[]\\"

/*
** exec/exec_command.c
*/
int					exec_command(t_command *command);
int					exec_command_list(t_command *command);

/*
** exec/exec_pipeline.c
*/
int					exec_pipeline(t_pipeline *pipeline);

/*
** exec/exec_process.c
*/
void				exec_process(t_process *process, int stdin, int stdout);

/*
** exec/exec_builtin.c
*/
t_bool				non_fork_builtin(t_builtin *builtin);
int					exec_builtin(t_builtin *builtin, t_process *process);

/*
** exec/build_process.c
*/
t_bool				build_process(t_process *process);

/*
** exec/build_redirector.c
*/
t_bool				build_process_redirectors(t_process *process);
t_bool				build_process_heredoc(t_process *process, int fd);

#endif
