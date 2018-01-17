/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 17:38:25 by bgauci            #+#    #+#             */
/*   Updated: 2014/06/24 18:33:16 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;

	if (!s1)
		return (strdup(s2));
	if (!s2)
		return (strdup(s1));
	res = (char *)calloc(strlen(s1) + strlen(s2), sizeof(char));
	if (res != NULL)
	{
		strcat(res, s1);
		strcat(res, s2);
	}
	return (res);
}
