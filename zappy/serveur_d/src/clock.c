/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 17:26:19 by dbenoit           #+#    #+#             */
/*   Updated: 2014/06/22 23:43:16 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include "server.h"
#include <sys/time.h>
#include <time.h>
#include <math.h>
#include <stdio.h>

double			get_turn_time_left(int reset)
{
	static clock_t	turnstart = 0;
	clock_t			now;

	if (reset == 1)
	{
		turnstart = clock();
		if ((long int)turnstart == -1)
			return (-1);
		return ((double)1 / g_map.time);
	}
	now = clock();
	if ((long int)now == -1)
		return (-1);
	return (((double)1 / g_map.time) - ((double)(now - turnstart)
	/ CLOCKS_PER_SEC));
}

t_tval			*generate_timeval(double waittime)
{
	static t_tval		tval;
	double				sec;

	if (waittime < 0)
		waittime = 0;
	sec = (int)(floor(waittime / 1000000));
	tval.tv_sec = sec;
	tval.tv_usec = waittime - (double)sec;
	return (&tval);
}
