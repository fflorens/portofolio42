/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:47:16 by fflorens          #+#    #+#             */
/*   Updated: 2013/12/22 18:54:46 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "fdf.h"
#include "gnl.h"

void		*ft_memalloc(size_t size)
{
	char	*out;

	if (size)
		out = malloc(size);
	else
		out = NULL;
	if (out)
		ft_bzero(out, size);
	return (out);
}
