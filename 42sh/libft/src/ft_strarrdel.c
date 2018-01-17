/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 23:36:27 by nmokrane          #+#    #+#             */
/*   Updated: 2014/02/28 16:03:58 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function deletes an array of null terminated strings freeing each
** element and then the array pointer. If the given size if negative, it
** is assumed that the array is null terminated, and ft_arrlen() is then used
** to get array length. Otherwise, only size elements are deleted.
*/
void		ft_strarrdel(char ***array_ptr, int size)
{
	char	**array;
	int		i;

	array = *array_ptr;
	i = 0;
	if (size < 0)
		size = ft_strarrlen((const char**)array);
	while (i < size)
	{
		ft_strdel(&array[i]);
		i++;
	}
	ft_memdel((void**)(array_ptr));
}
