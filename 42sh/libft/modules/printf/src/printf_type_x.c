/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_type_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 18:42:33 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/25 22:50:13 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char			*ptf_type_p(t_ptf_flags f, va_list ap)
{
	char		*result;
	char		*hex_ptr;

	(void)f;
	result = ft_strnew((sizeof(unsigned long) * 2) + 2);
	hex_ptr = ft_ltobase(va_arg(ap, unsigned long), 16);
	ft_strcat(&result[0], "0x");
	ft_strcat(&result[2], hex_ptr);
	ft_strdel(&hex_ptr);
	return (result);
}

char			*ptf_type_long_o(t_ptf_flags f, va_list ap)
{
	char		*result;

	(void)f;
	result = ft_ltobase(va_arg(ap, unsigned long), 8);
	ptf_fmt_int(&f, &result);
	return (result);
}

char			*ptf_type_o(t_ptf_flags f, va_list ap)
{
	char		*result;
	char		*tmp;

	if (TAG(f, 'l'))
		return (ptf_type_long_o(f, ap));
	result = ft_itobase(va_arg(ap, unsigned int), 8);
	if (TAG(f, '#'))
	{
		tmp = result;
		result = FT_STRJOIN("0", tmp);
		ft_strdel(&tmp);
	}
	ptf_fmt_int(&f, &result);
	return (result);
}

char			*ptf_type_long_x(t_ptf_flags f, va_list ap)
{
	char		*result;
	int			i;

	result = ptf_type_x(f, ap);
	i = 0;
	while (result[i] != '\0')
	{
		result[i] = (char)ft_toupper((int)result[i]);
		i++;
	}
	ptf_fmt_int(&f, &result);
	return (result);
}

char			*ptf_type_x(t_ptf_flags f, va_list ap)
{
	char		*result;
	char		*tmp;

	if (TAG(f, 'l'))
		result = ft_ltobase(va_arg(ap, unsigned long), 16);
	else
		result = ft_itobase(va_arg(ap, unsigned int), 16);
	if (TAG(f, '#'))
	{
		tmp = result;
		result = FT_STRJOIN("0x", tmp);
		ft_strdel(&tmp);
	}
	ptf_fmt_int(&f, &result);
	return (result);
}
