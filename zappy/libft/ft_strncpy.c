/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:28:32 by bgauci            #+#    #+#             */
/*   Updated: 2013/12/22 19:50:29 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	int				bol;

	i = 0;
	bol = 0;
	while (i < n)
	{
		if (bol)
			s1[i] = '\0';
		else
		{
			s1[i] = s2[i];
			if (s2[i] == '\0')
				bol = 1;
		}
		i++;
	}
	return (s1);
}
