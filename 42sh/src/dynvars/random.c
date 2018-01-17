/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 15:27:41 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/27 21:50:24 by jzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "shell.h"
#include "dynvars.h"

char					*random_dynvar(void)
{
	static char			*envs[2] = {NULL, NULL};
	static char			*out = NULL;
	static char			first = 1;
	static unsigned int	s[2];
	unsigned int		tmp;

	if (first)
	{
		first = 0;
		s[0] = getpid();
		s[1] = ~s[0];
	}
	if (((envs[0] = sh_getenv("RANDOM")) != NULL) && (envs[0] != envs[1]))
	{
		s[0] = ft_atoui(envs[0]);
		s[1] = ~s[0];
		envs[1] = envs[0];
	}
	tmp = s[0] ^ (s[0] >> 2) ^ (s[0] >> 6) ^ (s[0] >> 7);
	s[0] = ((s[0] >> 1) | (~tmp << 31));
	tmp = (s[1] << 1) ^ (s[1] << 2) ^ (s[0] << 3) ^ (s[1] << 4);
	s[1] = ((s[1] << 1) | (~tmp << 31));
	ft_strdel(&out);
	out = ft_uitoa(s[0] ^ s[1]);
	return (out);
}
