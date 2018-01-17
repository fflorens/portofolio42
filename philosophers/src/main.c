/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/07 19:50:18 by bgauci            #+#    #+#             */
/*   Updated: 2014/05/11 23:20:23 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philosophe.h"
#include	"debug.h"
#include	<errno.h>
#include	<pthread.h>
#include	<unistd.h>
#include	<stdlib.h>

int		g_forcequit = 0;
int		g_fd = -1;

t_table	*get_table(void)
{
	static t_table	table;

	return (&table);
}

int		main(void)
{
	int			i;
	t_table		*table;
	char		end;

	if ((set_term() != EXIT_SUCCESS) || (init(&table) != EXIT_SUCCESS))
		return (EXIT_FAILURE);
	table->turn = -1;
	end = 0;
	while (++(table->turn) < TIMEOUT_T && !end)
	{
		i = display(table->philotab, table->sticktab, table->turn);
		usleep(MUL_SECOND);
		while (++i < NB_PHIL)
		{
			CURR_PV -= ((CURR_STAT != EATING) ? 1 : 0);
			CURR_STAT = ((CURR_PV <= 0) ? DEAD : CURR_STAT);
			end = ((CURR_STAT == DEAD) ? 1 : end);
		}
	}
	restore_term();
	display(table->philotab, table->sticktab, table->turn);
	g_forcequit = 1;
	read(STDIN_FILENO, &end, 4);
	return (EXIT_SUCCESS);
}
