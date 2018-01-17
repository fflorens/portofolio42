/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 18:31:41 by fflorens          #+#    #+#             */
/*   Updated: 2017/03/14 10:54:33 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *out;

	if (s1 == NULL && s2)
		out = ft_strdup(s2);
	else if (s2 == NULL && s1)
		out = ft_strdup(s1);
	else if (s2 == NULL && s1 == NULL)
		return (NULL);
	else
	{
		out = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (out)
		{
			out = ft_strcat(out, s1);
			out = ft_strcat(out, s2);
		}
	}
	return (out);
}
