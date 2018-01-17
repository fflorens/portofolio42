/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 17:09:58 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/27 21:43:58 by jzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "printf.h"
#include "parser.h"
#include "nboon.h"

extern enum e_token	g_parse_error;

static t_bool		value_to_fd(char *value, int *fd)
{
	int				intlen;

	intlen = ft_getnbr(value, fd);
	if (intlen == 0 || value[intlen] != '\0')
	{
		*fd = FD_UNSET;
		return (FALSE);
	}
	return (TRUE);
}

static void			build_redirector(t_redirector *redirector, t_token *token)
{
	int				new_fd;

	if (token->type == IN_FD || token->type == OUT_FD)
	{
		if (value_to_fd(token->value, &new_fd) == TRUE)
			redirector->new_fd = new_fd;
		else
			redirector->file = ft_strdup(token->value);
	}
	else
		redirector->file = ft_strdup(token->value);
}

static void			build_heredoc(t_redirector *redirector, t_token *token)
{
	char			*ln;
	int				status;

	redirector->heredoc_label = ft_strdup(token->value);
	redirector->heredoc_buf = dynbuf_new(64);
	while ((status = nb_get_line(sh_getvar("PS2"), &ln)) != NB_EXIT)
	{
		if (ft_strequ(ln, redirector->heredoc_label) || status == NB_INTERRUPT)
			break ;
		if (status == NB_ERROR)
			ft_dprintf(2, "%s\n", "The characters were added to the heredoc.");
		dynbuf_write(redirector->heredoc_buf, ln, ft_strlen(ln));
		dynbuf_write(redirector->heredoc_buf, "\n", 1);
		ft_strdel(&ln);
	}
	if (ln == NULL)
		g_parse_error = QUIET_PARSE_ERROR;
	ft_strdel(&ln);
}

t_redirector		*get_redirector(t_token token, int id)
{
	t_redirector	*redirector;

	if (token.value == NULL)
	{
		parse_error(&token);
		return (NULL);
	}
	redirector = redirector_new();
	redirector->open_flag |= ((token.type == OUT_ADD) ? O_APPEND : O_TRUNC);
	if (token.type == IN || token.type == IN_FD)
		redirector->open_flag = O_RDONLY;
	redirector->old_fd = token.fd;
	if (token.type == HEREDOC && id != 0)
		g_parse_error = token.type;
	else if (token.type == HEREDOC)
		build_heredoc(redirector, &token);
	else
		build_redirector(redirector, &token);
	if (g_parse_error)
		redirector_del(&redirector);
	return (redirector);
}
