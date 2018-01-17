/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qexclamation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 20:30:07 by fflorens          #+#    #+#             */
/*   Updated: 2014/03/27 20:32:57 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "nboon.h"
#include "lexer.h"
#include "core.h"
#include "completion.h"

int			builtin_qexclamation(char **argv)
{
	(void)argv;
	nb_history_free();
	free_completion();
	sh_envmanager(ENV_FREE);
	free_lexer();
	core_free();
	exit(0);
	return (0);
}
