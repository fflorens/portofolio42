/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfastcat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 18:00:16 by bgauci            #+#    #+#             */
/*   Updated: 2013/12/16 18:01:18 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfastcat(char *s1, const int s1_len, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (s2[i] != '\0')
	{
		s1[i + s1_len] = s2[i];
		i++;
	}
	s1[i + s1_len] = '\0';
	return (s1);
}
