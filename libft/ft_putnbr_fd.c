/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:16:12 by fflorens          #+#    #+#             */
/*   Updated: 2013/11/27 15:39:51 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <libft.h>

void ft_putnbr_fd(int n, int fd)
{
	char *tmp;

	tmp = ft_itoa(n);
	write(fd, tmp, ft_strlen(tmp));
	free(tmp);
}
