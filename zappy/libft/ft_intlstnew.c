/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlstnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 15:30:07 by bgauci            #+#    #+#             */
/*   Updated: 2013/12/27 15:31:22 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_intlist	*ft_intlstnew(int value)
{
	t_intlist	*res;

	if ((res = malloc(sizeof(t_intlist))) == NULL)
		return (NULL);
	res->value = value;
	res->next = NULL;
	return (res);
}
