/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yes.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 15:40:46 by fflorens          #+#    #+#             */
/*   Updated: 2014/03/27 15:42:29 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int				yes_builtin(char **argv)
{
	char		*yes;

	if (argv[1] != NULL)
		yes = argv[1];
	else
		yes = "y";
	while (1)
		ft_printf("%s\n", yes);
	return (0);
}
