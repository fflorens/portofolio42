/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynbuf_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nil0x42@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 09:59:56 by nmokrane          #+#    #+#             */
/*   Updated: 2014/02/09 10:01:29 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dynbuf.h"

void		dynbuf_clear(t_dynbuf *buf)
{
	buf->pos = 0;
}
