/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlstnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 12:29:18 by bgauci            #+#    #+#             */
/*   Updated: 2013/11/28 14:45:12 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_strlist	*ft_strlstnew(const char *content)
{
	t_strlist	*res;

	if ((res = malloc(sizeof(t_strlist))) == NULL)
		return (NULL);
	if (content != NULL)
	{
		if ((res->content = ft_strdup(content)) == NULL)
			return (NULL);
	}
	else
		res->content = NULL;
	res->next = NULL;
	return (res);
}
