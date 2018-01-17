/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 21:36:56 by bgauci            #+#    #+#             */
/*   Updated: 2014/03/27 21:36:57 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "option.h"

t_opt	*init_opt(t_opt_fn def, int ac, char **av)
{
	t_opt		*opt;
	t_opt_elem	*new;

	new = (t_opt_elem*)malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	new->name = NULL;
	new->nbr_val = 2;
	new->fn = def;
	opt = (t_opt*)malloc(sizeof(*opt));
	if (opt == NULL)
		return (NULL);
	opt->elem = NULL;
	opt->def = new;
	opt->ac = ac;
	opt->av = av;
	opt->value = NULL;
	opt->i = 1;
	opt->max_opt = 2;
	return (opt);
}

void	add_opt(t_opt *opt, const char *name, unsigned int nbr_val, t_opt_fn fn)
{
	t_opt_elem	*new;

	new = (t_opt_elem*)malloc(sizeof(*new));
	if (new == NULL)
		return ;
	new->name = name;
	new->nbr_val = nbr_val + 1;
	new->fn = fn;
	new->next = opt->elem;
	opt->elem = new;
	if (opt->max_opt < new->nbr_val)
		opt->max_opt = new->nbr_val;
}

void	destroy_opt(t_opt **opt)
{
	t_opt_elem	*elem;
	t_opt_elem	*tmp;

	elem = (*opt)->elem;
	while (elem)
	{
		tmp = elem->next;
		free(elem);
		elem = tmp;
	}
	free((*opt)->value);
	if ((*opt)->def)
		free((*opt)->def);
	free(*opt);
	*opt = NULL;
}
