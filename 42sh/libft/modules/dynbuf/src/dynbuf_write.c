/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynbuf_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 12:20:13 by nmokrane          #+#    #+#             */
/*   Updated: 2014/02/05 18:39:21 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "dynbuf.h"

int			dynbuf_write(t_dynbuf *buf, char *data, int datasize)
{
	return (dynbuf_insert(buf, -1, data, datasize));
}
