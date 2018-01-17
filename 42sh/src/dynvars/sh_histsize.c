/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh_histsize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 17:22:52 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/24 14:01:52 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char			*sh_histsize_dynvar(void)
{
	char		*result;

	result = sh_getenv("SH_HISTSIZE");
	if (result == NULL || ft_atoi(result) == 0)
		result = "65536";
	return (result);
}
