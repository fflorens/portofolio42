/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynbuf_tostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nil0x42@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 08:16:55 by nmokrane          #+#    #+#             */
/*   Updated: 2014/02/06 08:20:26 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "dynbuf.h"

char		*dynbuf_tostr(t_dynbuf *buf)
{
	char	*str;

	str = ft_strnew(buf->pos);
	ft_memcpy(str, buf->ptr, buf->pos);
	return (str);
}
