/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seconds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 15:39:52 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/22 18:35:18 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "shell.h"
#include "core.h"

char			*seconds_dynvar(void)
{
	static char	buffer[12] = { 0 };
	time_t		current_time;
	char		*tmp;

	if (time(&current_time) < 0)
		current_time = 0;
	ft_bzero(buffer, 12);
	tmp = ft_itoa(current_time - g_core.birth_time);
	ft_strcat(buffer, tmp);
	ft_strdel(&tmp);
	return (buffer);
}
