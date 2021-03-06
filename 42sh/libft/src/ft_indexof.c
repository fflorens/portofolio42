/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indexof.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 18:00:37 by nmokrane          #+#    #+#             */
/*   Updated: 2013/12/20 19:21:18 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_indexof(const char *s, char c)
{
	int			i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	if (c == '\0' || s[i] != '\0')
		return (i);
	return (-1);
}
