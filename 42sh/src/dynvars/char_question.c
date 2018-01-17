/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_question.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 20:39:43 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/24 20:52:57 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "core.h"

char			*char_question_dynvar(void)
{
	static char	buf[12];
	char		*tmp;

	ft_bzero(buf, 12);
	tmp = ft_itoa(g_core.last_status);
	ft_strcat(buf, tmp);
	ft_strdel(&tmp);
	return (buf);
}
