/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/07 18:24:25 by bgauci            #+#    #+#             */
/*   Updated: 2014/05/11 23:01:05 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philosophe.h"
#include	<errno.h>
#include	<pthread.h>
#include	<unistd.h>
#include	<stdlib.h>

extern int	g_fd;

static void		ft_error2(int errorcode)
{
	write(2, "Error while creating thread: ", 28);
	if (errorcode == EAGAIN)
	{
		write(2, "The system lacked the necessary resources to create", 51);
		write(2, " another thread, or the system-imposed limit on the", 51);
		write(2, " total number of process thread is exceeded.", 43);
	}
	else if (errorcode == EAGAIN)
	{
		write(2, "The system temporarily lacks the resources to creat", 51);
		write(2, "e another mutex.\n", 17);
	}
	else
		write(2, "Unknown error code\n", 19);
}

static int		ft_error(int errorcode, char *object)
{
	if (object[0] == 'm')
	{
		write(2, "Error while creating mutex: ", 28);
		if (errorcode == EINVAL)
			write(2, "The value specified by attr is invalid.\n", 30);
		else if (errorcode == EAGAIN)
		{
			write(2, "The system temporarily lacks the resources to creat", 51);
			write(2, "e another mutex.\n", 17);
		}
		else if (errorcode == ENOMEM)
		{
			write(2, "The process cannot allocate enough memory to create", 51);
			write(2, " another mutex.\n", 16);
		}
		else
			write(2, "Unknown error code\n", 19);
	}
	else
		ft_error2(errorcode);
	close(g_fd);
	return (EXIT_FAILURE);
}

static int		clear_mutex(int error, char *str, int i, t_table **table)
{
	while (--i > -1)
		pthread_mutex_destroy(&(*table)->sticktab[i].mutex);
	return (ft_error(error, str));
}

t_table			*create_condi(t_table *table)
{
	int			i;
	static int	id;

	i = 0;
	id = 0;
	while (i < NB_PHIL)
	{
		table->sticktab[i].phid = -1;
		i++;
	}
	i = 0;
	while (i < NB_PHIL)
	{
		table->philotab[i].id = id;
		table->philotab[i].pv = MAX_LIFE;
		table->philotab[i].stat = NOTHING;
		if (i == 0)
			table->philotab[i].stick[RIGHT] = &(table->sticktab[NB_PHIL - 1]);
		else
			table->philotab[i].stick[RIGHT] = &(table->sticktab[i - 1]);
		table->philotab[i].stick[LEFT] = &(table->sticktab[i]);
		id++;
		i++;
	}
	return (table);
}

int				init(t_table **table)
{
	int		i;
	int		res;

	i = -1;
	*table = create_condi(get_table());
	while (++i < NB_PHIL)
	{
		if ((res = pthread_mutex_init(&(*table)->sticktab[i].mutex, NULL)) != 0)
			return (clear_mutex(res, "mutex", i, table));
	}
	i = -1;
	while (++i < NB_PHIL)
	{
		if ((res = pthread_create(&(*table)->philotab[i].self, NULL, phil,
						(void *)&(*table)->philotab[i]) != 0))
		{
			g_forcequit = TRUE;
			i = -1;
			return (clear_mutex(res, "thread", NB_PHIL, table));
		}
	}
	return (EXIT_SUCCESS);
}
