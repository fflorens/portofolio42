/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/11 18:17:51 by fflorens          #+#    #+#             */
/*   Updated: 2014/05/11 23:22:13 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <term.h>
#include "debug.h"
#include "philosophe.h"
#define D_TERMIOS struct termios

extern int			g_fd;

static void			sig_sigint(int sig)
{
	t_table			*table;

	table = get_table();
	(void)sig;
	restore_term();
	g_fd = STDOUT_FILENO;
	g_forcequit = 1;
	display(table->philotab, table->sticktab, table->turn);
	exit(EXIT_FAILURE);
}

static int			ft_putsclear(int j)
{
	int			i;

	i = write(g_fd, &j, 1);
	return (i);
}

int					set_term(void)
{
	char		*term;
	D_TERMIOS	termios;

	signal(SIGINT, sig_sigint);
	if (isatty(STDIN_FILENO) == 0 || (g_fd = open("/dev/tty", O_WRONLY)) == -1)
		return (EXIT_FAILURE);
	if (!(term = getenv("TERM")) || tgetent(NULL, term) < 1)
	{
		close(g_fd);
		return (EXIT_FAILURE);
	}
	put_str_fd(tgetstr((char *)"ti", NULL), g_fd);
	put_str_fd(tgetstr((char *)"vi", NULL), g_fd);
	tcgetattr(STDIN_FILENO, &termios);
	termios.c_lflag &= ~(ECHO);
	termios.c_lflag &= ~(ICANON);
	termios.c_cc[VTIME] = 0;
	termios.c_cc[VMIN] = 1;
	tcsetattr(STDIN_FILENO, TCSANOW, &termios);
	return (EXIT_SUCCESS);
}

void				restore_term(void)
{
	struct termios	termios;

	tcgetattr(STDIN_FILENO, &termios);
	termios.c_lflag |= (ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &termios);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &termios);
	put_str_fd(tgetstr((char *)"ve", NULL), g_fd);
	put_str_fd(tgetstr((char *)"te", NULL), g_fd);
	g_fd = STDOUT_FILENO;
}

void				ft_clear_display(void)
{
	tputs(tgoto(tgetstr((char *)"cm", NULL), 0, 0), g_fd, ft_putsclear);
	tputs(tgetstr((char *)"cl", NULL), g_fd, ft_putsclear);
	tputs(tgetstr((char *)"te", NULL), g_fd, ft_putsclear);
	tputs(tgetstr((char *)"ti", NULL), g_fd, ft_putsclear);
	tputs(tgoto(tgetstr((char *)"cm", NULL), 0, 0), g_fd, ft_putsclear);
	tputs(tgetstr((char *)"cl", NULL), g_fd, ft_putsclear);
}
