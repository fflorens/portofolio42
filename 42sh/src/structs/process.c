/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 12:35:39 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/27 21:34:12 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "structs.h"

void			process_init(t_process *process)
{
	ft_bzero(process, sizeof(*process));
}

t_process		*process_new(void)
{
	t_process		process;
	t_process		*copy;

	process_init(&process);
	copy = ft_memdup(&process, sizeof(process));
	return (copy);
}

void			process_del(t_process **ptr)
{
	t_process			*process;
	t_redirector		*redirector;

	process = *ptr;
	if (process == NULL)
		return ;
	if (process->argv != NULL)
		ft_strarrdel(&process->argv, -1);
	redirector = process->first_redirector;
	while (redirector != NULL)
		redirector_del(&redirector);
	*ptr = process->next;
	ft_memdel((void**)&process);
}

void			process_add(t_process **process_list, t_process *new)
{
	t_process		*process;

	if (*process_list == NULL)
	{
		*process_list = new;
		return ;
	}
	process = *process_list;
	while (process->next != NULL)
		process = process->next;
	process->next = new;
}
