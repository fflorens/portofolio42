/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 20:30:02 by fflorens          #+#    #+#             */
/*   Updated: 2014/03/27 20:35:32 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nboon.h"
#include "shell.h"
#include "printf.h"

int			wsavehist_builtin(char **av)
{
	(void)av;
	nb_history_save(sh_getvar("SH_HISTFILE"));
	ft_printf("Saved history in %s\n", sh_getvar("SH_HISTFILE"));
	return (0);
}
