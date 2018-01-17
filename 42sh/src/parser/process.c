/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 17:00:09 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/27 21:43:28 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

/*
** A process is a sequence of one or more STRING tokens, and zero or more
** IN, OUT, OUT_FD, IN_FD, HEREDOC or OUT_ADD token, in any order.
** Any other token marks the end of the process.
*/

extern enum e_token		g_parse_error;

static const enum e_token	g_redirector[] = {
	IN, OUT, IN_FD, OUT_FD, OUT_ADD, HEREDOC, 0
};

static void				add_argument(t_process *process, t_token *token)
{
	size_t		argc;
	size_t		old_size;
	size_t		new_size;

	if (process->argv == NULL)
		process->argv = FT_NEWPTR(char*, 1);
	argc = 0;
	while (process->argv[argc] != NULL)
		argc++;
	old_size = (argc + 1) * sizeof(t_token*);
	new_size = old_size + sizeof(t_token*);
	process->argv = ft_realloc(process->argv, old_size, new_size);
	if (token->value != NULL)
		process->argv[argc] = ft_strdup(token->value);
}

static t_bool			is_redirector(t_token *token)
{
	int							i;

	i = 0;
	while (g_redirector[i])
	{
		if (token->type == g_redirector[i])
			return (TRUE);
		i++;
	}
	return (FALSE);
}

t_process				*get_process(int id)
{
	t_process			*process;
	t_token				tok;
	t_redirector		*redir;

	process = process_new();
	while (TRUE)
	{
		if ((tok = get_next_token()).type == STRING)
			add_argument(process, &tok);
		else if (is_redirector(&tok) && (redir = get_redirector(tok, id)) != 0)
			redirector_add(&process->first_redirector, redir);
		else
			break ;
		free_token(tok);
	}
	if (process->argv == NULL)
	{
		if (!g_parse_error)
			g_parse_error = tok.type;
		free_token(tok);
		process_del(&process);
		return (NULL);
	}
	previous_token();
	return (process);
}
