/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 14:42:02 by fflorens          #+#    #+#             */
/*   Updated: 2013/12/22 18:54:50 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int			ft_open(char *name)
{
	int		fd;

	if ((fd = open(name, O_RDONLY)) > 1)
		return (fd);
	write(1, &"OPEN ERROR \n", 12);
	return (-1);
}
