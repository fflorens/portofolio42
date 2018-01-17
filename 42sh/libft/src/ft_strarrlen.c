/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nil0x42@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 11:49:16 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/27 22:18:45 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns length of the given null terminated array of strings.
*/
size_t		ft_strarrlen(const char **array)
{
	size_t		len;

	len = 0;
	while (array && *array++ != NULL)
		len++;
	return (len);
}
