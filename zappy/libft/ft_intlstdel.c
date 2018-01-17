/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlstdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 15:27:30 by bgauci            #+#    #+#             */
/*   Updated: 2013/12/27 15:27:49 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_intlstdel(t_intlist **alst)
{
	if (*alst == NULL)
		return ;
	ft_intlstdel(&((*alst)->next));
	ft_intlstdelone(alst);
}
