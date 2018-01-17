/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 13:18:04 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/27 20:31:55 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

/*
** Basic builtin command structure
*/
typedef enum			e_fork
{
	FORK,
	NOFORK
}						t_fork;

typedef struct			s_builtin
{
	char				*name;
	int					(*exec)(char**);
	t_fork				type;
}						t_builtin;

extern t_builtin		g_builtin[];

/*
** Get builtin by name (builtin_loader.c)
*/
t_builtin				*builtin_load(char *name);

/*
** The list of available builtins prototypes
*/
int						exit_builtin(char **argv);
int						pwd_builtin(char **argv);
int						cd_builtin(char **argv);
int						env_builtin(char **argv);
int						setenv_builtin(char **argv);
int						unsetenv_builtin(char **argv);
int						echo_builtin(char **argv);
int						history_builtin(char **argv);
int						yes_builtin(char **argv);
int						builtin_qexclamation(char **argv);
int						wsavehist_builtin(char **av);

#endif
