/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlstdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 12:24:39 by bgauci            #+#    #+#             */
/*   Updated: 2013/12/22 19:49:04 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strlstdel(t_strlist **alst)
{
	if (*alst == NULL)
		return ;
	ft_strlstdel(&((*alst)->next));
	ft_strlstdelone(alst);
}
