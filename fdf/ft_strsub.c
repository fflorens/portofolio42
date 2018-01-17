/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 18:26:00 by fflorens          #+#    #+#             */
/*   Updated: 2013/12/22 18:55:10 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*out;

	if (s)
	{
		out = ft_strnew(len);
		if (out)
			out = ft_strncpy(out, s + start, len);
		return (out);
	}
	return (NULL);
}
