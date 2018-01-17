/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 20:32:33 by fflorens          #+#    #+#             */
/*   Updated: 2017/03/14 10:53:25 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_itoa(int n)
{
	char	*out;
	int		tmp;
	int		i;
	int		sign;

	sign = ((n > 0) ? 1 : -1);
	i = ((sign == -1) ? 1 : 0);
	tmp = n;
	while (tmp)
	{
		i++;
		tmp /= 10;
	}
	out = ft_strnew(i);
	tmp = n;
	if (out)
	{
		while (i--)
		{
			out[i] = ((tmp % 10) * sign) + '0';
			tmp /= 10;
		}
		out[0] = ((sign == -1 && n != 0) ? '-' : out[0]);
	}
	return (out);
}
