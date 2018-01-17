/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:51:31 by fflorens          #+#    #+#             */
/*   Updated: 2013/12/22 18:34:56 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "gnl.h"

char	*ft_strchr(const char *s, int c)
{
	if (*s == (char) c)
		return ((char *) s);
	while (*s++)
		if (*s == (char) c)
			return ((char *) s);
	return (NULL);
}
