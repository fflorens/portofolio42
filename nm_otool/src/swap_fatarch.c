/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_til.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 17:13:45 by fflorens          #+#    #+#             */
/*   Updated: 2017/08/08 13:37:11 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libkern/OSByteOrder.h>
#include "ft_nm_otool.h"
#include "libft.h"

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

void	swap_fat_arch64(t_farch64 *archs, unsigned int n_arch, char swap)
{
	if (!swap)
		return ;
	while (n_arch--)
	{
		archs[n_arch].cputype = ft_swap_32(archs[n_arch].cputype);
		archs[n_arch].cpusubtype = ft_swap_32(archs[n_arch].cpusubtype);
		archs[n_arch].offset = ft_swap_64(archs[n_arch].offset);
		archs[n_arch].size = ft_swap_64(archs[n_arch].size);
	}
}
