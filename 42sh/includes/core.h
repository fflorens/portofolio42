/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 13:56:38 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/27 22:49:17 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include <time.h>
# include "structs.h"
# include "option.h"
# define ENV_REBUILD_ENABLED 1

/*
** The core module is related to the main global variable, used
** in some points by the shell
*/
typedef struct	s_core
{
	int			history_size;
	int			multiline;
	t_opt		*opt;
	time_t		birth_time;
	int			last_status;
	char		*self_bin;
	char		**path_list;
	char		*current_cmdline;
	t_command	*current_cmdlist;
}				t_core;

extern t_core	g_core;

/*
** src/core/core.c (constructor && destructor)
*/
void			core_init(char *bin_name);
void			core_free(void);

/*
** src/core/path_list.c
*/
void			core_update_path_list(void);
void			core_free_path_list(void);

#endif
