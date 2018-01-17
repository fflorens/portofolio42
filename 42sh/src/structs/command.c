/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 14:56:12 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/27 21:33:43 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "structs.h"

void			command_init(t_command *command)
{
	ft_bzero(command, sizeof(*command));
}

t_command		*command_new(void)
{
	t_command	command;
	t_command	*copy;

	command_init(&command);
	copy = ft_memdup(&command, sizeof(command));
	return (copy);
}

void			command_del(t_command **ptr)
{
	t_command	*command;
	t_pipeline	*pipeline;

	command = *ptr;
	if (command == NULL)
		return ;
	pipeline = command->first_pipeline;
	while (pipeline != NULL)
		pipeline_del(&pipeline);
	*ptr = command->next;
	ft_memdel((void**)&command);
}

void			command_del_list(t_command **ptr)
{
	t_command	*command;

	command = *ptr;
	while (command != NULL)
		command_del(&command);
	*ptr = NULL;
}

void			command_add(t_command **command_list, t_command *new)
{
	t_command	*command;

	if (*command_list == NULL)
	{
		*command_list = new;
		return ;
	}
	command = *command_list;
	while (command->next != NULL)
		command = command->next;
	command->next = new;
}
