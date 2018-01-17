/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_dollar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 20:52:04 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/24 20:55:06 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "shell.h"

char			*char_dollar_dynvar(void)
{
	static char	buf[12] = { 0 };
	char		*tmp;

	if (*buf == '\0')
	{
		tmp = ft_itoa((int)getpid());
		ft_strcat(buf, tmp);
		ft_strdel(&tmp);
	}
	return (buf);
}
