/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynbuf_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nil0x42@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 13:18:09 by nmokrane          #+#    #+#             */
/*   Updated: 2014/02/06 08:32:39 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "dynbuf.h"

static int	buf_split(t_dynbuf *buf, int pos, char **end)
{
	if (pos > (int)buf->pos)
		return (-1);
	if (pos < 0)
		pos += buf->pos + 1;
	if (pos < 0)
		return (-1);
	*end = NULL;
	if (pos < (int)buf->pos)
	{
		*end = (char*)ft_memdup((buf->ptr + pos), (buf->pos - pos));
		if (*end == NULL)
			return (-1);
		buf->pos = pos + 1;
	}
	return (buf->pos);
}

static int	buf_realloc(t_dynbuf *buf, int datasize)
{
	int		idx;

	while ((buf->pos + datasize) > buf->size)
	{
		idx = buf->size + buf->radix;
		if ((buf->ptr = (char*)ft_realloc(buf->ptr, buf->size, idx)) == NULL)
			return (-1);
		buf->size = idx;
	}
	return (0);
}

int			dynbuf_insert(t_dynbuf *buf, int pos, char *data, int datasize)
{
	int		idx;
	char	*end;

	if (datasize == 0)
		return (0);
	if (data == NULL)
		return (-1);
	if (datasize == -1)
		datasize = ft_strlen(data);
	if (buf_realloc(buf, datasize) < 0)
		return (-1);
	if (buf_split(buf, pos, &end) < 0)
		return (-1);
	idx = 0;
	while (idx < datasize)
	{
		buf->ptr[buf->pos] = data[idx];
		buf->pos += 1;
		idx += 1;
	}
	return (idx);
}
