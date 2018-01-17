/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:40:28 by fflorens          #+#    #+#             */
/*   Updated: 2013/11/27 15:41:17 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*out;
	int		i;

	if (s && f)
	{
		i = ft_strlen(s);
		out = ft_strnew(i);
		if (out)
		{
			while (i)
			{
				i--;
				out[i] = f(i, s[i]);
			}
		}
		return (out);
	}
	return (NULL);
}
