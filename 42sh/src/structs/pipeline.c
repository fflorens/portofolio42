/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 15:43:40 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/27 21:33:56 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "structs.h"

void			pipeline_init(t_pipeline *pipeline)
{
	ft_bzero(pipeline, sizeof(*pipeline));
}

t_pipeline		*pipeline_new(void)
{
	t_pipeline	pipeline;
	t_pipeline	*copy;

	pipeline_init(&pipeline);
	copy = ft_memdup(&pipeline, sizeof(pipeline));
	return (copy);
}

void			pipeline_del(t_pipeline **ptr)
{
	t_pipeline	*pipeline;
	t_process	*process;

	pipeline = *ptr;
	if (pipeline == NULL)
		return ;
	process = pipeline->first_process;
	while (process != NULL)
		process_del(&process);
	*ptr = pipeline->next;
	ft_memdel((void**)&pipeline);
}

void			pipeline_add(t_pipeline **pipeline_list, t_pipeline *new)
{
	t_pipeline	*pipeline;

	if (*pipeline_list == NULL)
	{
		*pipeline_list = new;
		return ;
	}
	pipeline = *pipeline_list;
	while (pipeline->next != NULL)
		pipeline = pipeline->next;
	pipeline->next = new;
}
