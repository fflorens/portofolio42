/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh_histfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 16:29:20 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/27 21:50:37 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char			*sh_histfile_dynvar(void)
{
	static char	result[4096] = { 0 };
	char		*tmp;

	ft_bzero(result, 4096);
	if (sh_getenv("SH_HISTFILE") == NULL)
		tmp = ft_strdup("~/.42sh_history");
	else
		tmp = ft_strdup(sh_getenv("SH_HISTFILE"));
	sh_realpath(&tmp);
	if (ft_strlen(tmp) >= 4096)
	{
		ft_strdel(&tmp);
		return ("");
	}
	ft_strcat(result, tmp);
	ft_strdel(&tmp);
	return (result);
}
