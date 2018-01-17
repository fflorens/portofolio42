/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 15:41:23 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/18 16:09:49 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char			*ps1_dynvar(void)
{
	char		*result;

	result = sh_getenv("PS1");
	if (result == NULL)
		result = PS1;
	return (result);
}
