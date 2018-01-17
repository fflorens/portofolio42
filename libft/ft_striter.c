/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:47:03 by fflorens          #+#    #+#             */
/*   Updated: 2013/11/27 15:40:49 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

void ft_striter(char *s, void (*f)(char *))
{
	size_t i;

	if (s && f)
	{
		i = ft_strlen(s);
		while (i)
		{
			i--;
			f(&s[i]);
		}
	}
}
