/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 16:22:49 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/27 21:36:21 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "core.h"

/*
** A command is a sequence of one or more pipelines, separated by a logical
** operator (OR or AND tokens), and terminated by SEMICOLON, EOL or AMPER.
*/

enum e_token			g_parse_error;

static t_command		*terminate_command(t_command *command, t_token *token)
{
	t_token				next_token;

	if (token->type == AMPER)
		command->in_background = TRUE;
	else if (token->type == SEMICOLON || token->type == EOL)
		command->in_background = FALSE;
	else
	{
		parse_error(token);
		free_token(*token);
		return (NULL);
	}
	free_token(*token);
	next_token = get_next_token();
	command->is_last = ((next_token.type == EOL) ? TRUE : FALSE);
	previous_token();
	return (command);
}

static t_command		*complete_command(t_command *command)
{
	t_token				token;
	t_pipeline			*pipeline;

	while (TRUE)
	{
		token = get_next_token();
		if (token.type == SEMICOLON || token.type == AMPER || token.type == EOL)
			return (terminate_command(command, &token));
		else if (token.type != AND && token.type != OR)
		{
			command_del(&command);
			return (parse_error(&token));
		}
		free_token(token);
		if ((pipeline = get_pipeline()) == NULL)
		{
			command_del(&command);
			return (NULL);
		}
		pipeline_add(&command->first_pipeline, pipeline);
	}
}

t_command				*get_command(void)
{
	t_command			*command;
	t_pipeline			*pipeline;

	command = command_new();
	pipeline = get_pipeline();
	if (pipeline == NULL)
	{
		command_del(&command);
		return (NULL);
	}
	pipeline_add(&command->first_pipeline, pipeline);
	return (complete_command(command));
}

t_command				*get_command_list(char *cmdline)
{
	t_command			*command;

	g_parse_error = 0;
	command_del_list(&g_core.current_cmdlist);
	lexer(cmdline);
	command = get_command();
	while (command != NULL)
	{
		command_add(&g_core.current_cmdlist, command);
		if (command->is_last == FALSE)
			command = get_command();
		else
			break ;
	}
	if (print_parse_error())
	{
		while (g_core.current_cmdlist)
			command_del(&g_core.current_cmdlist);
		return (NULL);
	}
	return (g_core.current_cmdlist);
}
