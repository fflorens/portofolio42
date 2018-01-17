/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 17:40:35 by bgauci            #+#    #+#             */
/*   Updated: 2014/03/27 20:06:42 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	free_token(t_token token)
{
	if (token.value)
		free(token.value);
}

char	*ft_strtab_add(char *txt, char c)
{
	char			*res;
	unsigned int	i;

	if (txt == NULL)
	{
		res = malloc(sizeof(char) * 2);
		res[0] = c;
		res[1] = '\0';
		return (res);
	}
	res = malloc(sizeof(char) * (ft_strlen(txt) + 2));
	i = 0;
	while (i < ft_strlen(txt))
	{
		res[i] = txt[i];
		i++;
	}
	res[i] = c;
	res[i + 1] = '\0';
	free(txt);
	return (res);
}

void	fd_reforge_eol(t_token *token)
{
	free_token(*token);
	token->type = EOL;
	token->fd = 0;
	token->value = NULL;
}

void	fd_redir(t_token *token, char **tmp, char current)
{
	(void)current;
	if (*tmp)
	{
		if (ft_getnbr(*tmp, &(token->fd)) == 0)
			token->fd = FD_OUT_OF_RANGE;
		free(*tmp);
		*tmp = NULL;
	}
	else
		token->fd = ((token->type == IN) ? 0 : 1);
}

void	fill_tmp(t_token *token, char **tmp, char current)
{
	(void)token;
	*tmp = ft_strtab_add(*tmp, current);
}
