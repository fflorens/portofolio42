/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 14:57:07 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/27 21:31:43 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "shell.h"
#include "builtins.h"
#include "nboon.h"

void		display_history(int max, int pos, int end)
{
	int		i;
	int		idx;

	i = 1;
	while (pos < end)
	{
		idx = pos % g_history_size;
		if (g_history[idx] != NULL)
			ft_printf("%5d  %s\n", (idx + 1), g_history[idx]);
		else
			break ;
		pos++;
		if (i >= max)
			break ;
		i++;
	}
}

int			history_builtin(char **argv)
{
	int		max;
	int		pos;
	int		end;
	int		i;

	if (argv[1] != NULL)
	{
		if ((i = ft_getnbr(argv[1], &max)) == 0 || argv[1][i] != '\0')
			return (ERROR("history", argv[1], "numeric argument required"));
	}
	else
		max = 0x7ffffff7;
	if (g_history_idx < (size_t)max)
		max = g_history_idx;
	pos = g_history_size - max;
	if (pos < 0)
		pos = 0;
	pos += g_history_idx;
	end = pos + g_history_size;
	display_history(max, pos, end);
	return (0);
}
