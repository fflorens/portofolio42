/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigconf.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 16:46:37 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/25 20:00:08 by jzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGCONF_H
# define SIGCONF_H

# include <signal.h>
# include "libft.h"

enum	e_sigconf_sig
{
	SIG_HUP = 2,
	SIG_INT = 4,
	SIG_QUIT = 8,
	SIG_ILL = 16,
	SIG_TRAP = 32,
	SIG_ABRT = 64,
	SIG_EMT = 128,
	SIG_FPE = 256,
	SIG_KILL = 512,
	SIG_BUS = 1024,
	SIG_SEGV = 2048,
	SIG_SYS = 4096,
	SIG_PIPE = 8192,
	SIG_ALRM = 16384,
	SIG_TERM = 32768,
	SIG_URG = 65536,
	SIG_STOP = 131072,
	SIG_TSTP = 262144,
	SIG_CONT = 524288,
	SIG_CHLD = 1048576,
	SIG_TTIN = 2097152,
	SIG_TTOU = 4194304,
	SIG_IO = 8388608,
	SIG_XCPU = 16777216,
	SIG_XFSZ = 33554432,
	SIG_VTALRM = 67108864,
	SIG_PROF = 134217728,
	SIG_WINCH = 268435456,
	SIG_INFO = 536870912,
	SIG_USR1 = 1073741824,
	SIG_USR2 = 2147483648
};

enum	e_sigconf_sigs
{
	SIGS_ALL = (SIG_HUP | SIG_INT | SIG_QUIT | SIG_ILL | SIG_TRAP | SIG_ABRT
			| SIG_EMT | SIG_FPE | SIG_KILL | SIG_BUS | SIG_SEGV | SIG_SYS
			| SIG_PIPE | SIG_ALRM | SIG_TERM | SIG_URG | SIG_STOP | SIG_TSTP
			| SIG_CONT | SIG_CHLD | SIG_TTIN | SIG_TTOU | SIG_IO | SIG_XCPU
			| SIG_XFSZ | SIG_VTALRM | SIG_PROF | SIG_WINCH | SIG_INFO
			| SIG_USR1 | SIG_USR2),
	SIGS_TERM = (SIG_HUP | SIG_INT | SIG_PIPE | SIG_ALRM | SIG_TERM
			| SIG_XCPU | SIG_XFSZ | SIG_VTALRM | SIG_PROF
			| SIG_USR1 | SIG_USR2),
	SIGS_ERROR = (SIG_QUIT | SIG_ILL | SIG_TRAP | SIG_ABRT | SIG_EMT | SIG_FPE
			| SIG_BUS | SIG_SEGV | SIG_SYS),
	SIGS_STOP = (SIG_TSTP | SIG_TTIN | SIG_TTOU),
	SIGS_KBD = (SIG_INT | SIG_QUIT | SIG_TSTP),
	SIGS_JOBCTL = (SIG_TTIN | SIG_TTOU | SIG_CHLD)
};

void	sigconf(unsigned int flags, void (*signal_handler)(int));

#endif
