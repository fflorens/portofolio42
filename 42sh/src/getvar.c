/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getvar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 19:11:48 by fflorens          #+#    #+#             */
/*   Updated: 2014/03/18 15:27:29 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "shell.h"
#include "dynvars.h"

/*
** Returns a non malloc'ed string representing the requested shell variable
*/
const char				*sh_getvar(const char *name)
{
	char				*var;

	if ((var = dynvar_load(name)) != NULL)
		return (var);
	else if ((var = sh_getenv(name)) != NULL)
		return (var);
	else
		return ("");
}
