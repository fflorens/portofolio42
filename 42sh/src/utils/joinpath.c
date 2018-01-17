/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joinpath.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 17:10:38 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/23 14:46:20 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdarg.h"
#include "utils.h"
#include "libft.h"

char			*sh_joinpath_va(int ignored, ...)
{
	va_list		va;
	va_list		cp;
	char		*str;
	char		*new;
	size_t		size;

	size = 0;
	va_start(va, ignored);
	va_copy(cp, va);
	while ((str = va_arg(cp, char*)) != NULL)
		size += ft_strlen(str) + 1;
	va_end(cp);
	if ((new = (char*)ft_calloc(sizeof(*new) * (size + 1))) == NULL)
		return (NULL);
	while ((str = va_arg(va, char*)) != NULL)
	{
		ft_strcat(new, str);
		ft_strcat(new, "/");
	}
	va_end(va);
	sh_realpath(&new);
	return (new);
}
