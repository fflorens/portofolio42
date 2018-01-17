/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 12:11:28 by bgauci            #+#    #+#             */
/*   Updated: 2014/01/07 18:05:24 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, int nb)
{
	char	*res;
	int		len_s1;
	int		len_s2;

	len_s1 = ((s1) ? ft_strlen(s1) : 0);
	len_s2 = ((s2) ? ft_strlen(s2) : 0);
	len_s2 = ((len_s2 < nb) ? len_s2 : nb);
	res = ft_strnew(len_s1 + len_s2);
	if (res != NULL)
	{
		ft_strcat(res, s1);
		ft_strncat(res, s2, len_s2);
	}
	return (res);
}
