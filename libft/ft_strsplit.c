/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 14:25:05 by fflorens          #+#    #+#             */
/*   Updated: 2013/11/27 15:41:38 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

static size_t	ft_get_elems(char const *s, char c)
{
	size_t nb;
	size_t i;

	nb = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
		{
			i++;
		}
		if (s[i] != c && s[i])
			nb++;
		while (s[i] != c && s[i])
			i++;
	}
	return (nb);
}

static char		**ft_fill_elems(char **out, char const *s, char c, size_t nb)
{
	size_t i;
	size_t pos;
	size_t start;
	size_t len;

	i = 0;
	pos = 0;
	while (i < nb)
	{
		len = 0;
		while (s[pos] == c)
			pos++;
		start = pos;
		while (s[pos] != c && s[pos])
		{
			len++;
			pos++;
		}
		out[i] = ft_strsub(s, start, len);
		i++;
	}
	out[nb] = NULL;
	return (out);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		nb;
	char		**out;

	if (s == NULL)
		return (NULL);
	nb = ft_get_elems(s, c);
	out = (char **)malloc(sizeof(char *) * (1 + nb));
	out[nb] = NULL;
	if (out)
		out = ft_fill_elems(out, s, c, nb);
	return (out);
}
