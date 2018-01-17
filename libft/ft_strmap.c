/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:40:28 by fflorens          #+#    #+#             */
/*   Updated: 2013/11/27 15:41:13 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char *ft_strmap(char const *s, char (*f)(char))
{
	char	*out;
	int		i;

	out = NULL;
	if (s && f)
	{
		i = ft_strlen(s);
		out = ft_strnew(i);
		if (out)
		{
			while (i)
			{
				i--;
				out[i] = f(s[i]);
			}
		}
	}
	return (out);
}
