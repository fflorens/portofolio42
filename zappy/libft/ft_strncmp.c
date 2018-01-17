/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 18:22:55 by bgauci            #+#    #+#             */
/*   Updated: 2014/01/28 15:23:18 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	if (s1 == NULL || s2 == NULL)
		return (0);
	i = 0;
	while (n > i)
	{
		if (s1[i] != s2[i] || s1[i] == '\0')
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	ft_strrncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	s1_l;
	unsigned int	s2_l;

	if (s1 == NULL || s2 == NULL)
		return (0);
	i = 0;
	s1_l = ft_strlen(s1);
	s2_l = ft_strlen(s2);
	while (i < n)
	{
		if (s1[s1_l - i] != s2[s2_l - i])
			return (s1[i] - s2[i]);
		i++;
		if (s1_l < i || s2_l < i)
			return (-1);
	}
	return (0);
}
