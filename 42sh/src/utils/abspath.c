/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abspath.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 12:21:35 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/25 20:39:16 by jzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "shell.h"

char	*sh_abspath(char **orig_ptr)
{
	char	*pwd;
	char	*old;
	int		sz;

	sh_expanduser(orig_ptr);
	if (**orig_ptr == '/')
		return (*orig_ptr);
	sz = 256;
	pwd = (char *)ft_calloc(sz);
	while (!getcwd(pwd, sz))
	{
		sz += 256;
		ft_strdel(&pwd);
		pwd = (char *)ft_calloc(sz);
	}
	old = *orig_ptr;
	if ((*orig_ptr = FT_STRJOIN("/", pwd, "/", old)) != NULL)
		ft_strdel(&old);
	ft_strdel(&pwd);
	if (old)
		return (old);
	return (*orig_ptr);
}
