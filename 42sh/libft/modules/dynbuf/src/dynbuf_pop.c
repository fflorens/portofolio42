/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynbuf_pop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nil0x42@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 18:41:17 by nmokrane          #+#    #+#             */
/*   Updated: 2014/02/06 08:30:53 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "dynbuf.h"

int			dynbuf_pop(t_dynbuf *buf, int pos, int datasize)
{
	if ((datasize <= 0) || (datasize > (int)buf->pos))
		return (-1);
	if ((pos < 0) || (pos >= (int)buf->pos))
		return (-1);
	if (pos + datasize < (int)buf->pos)
		ft_memmove(buf->ptr + buf->pos + datasize, buf->ptr + pos, datasize);
	buf->pos -= datasize;
	return (buf->pos);
}
