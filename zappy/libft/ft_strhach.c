/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strhach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 20:00:49 by bgauci            #+#    #+#             */
/*   Updated: 2013/12/16 18:05:30 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_strhach.h"

int	ft_strhach(char *str)
{
	int		i;
	int		j;

	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (*str != 0)
	{
		j = j * 3 + *str;
		if (j >= MAX_INT)
			j = j % (FACTOR);
		str++;
	}
	i = j % TAB_LEN;
	return (i);
}

int	ft_strhach_bis(char *str)
{
	int		i;
	int		j;

	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (*str != 0)
	{
		j = j * 5 + *str;
		if (j >= MAX_INT)
			j = j % (FACTOR);
		str++;
	}
	i = j % TAB_LEN;
	return (i);
}
