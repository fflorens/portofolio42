/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:25:30 by bgauci            #+#    #+#             */
/*   Updated: 2013/11/25 15:45:51 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	char			*res;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	res = ft_strnew((unsigned int)ft_strlen(s));
	while (i < ft_strlen(s))
	{
		res[i] = f(s[i]);
		i++;
	}
	return (res);
}
