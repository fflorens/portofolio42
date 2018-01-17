/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlstiter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 15:29:06 by bgauci            #+#    #+#             */
/*   Updated: 2013/12/27 15:29:25 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_intlstiter(t_intlist *lst, void (*f)(t_intlist *elem))
{
	if (!lst || !f)
		return ;
	f(lst);
	ft_intlstiter(lst->next, f);
}
