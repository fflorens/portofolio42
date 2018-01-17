/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strenqu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:48:40 by fflorens          #+#    #+#             */
/*   Updated: 2013/11/27 22:58:04 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int ft_strnequ(char const *s1, char const *s2, size_t n)
{
	return (!ft_memcmp(s1, s2, n));
}
