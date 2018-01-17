/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_nlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 14:26:24 by fflorens          #+#    #+#             */
/*   Updated: 2017/05/24 17:21:09 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach-o/nlist.h>
#include "ft_nm_otool.h"
#include "libft.h"

void	swap_nlist(t_nlist *sym, unsigned long nsym, char swap)
{
	if (!swap)
		return ;
	while (nsym--)
	{
		sym->n_un.n_strx = ft_swap_32(sym->n_un.n_strx);
		sym->n_desc = ft_swap_16(sym->n_desc);
		sym->n_value = ft_swap_32(sym->n_value);
		sym++;
	}
}

void	swap_nlist64(t_nlist64 *sym, unsigned long nsym, char swap)
{
	if (!swap)
		return ;
	while (nsym--)
	{
		sym->n_un.n_strx = ft_swap_32(sym->n_un.n_strx);
		sym->n_desc = ft_swap_16(sym->n_desc);
		sym->n_value = ft_swap_64(sym->n_value);
		sym++;
	}
}
