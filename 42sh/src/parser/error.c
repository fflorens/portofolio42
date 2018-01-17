/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 20:23:48 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/27 21:42:31 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "printf.h"

extern enum e_token		g_parse_error;

static const char	g_tpl[] = "%s: syntax error near unexpected token `%s'\n";
static const char	*g_token_repr[] = {
	NULL, "string", "||", "&&", "<", ">", "|", "<&",
	">&", ">>", "<<", ";", "&", "t_null", "newline"
};

void					*parse_error(t_token *token)
{
	g_parse_error = token->type;
	free_token(*token);
	return (NULL);
}

t_bool					print_parse_error(void)
{
	if (g_parse_error == 0)
		return (FALSE);
	if (g_parse_error != QUIET_PARSE_ERROR)
		ft_dprintf(2, g_tpl, NAME, g_token_repr[g_parse_error]);
	return (TRUE);
}
