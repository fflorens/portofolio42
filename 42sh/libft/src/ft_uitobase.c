/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitobase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 16:52:11 by fflorens          #+#    #+#             */
/*   Updated: 2014/03/22 17:25:19 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>

char		*ft_uitobase(unsigned int n, const char *base)
{
	char			*out;
	unsigned int	tmp;
	int				i;
	size_t			baselen;

	baselen = 0;
	while (base[baselen])
		baselen++;
	i = ((n == 0) ? 1 : 0);
	tmp = n;
	while (tmp)
	{
		i++;
		tmp /= baselen;
	}
	if ((out = (char *)malloc(i + 1)))
	{
		out[i] = 0;
		while (i--)
		{
			out[i] = base[n % baselen];
			n /= baselen;
		}
	}
	return (out);
}
