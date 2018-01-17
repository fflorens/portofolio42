/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_type_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 18:42:23 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/25 20:41:41 by jzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		fill_str(char **str, t_ptf_flags *f)
{
	char		*fill;
	int			strlen;
	char		*newstr;

	strlen = ft_strlen(*str);
	if (f->length)
	{
		fill = ft_strnew(ft_abs(f->length));
		if (strlen < ft_abs(f->length))
			ft_memset(fill, ' ', ft_abs(f->length) - strlen);
		if (f->length < 0)
			newstr = FT_STRJOIN(*str, fill);
		else
			newstr = FT_STRJOIN(fill, *str);
		ft_strdel(str);
		ft_strdel(&fill);
		*str = newstr;
	}
}

char			*ptf_type_c(t_ptf_flags f, va_list ap)
{
	char		*res;

	(void)f;
	res = ft_strnew(1);
	res[0] = (char)va_arg(ap, int);
	fill_str(&res, &f);
	return (res);
}

char			*ptf_type_s(t_ptf_flags f, va_list ap)
{
	char		*res;

	(void)f;
	res = va_arg(ap, char *);
	if (res == NULL)
		res = "(null)";
	res = ft_strdup(res);
	fill_str(&res, &f);
	return (res);
}

char			*ptf_type_perc(t_ptf_flags f, va_list ap)
{
	(void)f;
	(void)ap;
	return (ft_strdup("%"));
}
