/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_handle_64.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 13:37:51 by fflorens          #+#    #+#             */
/*   Updated: 2017/08/08 16:04:09 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <mach-o/nlist.h>
#include <mach-o/stab.h>
#include "ft_nm_otool.h"
#include "libft.h"

static int		check_seg(t_segc64 *seg, t_sect64 *currsect, t_file *file)
{
	if (seg->nsects > UINT_MAX / sizeof(t_sect64) ||
		sizeof(t_sect64) * seg->nsects > ((t_lc *)seg)->cmdsize - sizeof(*seg))
		return (ft_otool_err(file->name, STR_LC_TOO_MANY, 0));
	if ((void *)seg + sizeof(*seg) + sizeof(*currsect) * seg->nsects
			> file->ptr + file->size)
		return (ft_otool_err(file->name, STR_FILE_TOO_SMALL, 0));
	return (EXIT_SUCCESS);
}

static int		crawl_command(t_segc64 *seg, t_file *file, char swap)
{
	t_sect64	*currsect;
	uint32_t	i;

	i = 0;
	currsect = (void *)(seg + 1);
	if ((void *)seg + sizeof(*seg) > file->ptr + file->size)
		return (ft_otool_err(file->name, STR_LC_TOO_MANY, 0));
	swap_segment_command_64(seg, swap);
	if (check_seg(seg, currsect, file) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	swap_section64(currsect, seg->nsects, swap);
	while (i++ < seg->nsects)
	{
		if ((void *)currsect + sizeof(t_sect64) > file->ptr + file->size)
			return (ft_otool_err(file->name, STR_FILE_TOO_SMALL, 0));
		if (!ft_strcmp(currsect->sectname, SECT_TEXT) &&
			!ft_strcmp(currsect->segname, SEG_TEXT))
		{
			file->sec = copy_sec64(currsect, file);
			return (file->sec ? EXIT_SUCCESS : EXIT_FAILURE);
		}
		currsect = currsect + 1;
	}
	return (EXIT_SUCCESS);
}

static int		test_sym(t_file *f, t_symc *sym, char swap)
{
	t_nlist64	*symt;
	char		*strtable;
	uint32_t	off;
	uint32_t	i;
	uint32_t	j;

	symt = f->ptr + sym->symoff;
	strtable = f->ptr + sym->stroff;
	if ((void *)symt > f->ptr + sym->symoff ||
		(void *)strtable > f->ptr + sym->stroff)
		return (ft_otool_err(f->name, STR_FILE_TOO_SMALL, 0));
	off = 0;
	i = 0;
	j = 0;
	swap_nlist64(symt, sym->nsyms, swap);
	while (i < sym->nsyms)
	{
		if ((void *)&symt[i] + sizeof(*symt) > f->ptr + f->size)
			return (ft_otool_err(f->name, STR_LC_CMD_TOO_SMALL, 0));
		if ((void *)strtable + symt[i].n_un.n_strx > f->ptr + f->size)
			return (ft_otool_err(f->name, STR_FILE_TOO_SMALL, 0));
		i++;
	}
	return (EXIT_SUCCESS);
}

static int		handle_seg(t_lc *lc, t_file *file, char swap)
{
	t_segc64	*seg;
	t_symc		*sym;

	if (lc->cmd == LC_SEGMENT_64 && !file->sec)
	{
		seg = (void *)lc;
		if ((void *)seg + sizeof(t_segc64) > file->ptr + file->size)
			return (ft_otool_err(file->name, STR_FILE_TOO_SMALL, 0));
		if (crawl_command((void *)lc, file, swap) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
	}
	else if (lc->cmd == LC_SYMTAB)
	{
		sym = (void *)lc;
		if ((void *)lc + sizeof(t_symc) > file->ptr + file->size)
			return (ft_otool_err(file->name, STR_FILE_TOO_SMALL, 0));
		swap_symtab_command(sym, swap);
		if (test_sym(file, (void *)lc, swap) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int				otool_handle_64(t_file *f, char swap)
{
	t_mhdr64	*hdr;
	t_lc		*lc;
	uint32_t	i;

	if ((off_t)f->size < (off_t)sizeof(t_mhdr64))
		return (ft_otool_err(f->name, STR_FILE_TOO_SMALL, 0));
	hdr = f->ptr;
	swap_mach_header_64(hdr, swap);
	lc = (void *)hdr + sizeof(t_mhdr64);
	setflags64(f, f->ptr);
	i = 0;
	while (i++ < hdr->ncmds)
	{
		swap_load_command(lc, swap);
		if (otool_test_lc(lc, f) != EXIT_SUCCESS
			|| handle_seg(lc, f, swap) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
		lc = (void *)lc + lc->cmdsize;
	}
	if (check_sec(f) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (check_has_arch(f) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	ft_otool_header(f);
	return (print_f(f));
}
