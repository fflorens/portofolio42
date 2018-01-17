/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_handle_fat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 17:16:17 by fflorens          #+#    #+#             */
/*   Updated: 2017/08/09 11:46:35 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"
#include "libft.h"

extern char	*g_arch;

static int	process_arch(t_file *file, t_farch *arch, int has_arch)
{
	t_file	f;
	int		ret;

	ft_memcpy(&f, file, sizeof(t_file));
	f.ptr = file->ptr + arch->offset;
	f.size = arch->size;
	f.archname[0] = 0;
	set_arch(&f, arch);
	f.flag = (has_arch ? file->flag : (file->flag | FLAG_ARCH));
	f.best_arch = (has_arch ? file->best_arch : NULL);
	ret = ft_otool(&f);
	free(f.sym);
	free(f.sec);
	return (ret);
}

int			otool_handle_fat(t_file *f, char swap)
{
	t_fhdr	*hdr;
	t_farch	*arch;

	hdr = f->ptr;
	swap_fat_header(hdr, swap);
	arch = (void*)hdr + sizeof(t_fhdr);
	if ((void *)arch + sizeof(t_farch) > f->ptr + f->size ||
		hdr->nfat_arch * sizeof(t_farch) + (void *)arch > f->ptr + f->size)
		return (ft_otool_err(f->name, "' file size too small\n", 0));
	swap_fat_arch(arch, hdr->nfat_arch, swap);
	f->flag |= FLAG_FAT;
	f->best_arch = get_best_arch(arch, hdr->nfat_arch);
	if (f->best_arch)
		return (process_arch(f, f->best_arch, 0));
	else if (!f->best_arch && g_arch && ft_strcmp(g_arch, "all"))
		return (ft_otool_err(f->name, g_arch, 1));
	while (hdr->nfat_arch--)
		if (process_arch(f, arch++, 1) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
