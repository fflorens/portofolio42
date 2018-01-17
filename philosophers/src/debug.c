/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 17:50:14 by bgauci            #+#    #+#             */
/*   Updated: 2014/05/11 22:04:07 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include <unistd.h>
#include <pthread.h>

int			put_str_fd(char *txt, int fd)
{
	int	i;

	if (!txt)
		return (0);
	i = 0;
	while (txt[i])
		i++;
	write(fd, txt, i);
	return (i);
}

int			put_nbr_fd(int n, int fd)
{
	char	nb[13];
	int		i;
	int		j;
	int		k;
	int		u;

	i = (n < 0) ? -1 : 1;
	j = n;
	k = (j <= 0) ? 1 : 0;
	while (j && ++k)
		j /= 10;
	nb[k] = 0;
	u = k;
	while (k-- >= 1)
	{
		nb[k] = (n % 10) * i + '0';
		n = n / 10;
	}
	nb[0] = (i == -1) ? '-' : nb[0];
	if (u)
		write(fd, nb, u);
	return (u);
}
