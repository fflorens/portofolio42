/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrcarembole <mrcarembole@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 17:45:47 by mrcarembole       #+#    #+#             */
/*   Updated: 2014/03/26 19:29:03 by jzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

char		*sh_joinpath_va(int ignored, ...);

char		*sh_getcmdstr(char *cmdline);

char		*sh_expanduser(char **orig_ptr);
char		*sh_abspath(char **orig_ptr);
char		*sh_realpath(char **orig_ptr);
char		*sh_expandvar(char **orig_ptr);

char		**sh_globalize(char *pattern);

/*
** fflorens's dirty function
*/
void		sh_closepipe(int *tube);

#endif
