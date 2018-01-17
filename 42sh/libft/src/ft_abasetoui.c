/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abasetoui.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 17:13:55 by fflorens          #+#    #+#             */
/*   Updated: 2014/03/22 17:28:07 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include			"libft.h"

unsigned int		ft_abasetoui(const char *str, const char *base)
{
	unsigned int	out;
	unsigned int	len;
	unsigned int	baselen;
	unsigned int	i;
	int				tmp;

	i = 1;
	out = 0;
	len = ft_strlen(str);
	baselen = ft_strlen(base);
	while (len--)
	{
		tmp = ft_indexof(base, str[len]);
		if (tmp == -1)
			return (out);
		out += i * tmp;
		i *= baselen;
	}
	return (out);
}
