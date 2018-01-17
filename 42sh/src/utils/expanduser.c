/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanduser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 12:23:25 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/25 20:39:48 by jzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include			<pwd.h>
#include			"shell.h"

static char			*process_tilduser(char **orig_ptr)
{
	char			*user;
	char			*old;
	struct passwd	*pw;
	int				i;

	i = 0;
	old = *orig_ptr;
	while (old[i] != '/' && old[i])
		i++;
	if (!(user = ft_strsub(old, 1, i - 1)))
		return (*orig_ptr);
	if ((pw = getpwnam(user)) == NULL || pw->pw_dir == NULL)
	{
		ft_strdel(&user);
		return (*orig_ptr);
	}
	if (*(pw->pw_dir) == '/' && *(pw->pw_dir + 1) == '\0')
		i++;
	*orig_ptr = FT_STRJOIN(pw->pw_dir, old + i);
	ft_strdel(&old);
	ft_strdel(&user);
	return (*orig_ptr);
}

char				*sh_expanduser(char **orig_ptr)
{
	char			*old;
	char			*home;

	if (!*orig_ptr || **orig_ptr == '\0')
		return (*orig_ptr);
	if ((old = *orig_ptr)[0] == '~' && old[1] && old[1] != '/')
		return (process_tilduser(orig_ptr));
	if (**orig_ptr != '~' || (home = sh_getenv("HOME")) == NULL)
		return (*orig_ptr);
	if ((old = *orig_ptr)[1] != '/' && old[1] != '\0')
		return (*orig_ptr);
	*orig_ptr = FT_STRJOIN(home, old + 1);
	ft_strdel(&old);
	return (*orig_ptr);
}
