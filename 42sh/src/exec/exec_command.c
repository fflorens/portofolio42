/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 14:45:31 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/27 21:37:21 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "core.h"

int					exec_command(t_command *command)
{
	t_pipeline		*pipeline;
	int				status;

	status = 0;
	pipeline = command->first_pipeline;
	while (pipeline != NULL)
	{
		status = exec_pipeline(pipeline);
		g_core.last_status = status % 255;
		if (pipeline->operator == EOL)
			break ;
		if (pipeline->operator == OR && status == 0)
			break ;
		if (pipeline->operator == AND && status != 0)
			break ;
		pipeline = pipeline->next;
	}
	return (status);
}

int					exec_command_list(t_command *command)
{
	int				status;

	status = 0;
	while (command != NULL)
	{
		status = exec_command(command);
		command = command->next;
	}
	return (status);
}
