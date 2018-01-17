/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 14:30:12 by bgauci            #+#    #+#             */
/*   Updated: 2014/03/26 16:40:30 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "shell.h"
# include "lexer_struct.h"

/*
** Lexer public functions
*/
void					previous_token(void);
void					lexer(char *new_line);
t_token					get_next_token(void);
void					fill_tmp(t_token *token, char **tmp, char current);
void					fd_redir(t_token *token, char **tmp, char current);
void					fill_quote(t_token *token, char **tmp, char current);
void					fill_dquote(t_token *token, char **tmp, char current);
void					fill_eluion(t_token *token, char **tmp, char current);
char					*ft_strtab_add(char *txt, char c);
void					free_token(t_token token);
void					free_lexer(void);
void					fd_reforge_eol(t_token *token);

#endif
