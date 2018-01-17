/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/22 19:20:20 by bgauci            #+#    #+#             */
/*   Updated: 2014/05/22 23:17:36 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sys/errno.h"
#include "stdio.h"

void	ft_perror(char *txt)
{
	if (txt)
	{
		ft_putstr_fd(txt, 2);
		ft_putstr_fd(": ", 2);
	}
	if (errno < 0 || errno > sys_nerr)
	{
		ft_putstr_fd("Unknown error [", 2);
		ft_putnbr_fd(errno, 2);
		ft_putstr_fd("]", 2);
	}
	else
		ft_putstr_fd(sys_errlist[errno], 2);
	ft_putstr_fd("\n", 2);
}

void	exit_perror(char *txt, int i)
{
	ft_perror(txt);
	exit(i);
}
