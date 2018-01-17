/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 23:22:59 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/27 22:48:48 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include <stdlib.h>
# include <errno.h>
# include <termios.h>
# include "libft.h"
# include "utils.h"

# define NAME "42sh"
# define PS1 "\x01\033[32m\x02[ケブラー会社]\x01\033[33m\x02$\x01\033[0m\x02 "
# define MAX_HISTORY_SIZE 65536

/*
** It seems that archlinux noes not have SIGEMT signal,
** so it is a patch for it
*/
# ifndef SIGEMT
#  define SIGEMT 84
# endif

/*
** Declaring t_bool (boolean) abstract type
*/
typedef int		t_bool;

# ifndef TRUE
#  define TRUE (1)
# endif

# ifndef FALSE
#  define FALSE (0)
# endif

/*
** Declaring NULL
*/
# ifndef NULL
#  define NULL ((void*)0)
# endif

/*
** env.c defines
*/
# define ENV_INIT		(0)
# define ENV_ADDSLOT	(1)
# define ENV_GETPTR		(2)
# define ENV_FREE		(3)

/*
** Error display functions
*/
# define ERROR(...) (ft_error_va(0, __VA_ARGS__, NULL))
# define FATAL_ERROR(...) (sh_exit(ft_error_va(0, NAME, __VA_ARGS__, NULL)))

# define ERRNO ft_strerror(errno)

/*
** Shell configuration structure
*/
typedef struct		s_shell
{
	pid_t			pgid;
	struct termios	tmodes;
	int				term;
	int				isatty;
}					t_shell;

/*
** Shell environment management (env.c)
*/
void				*sh_envmanager(int action);
char				*sh_getenv(const char *name);
int					sh_setenv(const char *name, const char *value,
																int overwrite);
int					sh_putenv(char *string);
int					sh_unsetenv(const char *name);
void				sh_rebuildenv(void);

/*
** getvar.c
** Returns a non malloc'ed string representing the requested shell variable
*/
const char			*sh_getvar(const char *name);

/*
** Signal handling functions (signals.c)
*/
void				sigmode_error(int signum);
void				sigmode_shell(int signum);
void				sigmode_child(int signum);

/*
** Path string shell handlers (path/?.c)
*/
char				*sh_expanduser(char **orig_ptr);
char				*sh_abspath(char **orig_ptr);
char				*sh_realpath(char **orig_ptr);

/*
** error.c
*/
int					sh_exit(int status);
void				help(void);
#endif
