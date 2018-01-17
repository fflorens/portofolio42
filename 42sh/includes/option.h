/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzak <jzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 19:19:16 by jzak              #+#    #+#             */
/*   Updated: 2014/03/27 23:12:21 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTION_H
# define OPTION_H

/*
** More powerful argv parser
** t_opt_fn and parse_opt return 1 on error
*/
typedef int				(*t_opt_fn)(char **av, int ac, void *userdata);

typedef struct			s_opt_elem
{
	const char			*name;
	unsigned int		nbr_val;
	t_opt_fn			fn;
	struct s_opt_elem	*next;
}						t_opt_elem;

typedef struct			s_opt
{
	t_opt_elem			*elem;
	t_opt_elem			*def;
	char				**av;
	int					ac;
	int					i;
	char				**value;
	unsigned int		max_opt;
}						t_opt;

t_opt					*init_opt(t_opt_fn def, int ac, char **av);
void					add_opt(t_opt *opt, const char *name,
								unsigned int nbr_val, t_opt_fn fn);
int						parse_opt(t_opt *opt, void *data);
void					destroy_opt(t_opt **opt);

/*
** Custum option
*/
int						opt_help(char **av, int ac, void *userdata);
int						opt_version(char **av, int ac, void *userdata);
int						opt_multiline(char **av, int ac, void *userdata);
int						opt_history_size(char **av, int ac, void *userdata);
int						opt_single_exec(char **av, int ac, void *userdata);
int						opt_rebuild(char **av, int ac, void *userdata);

#endif
