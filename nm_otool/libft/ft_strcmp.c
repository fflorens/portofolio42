/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:51:48 by fflorens          #+#    #+#             */
/*   Updated: 2017/03/14 10:53:53 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;
	int	result;

	i = 0;
	while (s1[i] && s2[i] &&
			(unsigned char)s1[i] == (unsigned char)s2[i])
		i++;
	result = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (result);
}
