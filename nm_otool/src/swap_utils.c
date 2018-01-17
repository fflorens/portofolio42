/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 17:12:47 by fflorens          #+#    #+#             */
/*   Updated: 2017/05/24 17:13:09 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"
#include "libft.h"

void	swap_segment_command(t_segc *seg, char swap)
{
	if (!swap)
		return ;
	seg->nsects = ft_swap_32(seg->nsects);
}

void	swap_segment_command_64(t_segc64 *seg, char swap)
{
	if (!swap)
		return ;
	seg->nsects = ft_swap_32(seg->nsects);
}

void	swap_section(t_sect *sect, unsigned int nsects, char swap)
{
	if (!swap)
		return ;
	while (nsects--)
	{
		sect[nsects].size = ft_swap_32(sect[nsects].size);
		sect[nsects].offset = ft_swap_32(sect[nsects].offset);
		sect[nsects].addr = ft_swap_32(sect[nsects].addr);
	}
}

void	swap_section64(t_sect64 *sect, unsigned int nsects, char swap)
{
	if (!swap)
		return ;
	while (nsects--)
	{
		sect[nsects].size = ft_swap_64(sect[nsects].size);
		sect[nsects].offset = ft_swap_32(sect[nsects].offset);
		sect[nsects].addr = ft_swap_64(sect[nsects].addr);
	}
}

void	swap_symtab_command(t_symc *symt, char swap)
{
	if (!swap)
		return ;
	symt->symoff = ft_swap_32(symt->symoff);
	symt->nsyms = ft_swap_32(symt->nsyms);
	symt->stroff = ft_swap_32(symt->stroff);
}
