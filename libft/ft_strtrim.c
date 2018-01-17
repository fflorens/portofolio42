/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 18:51:54 by fflorens          #+#    #+#             */
/*   Updated: 2013/11/27 15:41:55 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char *ft_strtrim(char const *s)
{
	char	*out;
	size_t	i;
	size_t	j;

	if (s)
	{
		j = 0;
		while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
			j++;
		i = ft_strlen(s) - 1;
		while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && i >= j)
			i--;
		out = ft_strsub(s, j, 1 + i - j);
		return (out);
	}
	return (NULL);
}
