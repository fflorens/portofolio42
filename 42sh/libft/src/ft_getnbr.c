/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 17:41:02 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/25 19:49:19 by jzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function looks for a number at start of the given str, ignoring blanks
** and writes it to nbr int pointer.
** The function returns an int which can be used to increment str outside in
** order to go just after the captured number.
** If the string doesn't starts with a number, then it returns zero.
*/
static int		get_long(char *str, long *nbr)
{
	long		multiply;
	char		*ptr;

	ptr = str;
	while ((*ptr > 8 && *ptr < 14) || (*ptr == ' '))
		ptr++;
	multiply = 1;
	if (*ptr == '-' || *ptr == '+')
		multiply = 44 - *ptr++;
	if (!ft_isdigit(*ptr))
		return (0);
	*nbr = 0;
	while (*ptr >= '0' && *ptr <= '9')
		*nbr = (*nbr * 10) + (*ptr++ - '0');
	*nbr *= multiply;
	return ((int)(ptr - str));
}

int				ft_getnbr(char *str, int *nbr)
{
	int		ret_val;
	long	long_nbr;
	long	int_min;
	long	int_max;

	if ((ret_val = get_long(str, &long_nbr)) == 0)
		return (0);
	int_min = (ft_powl(2, (sizeof(int) * 8)) / 2) * -1;
	int_max = (ft_powl(2, (sizeof(int) * 8)) / 2) - 1;
	if (long_nbr < int_min || long_nbr > int_max)
		return (0);
	*nbr = (int)long_nbr;
	return (ret_val);
}
