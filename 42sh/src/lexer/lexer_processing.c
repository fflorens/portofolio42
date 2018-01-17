/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 16:02:11 by bgauci            #+#    #+#             */
/*   Updated: 2014/03/26 16:40:09 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "nboon.h"
#include "shell.h"
#include "lexer.h"
#include "utils.h"

extern char	*g_line;
extern int	g_position;

#define GAIN(x, y) ((x) = (y))

static int	complete_line(t_token *token, char *tmp, char current)
{
	char	*txt;
	char	*mem;

	txt = NULL;
	while (g_line[g_position] == '\0')
	{
		nb_get_line(sh_getvar("PS2"), &txt);
		if (txt == NULL)
		{
			if (tmp)
				free(tmp);
			fd_reforge_eol(token);
			return (0);
		}
		if (current != '\\')
		{
			g_line = FT_STRJOIN(GAIN(mem, g_line), "\n");
			free(mem);
		}
		g_line = FT_STRJOIN(GAIN(mem, g_line), txt);
		free(mem);
		free(txt);
	}
	return (1);
}

void		fill_quote(t_token *token, char **tmp, char current)
{
	if (g_position++ && (complete_line(token, *tmp, current) == 0))
		return ;
	while (g_line[g_position] != current)
	{
		*tmp = ft_strtab_add(*tmp, '\\');
		*tmp = ft_strtab_add(*tmp, g_line[g_position]);
		if (g_position++ && (complete_line(token, *tmp, current) == 0))
			return ;
	}
	if (*tmp == NULL)
		*tmp = ft_strtab_add(*tmp, '\0');
}

void		fill_dquote(t_token *token, char **tmp, char current)
{
	if (g_position++ && (complete_line(token, *tmp, current) == 0))
		return ;
	while (g_line[g_position] != current)
	{
		*tmp = ft_strtab_add(*tmp, '\\');
		if (g_line[g_position] == '\\')
		{
			if (g_position++ && (complete_line(token, *tmp, current) == 0))
				return ;
			if (g_line[g_position] != current && g_line[g_position] != '\\')
				*tmp = ft_strtab_add(ft_strtab_add(*tmp, '\\'), '\\');
		}
		*tmp = ft_strtab_add(*tmp, g_line[g_position]);
		if (g_position++ && (complete_line(token, *tmp, current) == 0))
			return ;
	}
	if (*tmp == NULL)
		*tmp = ft_strtab_add(*tmp, '\0');
}

void		fill_eluion(t_token *token, char **tmp, char current)
{
	*tmp = ft_strtab_add(*tmp, '\\');
	if (g_position++ && (complete_line(token, *tmp, current) == 0))
		return ;
	*tmp = ft_strtab_add(*tmp, g_line[g_position]);
}

void		free_lexer(void)
{
	free(g_line);
	g_line = NULL;
}
