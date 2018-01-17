/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 17:52:26 by bgauci            #+#    #+#             */
/*   Updated: 2013/12/22 19:37:54 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstswap(t_list *a, t_list *b)
{
	void	*tmp;
	size_t	tmp2;

	tmp = a->content;
	tmp2 = a->content_size;
	a->content = b->content;
	a->content_size = b->content_size;
	b->content = tmp;
	b->content_size = tmp2;
}
