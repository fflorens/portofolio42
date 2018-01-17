/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/22 18:36:16 by bgauci            #+#    #+#             */
/*   Updated: 2014/06/25 20:55:52 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
# define READ_H

# include "struct_reseau.h"
# include "zappy.h"

typedef struct	s_tab
{
	char		*name;
	enum e_cmd	cmd;
}				t_tab;

void			snapshot(void);
void			read_fd(t_connexion *client);
bool			can_exe(t_connexion *client);
void			exe(t_connexion *current);
void			exe_ihm(t_connexion *current);

#endif
