/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_powl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 14:09:59 by nmokrane          #+#    #+#             */
/*   Updated: 2014/01/23 07:46:50 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long		ft_powl(long x, long y)
{
	long		result;

	if (y == 0)
		return (1);
	result = x;
	while (--y)
		result *= x;
	return (result);
}
