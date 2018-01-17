/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 15:41:23 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/18 15:48:12 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char			*ps2_dynvar(void)
{
	char		*result;

	result = sh_getenv("PS2");
	if (result == NULL)
		result = "> ";
	return (result);
}
