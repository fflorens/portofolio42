/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstd_addf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 11:20:32 by fflorens          #+#    #+#             */
/*   Updated: 2013/11/29 11:20:38 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void ft_lstd_addf(t_lstd **alstd, t_lstd *new)
{
	new->next = *alstd;
	(*alstd)->prev = new;
	*alstd = new;
}
