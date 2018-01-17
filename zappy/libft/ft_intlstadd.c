/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlstadd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 15:26:42 by bgauci            #+#    #+#             */
/*   Updated: 2013/12/27 15:26:58 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_intlstadd(t_intlist **alst, t_intlist *new)
{
	if (!alst || !new)
		return ;
	new->next = *alst;
	*alst = new;
}
