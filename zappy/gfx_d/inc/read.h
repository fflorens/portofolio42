/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/22 18:36:16 by bgauci            #+#    #+#             */
/*   Updated: 2014/06/25 17:25:48 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
# define READ_H

# include "struct_reseau.h"
//# include "zappy.h"

typedef void	(*t_fn)(char *line);

typedef struct	s_tab
{
	const char	*name;
	t_fn		fn;
}				t_tab;

void			read_fd(int fd);
bool			can_exe(char *buff);
void			exe(char **buff);
void			test(char *lolo);
void			snapshot(char *lolo);

#endif
