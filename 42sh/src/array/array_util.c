/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzak <jzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 13:35:38 by jzak              #+#    #+#             */
/*   Updated: 2014/03/27 18:22:21 by jzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "dynbuf.h"
#include "array.h"

/*
** Remove the last entry in the array
*/
void			array_clear(t_array *arr, void (*free_fn)(void*))
{
	unsigned int		i;

	i = 0;
	if (free_fn != NULL)
	{
		while (i < arr->used)
		{
			free_fn(arr->data[i]);
			++i;
		}
	}
	arr->used = 0;
}

unsigned int	array_get_size(t_array *arr)
{
	return (arr->used);
}

char			*array_to_str(t_array *arr, char *str)
{
	char				*ret;
	unsigned int		i;
	size_t				len;
	t_dynbuf			*buf;

	len = ft_strlen(str);
	if ((buf = dynbuf_new(4096)) == NULL)
		return (NULL);
	i = 0;
	while (i < arr->used)
	{
		dynbuf_write(buf, arr->data[i], ft_strlen(arr->data[i]));
		if (str != NULL)
			dynbuf_write(buf, str, len);
		++i;
	}
	ret = dynbuf_tostr(buf);
	dynbuf_del(&buf);
	return (ret);
}
