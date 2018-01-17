/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 13:47:54 by fflorens          #+#    #+#             */
/*   Updated: 2017/08/08 13:47:57 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	ft_error(char *str, char *extra)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	write(2, str, i);
	if (extra)
	{
		i = -1;
		while (extra[++i])
			;
		write(2, extra, i);
		write(2, "\n", 1);
	}
	return (EXIT_FAILURE);
}
