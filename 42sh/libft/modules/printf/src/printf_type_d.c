/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_type_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 18:42:13 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/25 22:49:36 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*ptf_type_long_d(t_ptf_flags f, va_list ap)
{
	char	*result;

	result = ft_ltoa(va_arg(ap, long));
	ptf_fmt_int(&f, &result);
	return (result);
}

char		*ptf_type_d(t_ptf_flags f, va_list ap)
{
	char	*result;

	if (TAG(f, 'l'))
		return (ptf_type_long_d(f, ap));
	result = ft_itoa((int)va_arg(ap, int));
	ptf_fmt_int(&f, &result);
	return (result);
}

char		*ptf_type_long_u(t_ptf_flags f, va_list ap)
{
	char	*result;

	(void)f;
	result = ft_ultoa(va_arg(ap, unsigned long));
	ptf_fmt_int(&f, &result);
	return (result);
}

char		*ptf_type_u(t_ptf_flags f, va_list ap)
{
	char	*result;

	if (TAG(f, 'l'))
		return (ptf_type_long_u(f, ap));
	result = ft_uitoa(va_arg(ap, unsigned int));
	ptf_fmt_int(&f, &result);
	return (result);
}
