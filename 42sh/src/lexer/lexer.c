/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 15:24:15 by bgauci            #+#    #+#             */
/*   Updated: 2014/03/26 19:22:20 by jzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char	*g_line = NULL;
int		g_position = 0;
t_bool	g_prev = FALSE;

t_etat	g_tab[19] =
{
	{{13, 6, 9, 4, 1, 2, 12, 0, 15, 16, 17, 18}, STRING, NULL},
	{{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, SEMICOLON, NULL},
	{{-1, -1, -1, -1, -1, 3, -1, -1, -1, -1, -1, -1}, AMPER, NULL},
	{{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, AND, NULL},
	{{-1, -1, -1, 5, -1, -1, -1, -1, -1, -1, -1, -1}, PIPE, NULL},
	{{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, OR, NULL},
	{{13, 7, -1, -1, -1, 8, 13, 14, -1, 16, 17, 18}, IN, fd_redir},
	{{13, -1, -1, -1, -1, -1, 13, 14, -1, 16, 17, 18}, HEREDOC, NULL},
	{{13, -1, -1, -1, -1, -1, 13, 14, -1, 16, 17, 18}, IN_FD, NULL},
	{{13, -1, 10, -1, -1, 11, 13, 14, -1, 16, 17, 18}, OUT, fd_redir},
	{{13, -1, -1, -1, -1, -1, 13, 14, -1, 16, 17, 18}, OUT_ADD, NULL},
	{{13, -1, -1, -1, -1, -1, 13, 14, -1, 16, 17, 18}, OUT_FD, NULL},
	{{13, 6, 9, -1, -1, -1, 12, -1, -1, 16, 17, 18}, T_NULL, fill_tmp},
	{{13, -1, -1, -1, -1, -1, 13, -1, -1, 16, 17, 18}, T_NULL, fill_tmp},
	{{13, -1, -1, -1, -1, -1, 13, 14, -1, 16, 17, 18}, T_NULL, NULL},
	{{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, EOL, NULL},
	{{13, -1, -1, -1, -1, -1, 13, -1, -1, 16, 17, 18}, T_NULL, fill_quote},
	{{13, -1, -1, -1, -1, -1, 13, -1, -1, 16, 17, 18}, T_NULL, fill_dquote},
	{{13, -1, -1, -1, -1, -1, 13, -1, -1, 16, 17, 18}, T_NULL, fill_eluion},
};

void		previous_token(void)
{
	g_prev = TRUE;
}

void		lexer(char *new_line)
{
	if (g_line != NULL)
	{
		free(g_line);
		g_line = NULL;
	}
	g_line = ft_strdup(new_line);
	g_position = 0;
	g_prev = FALSE;
}

static enum	e_atomic_token def_atom_token(char c)
	{
	if (c == '<')
		return (A_IN);
	if (c == '>')
		return (A_OUT);
	if (c == '|')
		return (A_PIPE);
	if (c == ';')
		return (A_SEMICOLON);
	if (c == '&')
		return (A_AMPER);
	if (c == ' ' || c == '\t')
		return (A_SEPARATOR);
	if (c == '\0')
		return (A_EOL);
	if (c == '\'')
		return (A_QUOTE);
	if (c == '"')
		return (A_DQUOTE);
	if (c == '\\')
		return (A_A_SLACH);
	if (c >= '0' && c <= '9')
		return (A_DIGIT);
	return (A_STRING);
	}

static void	automaton(t_token *token, int etat, char *tmp)
{
	enum e_atomic_token	type;

	if (g_tab[etat].new_type != T_NULL)
		token->type = g_tab[etat].new_type;
	if (g_tab[etat].fn)
		g_tab[etat].fn(token, &tmp, g_line[g_position]);
	if (g_line[g_position] != '\0')
		g_position++;
	type = def_atom_token(g_line[g_position]);
	if (g_tab[etat].transition[type] >= 0)
	{
		automaton(token, g_tab[etat].transition[type], tmp);
		return ;
	}
	if (token->type != EOL)
		token->value = tmp;
}

t_token		get_next_token(void)
{
	static t_token		token = {T_NULL, 0, NULL};
	enum e_atomic_token	type;
	char				*tmp;

	tmp = NULL;
	if (g_prev)
	{
		g_prev = FALSE;
		return (token);
	}
	token.type = STRING;
	token.fd = 0;
	token.value = NULL;
	type = def_atom_token(g_line[g_position]);
	if (g_tab[0].transition[type] >= 0)
		automaton(&token, g_tab[0].transition[type], tmp);
	return (token);
}
