/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 21:37:06 by bgauci            #+#    #+#             */
/*   Updated: 2014/03/27 21:40:49 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"
#include "option.h"

static int			error(const char *fmt, ...)
{
	va_list		va;

	ft_dprintf(2, "42sh: ");
	ft_dprintf(2, "error: ");
	va_start(va, fmt);
	ft_vdprintf(2, fmt, va);
	va_end(va);
	return (1);
}

static t_opt_elem	*get_opt(t_opt_elem *opt, const char *str)
{
	while (opt != NULL)
	{
		if (ft_strcmp(opt->name, str) == 0)
			return (opt);
		opt = opt->next;
	}
	return (NULL);
}

static int			exec_opt(t_opt *opt, char *str, void *data)
{
	unsigned int	i;
	t_opt_elem		*curr;
	int				nbr;

	i = 1;
	if ((curr = get_opt(opt->elem, str)) == NULL)
		return (error("illegal option -- %s\n", str));
	opt->i++;
	nbr = curr->nbr_val - 1;
	opt->value[0] = str;
	while (i < curr->nbr_val && opt->i < opt->ac)
	{
		if (opt->av[opt->i][0] == '-' && opt->av[opt->i][1] != '\0')
			return (error("illegal option -- %s\n", &opt->av[opt->i][1]));
		opt->value[i++] = opt->av[opt->i];
		opt->i++;
	}
	if (i != curr->nbr_val)
		return (error("expect %d argument(s) for option %s\n", nbr, str));
	if (curr->fn(opt->value, curr->nbr_val, data))
		return (1);
	return (0);
}

int					parse_opt(t_opt *opt, void *data)
{
	opt->value = (char**)ft_calloc(sizeof(char*) * (opt->max_opt));
	if (opt->value == NULL)
		return (1);
	while (opt->i < opt->ac)
	{
		if (opt->av[opt->i][0] == '-' && opt->av[opt->i][1] != '\0')
		{
			if (exec_opt(opt, &opt->av[opt->i][1], data))
				return (1);
		}
		else
		{
			opt->value[0] = "";
			opt->value[1] = opt->av[opt->i];
			if (opt->def == NULL
					&& opt->def->fn(opt->value, opt->def->nbr_val, data))
				return (1);
			++opt->i;
		}
	}
	ft_memdel((void**)&opt->value);
	return (0);
}
