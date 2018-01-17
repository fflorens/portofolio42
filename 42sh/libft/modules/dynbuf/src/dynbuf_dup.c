/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynbuf_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nil0x42@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 17:27:31 by nmokrane          #+#    #+#             */
/*   Updated: 2014/02/09 17:30:28 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "dynbuf.h"

t_dynbuf		*dynbuf_dup(t_dynbuf *buf)
{
	t_dynbuf		*new;

	new = (t_dynbuf*)ft_memdup(buf, sizeof(t_dynbuf));
	new->ptr = (char*)ft_memdup(buf->ptr, buf->size);
	return (new);
}
