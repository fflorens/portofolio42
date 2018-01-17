/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjcat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 12:28:34 by bgauci            #+#    #+#             */
/*   Updated: 2014/01/06 15:15:40 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strnjcat(char **s1, const char *s2, int nb)
{
	char	*tmp;

	if (!s2)
		return ;
	if (!s1)
		return ;
	tmp = *s1;
	*s1 = ft_strnjoin(tmp, s2, nb);
	if (tmp)
		free(tmp);
}
