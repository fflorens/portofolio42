/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfastjoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 17:24:23 by bgauci            #+#    #+#             */
/*   Updated: 2013/12/16 17:58:37 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline void	ft_strfastjoin (char **s1, char const *s2, int s1_len, int s2_len)
{
	char	*res;

	if (!s1 || !(*s1) || !s2)
		return ;
	res = ft_strfastnew(s1_len + s2_len);
	if (res != NULL)
	{
		ft_strfastcat(res, 0, *s1);
		ft_strfastcat(res, s1_len, s2);
	}
	*s1 = res;
}
