/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzak <jzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:53:33 by jzak              #+#    #+#             */
/*   Updated: 2014/03/27 21:25:43 by jzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "array.h"
#include "completion.h"

static int			find_bin(t_array *arr, const char *name, size_t n)
{
	size_t		i;

	i = 0;
	while (i < arr->used)
	{
		if (ft_strncmp(name, arr->data[i], n) == 0)
			return (i);
		++i;
	}
	return (-1);
}

void				complete_bin(t_array *arr, const char *word, size_t n)
{
	int				idx;

	idx = find_bin(g_comp->bin, word, n);
	if (idx == -1)
		return ;
	while (idx < (int)g_comp->bin->used
			&& ft_strncmp(word, g_comp->bin->data[idx], n) == 0)
	{
		array_push(arr, FT_STRJOIN(g_comp->bin->data[idx], "\n"));
		idx++;
	}
}
