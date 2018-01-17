/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/09 19:39:45 by nmokrane          #+#    #+#             */
/*   Updated: 2013/12/09 20:20:44 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intcmp(int i1, int i2)
{
	if (i1 < i2)
		return (-1);
	else if (i1 > i2)
		return (1);
	return (0);
}
