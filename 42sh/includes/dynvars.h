/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynvars.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 14:58:35 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/26 19:18:23 by jzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DYNVARS_H
# define DYNVARS_H

/*
** Basic dynvar command structure
*/
typedef struct	s_dynvar
{
	const char	*name;
	char		*(*func)(void);
}				t_dynvar;

/*
** Get dynvar by name (dynvar_loader.c)
*/
char			*dynvar_load(const char *name);

/*
** The list of available dynvars prototypes
*/
char			*random_dynvar(void);
char			*seconds_dynvar(void);
char			*ps1_dynvar(void);
char			*ps2_dynvar(void);
char			*sh_histfile_dynvar(void);
char			*sh_histsize_dynvar(void);
char			*ifs_dynvar(void);
char			*char_question_dynvar(void);
char			*char_underscore_dynvar(void);
char			*char_dollar_dynvar(void);

#endif
