/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzak <jzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 18:26:11 by jzak              #+#    #+#             */
/*   Updated: 2014/03/27 21:35:42 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "array.h"

void			array_sort(t_array *arr, t_cmp_fn cmp)
{
	size_t		i;
	size_t		j;
	void		*elem;

	i = 1;
	while (i < arr->used)
	{
		elem = arr->data[i];
		j = i;
		while (j > 0 && cmp(arr->data[j - 1], elem) > 0)
		{
			arr->data[j] = arr->data[j - 1];
			--j;
		}
		arr->data[j] = elem;
		++i;
	}
}

void			array_riter(t_array *arr, void (*fn)(const char*))
{
	size_t		i;

	i = arr->used;
	while (i > 0)
	{
		fn(arr->data[--i]);
	}
}

void			array_iter(t_array *arr, void (*fn)(const char*))
{
	size_t		i;

	i = 0;
	while (i < arr->used)
	{
		fn(arr->data[i]);
		++i;
	}
}

int				array_find(t_array *arr, const char *name)
{
	char	**data;
	int		min;
	int		max;

	data = arr->data;
	max = arr->used;
	min = 0;
	while (min < max)
	{
		if (ft_strcmp(name, data[min]) == 0)
			return (min);
		++min;
	}
	return (-1);
}
