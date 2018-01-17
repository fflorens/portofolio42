/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 21:27:21 by bgauci            #+#    #+#             */
/*   Updated: 2014/03/26 19:38:13 by jzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_STRUCT_H
# define LEXER_STRUCT_H

# include "shell.h"
# include "lexer_struct.h"

/*
** Special redirecotr's fd meanings
*/
# define FD_UNSET			(-1)
# define FD_OUT_OF_RANGE	(-2)
# define FD_HEREDOC			(-3)

# define NB_E_ATOMIC_TOKEN	(13)

enum				e_token
{
	STRING = 1,
	OR,
	AND,
	IN,
	OUT,
	PIPE,
	IN_FD,
	OUT_FD,
	OUT_ADD,
	HEREDOC,
	SEMICOLON,
	AMPER,
	T_NULL,
	EOL,
	QUIET_PARSE_ERROR = 1000
};

typedef struct		s_token
{
	enum e_token	type;
	int				fd;
	char			*value;
}					t_token;

enum				e_atomic_token
{
	A_STRING = 0,
	A_IN = 1,
	A_OUT = 2,
	A_PIPE = 3,
	A_SEMICOLON = 4,
	A_AMPER = 5,
	A_DIGIT = 6,
	A_SEPARATOR = 7,
	A_EOL = 8,
	A_QUOTE = 9,
	A_DQUOTE = 10,
	A_A_SLACH = 11
};

typedef void		(*t_etat_fn)(t_token *, char **, char);

typedef struct		s_etat
{
	t_bool			transition[NB_E_ATOMIC_TOKEN];
	enum e_token	new_type;
	t_etat_fn		fn;
}					t_etat;

#endif
