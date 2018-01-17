/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callback.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzak <jzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 13:32:55 by jzak              #+#    #+#             */
/*   Updated: 2014/03/27 21:43:34 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "printf.h"
#include "nboon.h"
#include "completion.h"

static int	ask_question(size_t nbr)
{
	char	c;

	nb_enable_raw(STDIN_FILENO);
	c = '\0';
	while ((c != 'y' && c != 'n'))
	{
		ft_printf("\r\nDisplay all %u possibilities? (y or n)", nbr);
		if (read(STDIN_FILENO, &c, 1) < 1)
			return (0);
	}
	write(STDIN_FILENO, "\n", 1);
	nb_disable_raw(STDIN_FILENO);
	return ((c == 'y') ? 1 : 0);
}

char		*autocomplete_line(const t_line *l, const char *word, size_t n)
{
	size_t	size;

	(void)l;
	array_clear(g_comp->result, free);
	complete_bin(g_comp->result, word, n);
	size = array_get_size(g_comp->result);
	if (size == 1)
		return (array_pop(g_comp->result));
	if (size < 200 || ask_question(size))
		completion_display(g_comp->result);
	return (NULL);
}
