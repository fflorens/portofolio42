/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 13:47:47 by nmokrane          #+#    #+#             */
/*   Updated: 2014/02/22 13:47:54 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

int		ft_fmterror(const char *fmt, ...)
{
	va_list		ap;

	va_start(ap, fmt);
	ft_vdprintf(2, fmt, ap);
	va_end(ap);
	ft_dprintf(2, "\n");
	return (1);
}
