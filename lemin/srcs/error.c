/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 03:48:46 by fflorens          #+#    #+#             */
/*   Updated: 2014/02/23 06:24:04 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdarg.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<lemin.h>

static void	ft_putstr_fd(int fd, char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	write(fd, str, i);
}

void		*ft_malloc_noerror(unsigned int size)
{
	void	*p;

	if (!(p = malloc(size)))
	{
		ft_error(E_MALLOC_FAIL);
		exit(1);
	}
	return (p);
}

int			ft_error(const char *fmt, ...)
{
	va_list	ap;

	va_start(ap, fmt);
	while (*fmt)
	{
		if ((*fmt == '%') && (*(fmt + 1) == 's'))
		{
			ft_putstr_fd(2, va_arg(ap, char *));
			fmt++;
		}
		else
			write(2, fmt, 1);
		fmt++;
	}
	va_end(ap);
	return (0);
}
