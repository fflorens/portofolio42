/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigconf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 16:45:20 by nmokrane          #+#    #+#             */
/*   Updated: 2014/01/26 10:39:01 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sigconf.h"

void			sigconf(unsigned int flags, void (*signal_handler)(int))
{
	int			signum;
	int			sigflag;

	signum = 1;
	while (signum < 32)
	{
		sigflag = ((unsigned int)ft_powl(2, signum));
		if ((flags & sigflag) && signum != SIGKILL && signum != SIGSTOP)
			signal(signum, signal_handler);
		signum++;
	}
}
