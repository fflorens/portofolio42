/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzak <jzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 18:25:55 by jzak              #+#    #+#             */
/*   Updated: 2014/03/27 21:35:13 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "array.h"

t_array			*init_array(size_t size)
{
	t_array		*arr;

	arr = (t_array*)malloc(sizeof(*arr));
	if (arr == NULL || size == 0)
		exit(1);
	arr->used = 0;
	arr->size = size;
	arr->data = (char**)malloc(sizeof(char**) * (size));
	if (arr->data == NULL)
		exit(1);
	return (arr);
}

static void		grow_array(t_array *arr)
{
	char	**new;

	arr->size *= 2;
	new = (char**)malloc(sizeof(char**) * (arr->size));
	if (new == NULL)
		exit(1);
	ft_memcpy(new, arr->data, arr->used * sizeof(char*));
	arr->data = new;
}

void			array_push(t_array *arr, char *str)
{
	if (arr->used + 1 == arr->size)
		grow_array(arr);
	arr->data[arr->used++] = str;
}

void			*array_pop(t_array *arr)
{
	return (arr->data[--arr->used]);
}

void			destroy_array(t_array *arr, void (*free_fn)(void*))
{
	unsigned int		i;

	i = 0;
	while (i < arr->used)
	{
		free_fn(arr->data[i]);
		++i;
	}
	free(arr->data);
	free(arr);
}
