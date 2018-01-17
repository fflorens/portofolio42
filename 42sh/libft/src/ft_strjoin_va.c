/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_va.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 17:20:20 by nmokrane          #+#    #+#             */
/*   Updated: 2014/02/05 12:00:15 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

char	*ft_strjoin_va(int ignored, ...)
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
		size += ft_strlen(str);
	va_end(cp);
	if ((new = (char*)ft_calloc(sizeof(*new) * (size + 1))) == NULL)
		return (NULL);
	while ((str = va_arg(va, char*)) != NULL)
		ft_strcat(new, str);
	va_end(va);
	return (new);
}
