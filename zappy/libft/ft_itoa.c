/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 13:01:47 by bgauci            #+#    #+#             */
/*   Updated: 2013/12/22 19:26:14 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*res;
	char			tmp;
	unsigned int	nb;

	res = ft_strnew(15);
	if (n < 0)
	{
		ft_strcat(res, "-");
		nb = n * -1;
	}
	else
		nb = n;
	while (nb >= 10)
	{
		tmp = (nb % 10) + '0';
		ft_strncat(res, &tmp, 1);
		nb = nb / 10;
	}
	tmp = (nb % 10) + '0';
	ft_strncat(res, &tmp, 1);
	if (n < 0)
		ft_strreverse(res + 1);
	else
		ft_strreverse(res);
	return (res);
}
