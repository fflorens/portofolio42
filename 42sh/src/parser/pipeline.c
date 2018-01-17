/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 16:48:59 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/27 21:35:55 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
** A pipeline is a sequence of one or more processes, separated by PIPE
** and terminating with OR, AND, SEMICOLON, EOL or AMPER
*/

extern enum e_token	g_parse_error;

static t_pipeline	*terminate_pipeline(t_pipeline *pipeline, t_token *token)
{
	if (token->type == AMPER || token->type == SEMICOLON)
		pipeline->operator = EOL;
	else
		pipeline->operator = token->type;
	previous_token();
	return (pipeline);
}

static t_pipeline	*complete_pipeline(t_pipeline *pipeline)
{
	t_token			token;
	t_process		*process;

	while (TRUE)
	{
		token = get_next_token();
		if (token.type == OR || token.type == AND || token.type == EOL
				|| token.type == SEMICOLON || token.type == AMPER)
			return (terminate_pipeline(pipeline, &token));
		else if (token.type != PIPE)
		{
			pipeline_del(&pipeline);
			return (parse_error(&token));
		}
		free_token(token);
		if ((process = get_process(1)) == NULL)
		{
			pipeline_del(&pipeline);
			return (NULL);
		}
		process_add(&pipeline->first_process, process);
	}
}

t_pipeline			*get_pipeline(void)
{
	t_pipeline		*pipeline;
	t_process		*process;

	pipeline = pipeline_new();
	process = get_process(0);
	if (process == NULL)
	{
		pipeline_del(&pipeline);
		return (NULL);
	}
	process_add(&pipeline->first_process, process);
	return (complete_pipeline(pipeline));
}
