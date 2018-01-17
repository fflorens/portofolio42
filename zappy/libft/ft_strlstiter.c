/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlstiter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 12:26:53 by bgauci            #+#    #+#             */
/*   Updated: 2013/12/22 19:49:15 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strlstiter(t_strlist *lst, void (*f)(t_strlist *elem))
{
	if (!lst || !f)
		return ;
	f(lst);
	ft_strlstiter(lst->next, f);
}
