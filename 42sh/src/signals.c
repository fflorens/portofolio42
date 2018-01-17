/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 20:19:31 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/27 21:29:44 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "shell.h"
#include "printf.h"

void			sigmode_error(int signum)
{
	const char	*tab[100] = { 0 };

	tab[SIGQUIT] = "Quit";
	tab[SIGILL] = "Illegal hardware instruction";
	tab[SIGTRAP] = "Trace trap";
	tab[SIGABRT] = "Abort trap";
	tab[SIGEMT] = "Emulate instruction executed";
	tab[SIGFPE] = "Floating-point exception";
	tab[SIGBUS] = "Bus error";
	tab[SIGSEGV] = "Segmentation fault";
	tab[SIGSYS] = "Non existent system call invoked";
	if (tab[signum] != NULL)
		ft_dprintf(2, "\r%s: %d\n", tab[signum], signum);
}

void			sigmode_shell(int signum)
{
	if (signum == SIGINT)
		ft_putchar('\n');
}

void			sigmode_child(int signum)
{
	if (signum == SIGTSTP)
		kill(getpid(), SIGINT);
}
