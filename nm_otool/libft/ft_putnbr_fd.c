/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:16:12 by fflorens          #+#    #+#             */
/*   Updated: 2017/03/14 10:59:27 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <libft.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	out[20];
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
	tmp = n;
	while (i--)
	{
		out[i] = ((tmp % 10) * sign) + '0';
		tmp /= 10;
	}
	out[0] = ((sign == -1 && n != 0) ? '-' : out[0]);
	ft_putstr_fd(out, fd);
}
