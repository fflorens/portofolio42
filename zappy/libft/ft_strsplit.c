/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 17:52:12 by bgauci            #+#    #+#             */
/*   Updated: 2014/05/16 17:24:41 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char	**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		n;
	int		start;
	int		len;

	if (!s || !c)
		return (NULL);
	n = 0;
	i = 0;
	res = malloc(sizeof(char*) * ft_strlen(s));
	while (s[i] != '\0' || n == 0)
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		len = i - start;
		res[n] = ft_strsub(s, start, len);
		n++;
	}
	res[n] = NULL;
	return (res);
}
