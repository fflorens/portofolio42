/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 19:34:15 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/27 15:22:58 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void			array_join(char ***array, char **to_add)
{
	int			i;
	int			j;

	i = sizeof(char*) * ft_strarrlen((const char**)*array);
	j = sizeof(char*) * ft_strarrlen((const char**)to_add);
	*array = ft_realloc(*array, (i + sizeof(char*)), (i + j + sizeof(char*)));
	i = 0;
	j /= sizeof(char*);
	while (i < j)
	{
		FT_ARRPUSH(*array, ft_strdup(to_add[i]));
		i++;
	}
	ft_strarrdel(&to_add, j);
}

static t_bool	build_process_arguments(t_process *process)
{
	int			i;
	char		**new_array;
	char		**tmp_array;

	i = 0;
	new_array = FT_NEWPTR(char*, 1);
	while (process->argv[i] != NULL)
	{
		tmp_array = sh_globalize(process->argv[i]);
		array_join(&new_array, tmp_array);
		i++;
	}
	ft_strarrdel(&process->argv, i);
	process->argv = new_array;
	return (TRUE);
}

t_bool			build_process(t_process *process)
{
	t_bool		status;

	status = TRUE;
	if (build_process_redirectors(process) == FALSE)
		status = FALSE;
	else if (build_process_arguments(process) == FALSE)
		status = FALSE;
	return (status);
}
