/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_va.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 13:47:34 by nmokrane          #+#    #+#             */
/*   Updated: 2014/02/22 13:47:38 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

int		ft_error_va(int ignored, ...)
{
	va_list		ap;
	char		*str;

	va_start(ap, ignored);
	if ((str = va_arg(ap, char*)) == NULL)
	{
		ft_dprintf(2, "\n");
		return (1);
	}
	ft_dprintf(2, str);
	while ((str = va_arg(ap, char*)) != NULL)
		ft_dprintf(2, ": %s", str);
	va_end(ap);
	ft_dprintf(2, "\n");
	return (1);
}
