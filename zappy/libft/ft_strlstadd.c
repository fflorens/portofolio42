/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlstadd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 12:23:48 by bgauci            #+#    #+#             */
/*   Updated: 2013/12/22 19:48:42 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strlstadd(t_strlist **alst, t_strlist *new)
{
	if (!alst || !new)
		return ;
	new->next = *alst;
	*alst = new;
}
