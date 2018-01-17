/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynvar_loader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 15:09:32 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/25 15:10:42 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "shell.h"
#include "dynvars.h"

static const t_dynvar	g_dynvar_tab[] = {
	{"RANDOM", random_dynvar},
	{"SECONDS", seconds_dynvar},
	{"PS1", ps1_dynvar},
	{"PS2", ps2_dynvar},
	{"SH_HISTFILE", sh_histfile_dynvar},
	{"SH_HISTSIZE", sh_histsize_dynvar},
	{"IFS", ifs_dynvar},
	{"?", char_question_dynvar},
	{"_", char_underscore_dynvar},
	{"$", char_dollar_dynvar},
	{NULL, NULL}
};

char					*dynvar_load(const char *name)
{
	int					i;

	i = 0;
	while (g_dynvar_tab[i].name)
	{
		if (ft_strequ(g_dynvar_tab[i].name, name))
			return (g_dynvar_tab[i].func());
		i++;
	}
	return (NULL);
}
