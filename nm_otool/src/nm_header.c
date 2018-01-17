/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_header.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 10:22:28 by fflorens          #+#    #+#             */
/*   Updated: 2017/08/08 13:30:45 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_nm_otool.h"

extern char	*g_arch;

static void		print_name_and_arch(t_file *file)
{
	if (file->best_arch)
	{
		ft_putstr(file->name);
		ft_putstr(":\n");
		return ;
	}
	ft_putstr("\n");
	ft_putstr(file->name);
	ft_putstr(" (for architecture ");
	ft_putstr(file->archname);
	ft_putstr("):\n");
}

static void		print_name(t_file *file)
{
	ft_putstr("\n");
	ft_putstr(file->name);
	ft_putstr(":\n");
}

static int		check_compat(t_file *file)
{
	NXArchInfo	*info;

	info = get_host_arch();
	if (!file->best_arch)
		return (1);
	if (info->cputype != file->best_arch->cputype ||
			info->cpusubtype != file->best_arch->cpusubtype)
		if (file->best_arch->cputype == 7)
			return (0);
	return (1);
}

void			ft_nm_header(t_file *file)
{
	if (file->first && file->flag != 148 && !(file->flag & FLAG_FAT) &&
			file->flag != 144 && g_arch)
		return ;
	if (file->first && file->cputype == arch_cpu_type() && g_arch)
		return ;
	if (g_arch && ft_strcmp(g_arch, "all") && (!file->flag || file->flag == 8))
		return ;
	if ((!file->flag || file->flag == 8 || file->flag == 32) && g_arch &&
			!ft_strcmp(g_arch, "all"))
		return ;
	if (file->flag == 148 || file->flag == 144 || file->flag == 209 ||
			(g_arch && ft_strcmp(g_arch, "all")))
		print_name(file);
	else if (!g_arch && check_compat(file) &&
			(file->flag & FLAG_ARCH || file->flag == 0 ||
				file->flag == 32 || file->flag == 8))
		return ;
	else
		print_name_and_arch(file);
}
