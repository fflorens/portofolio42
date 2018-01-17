/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlstdelone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 12:25:23 by bgauci            #+#    #+#             */
/*   Updated: 2013/12/22 19:49:07 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strlstdelone(t_strlist **alst)
{
	if (!alst)
		return ;
	free((*alst)->content);
	free (*alst);
	*alst = NULL;
}
