/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 12:32:59 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/27 22:55:22 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "lexer.h"
# include "dynbuf.h"
typedef struct passwd	t_passwd;
typedef struct group	t_group;
/*
** Process redirector structure (for dup2())
*/
typedef struct			s_redirector
{
	int					open_flag;
	int					open_mode;
	int					old_fd;
	int					new_fd;
	char				*file;
	char				*heredoc_label;
	t_dynbuf			*heredoc_buf;
	struct s_redirector	*next;
}						t_redirector;

/*
** A process is an argv/redirectors composed command or builtin
*/
typedef struct			s_process
{
	char				**argv;
	t_redirector		*first_redirector;
	struct s_process	*next;
}						t_process;

/*
** A pipeline is a job composed of various processes;
*/
typedef struct			s_pipeline
{
	enum e_token		operator;
	t_process			*first_process;
	struct s_pipeline	*next;
}						t_pipeline;

/*
** A command is a list of operator separated pipelines
*/
typedef struct			s_command
{
	t_bool				in_background;
	t_bool				is_last;
	t_pipeline			*first_pipeline;
	struct s_command	*next;
}						t_command;

/*
** t_command basic functions (structs/command.c)
*/
void					command_init(t_command *command);
t_command				*command_new(void);
void					command_del(t_command **ptr);
void					command_del_list(t_command **ptr);
void					command_add(t_command **command_list, t_command *new);

/*
** t_pipeline basic functions (structs/pipeline.c)
*/
void					pipeline_init(t_pipeline *pipeline);
t_pipeline				*pipeline_new(void);
void					pipeline_del(t_pipeline **ptr);
void					pipeline_add(t_pipeline **pipeline_list,
														t_pipeline *new);

/*
** t_process basic functions (structs/process.c)
*/
void					process_init(t_process *process);
t_process				*process_new(void);
void					process_del(t_process **ptr);
void					process_add(t_process **process_list, t_process *new);

/*
** t_redirector basic functions (structs/redirector.c)
*/
void					redirector_init(t_redirector *redirector);
t_redirector			*redirector_new(void);
void					redirector_del(t_redirector **ptr);
void					redirector_add(t_redirector **list, t_redirector *new);

#endif
