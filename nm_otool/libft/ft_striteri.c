/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:27:24 by fflorens          #+#    #+#             */
/*   Updated: 2017/03/14 10:54:27 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t j;

	if (s && f)
	{
		j = ft_strlen(s);
		while (j)
		{
			j--;
			f((unsigned int)j, &s[j]);
		}
	}
}
