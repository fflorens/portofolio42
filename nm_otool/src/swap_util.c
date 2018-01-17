/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 17:13:45 by fflorens          #+#    #+#             */
/*   Updated: 2017/05/24 17:13:48 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"
#include "libft.h"

void	swap_fat_header(t_fhdr *hdr, char swap)
{
	if (!swap)
		return ;
	hdr->nfat_arch = ft_swap_32(hdr->nfat_arch);
}

void	swap_mach_header(t_mhdr *hdr, char swap)
{
	if (!swap)
		return ;
	hdr->filetype = ft_swap_32(hdr->filetype);
	hdr->ncmds = ft_swap_32(hdr->ncmds);
	hdr->cputype = ft_swap_32(hdr->cputype);
}

void	swap_mach_header_64(t_mhdr64 *hdr, char swap)
{
	if (!swap)
		return ;
	hdr->filetype = ft_swap_32(hdr->filetype);
	hdr->ncmds = ft_swap_32(hdr->ncmds);
	hdr->cputype = ft_swap_32(hdr->cputype);
}

void	swap_fat_arch(t_farch *archs, unsigned int n_arch, char swap)
{
	if (!swap)
		return ;
	while (n_arch--)
	{
		archs[n_arch].cputype = ft_swap_32(archs[n_arch].cputype);
		archs[n_arch].cpusubtype = ft_swap_32(archs[n_arch].cpusubtype);
		archs[n_arch].offset = ft_swap_32(archs[n_arch].offset);
		archs[n_arch].size = ft_swap_32(archs[n_arch].size);
	}
}

void	swap_load_command(t_lc *lc, char swap)
{
	if (!swap)
		return ;
	lc->cmd = ft_swap_32(lc->cmd);
	lc->cmdsize = ft_swap_32(lc->cmdsize);
}
