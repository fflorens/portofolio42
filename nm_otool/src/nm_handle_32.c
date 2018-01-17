/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_handle_32.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 12:44:12 by fflorens          #+#    #+#             */
/*   Updated: 2017/08/08 13:35:19 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach-o/nlist.h>
#include <mach-o/stab.h>
#include "ft_nm_otool.h"
#include "libft.h"

static int	copy_sym(t_nlist sym, void *str, t_file *f, uint32_t *idx)
{
	if ((void *)str + sym.n_un.n_strx > f->ptr + f->size)
		return (ft_nm_err(f->name, STR_FILE_TOO_SMALL, 0));
	if (sym.n_type & N_STAB)
		return (EXIT_SUCCESS);
	f->sym[*idx].stab = (sym.n_type & N_STAB);
	f->sym[*idx].cpu = 32;
	f->sym[*idx].name = (void *)str + sym.n_un.n_strx;
	f->sym[*idx].ext = (sym.n_type & N_EXT);
	f->sym[*idx].type = (sym.n_type & N_TYPE);
	f->sym[*idx].sectnb = sym.n_sect - 1;
	f->sym[*idx].addr = sym.n_value;
	(*idx)++;
	return (EXIT_SUCCESS);
}

static int	crawl_section(t_file *f, uint32_t ncmds, uint32_t sect_nb)
{
	uint32_t	i[3];
	t_lc		*lc;
	t_sect		*sect;

	if ((f->sec = malloc(sizeof(t_sec) * (sect_nb + 1))) == NULL)
		return (ft_nm_err(f->name, "': Malloc error.\n", 0));
	lc = (void *)f->ptr + sizeof(t_mhdr);
	ft_bzero(i, sizeof(uint32_t) * 3);
	while (i[0] < ncmds)
	{
		if (lc->cmd == LC_SEGMENT)
		{
			i[1] = 0;
			sect = (void *)lc + sizeof(t_segc);
			while (i[1]++ < ((t_segc *)lc)->nsects)
			{
				if ((void *)sect + sizeof(t_sect) > f->ptr + f->size)
					return (ft_nm_err(f->name, STR_LC_TOO_MANY, 0));
				sect = copy_sect32(sect, f, i[2]++);
			}
		}
		i[0]++;
		lc = (void *)lc + lc->cmdsize;
	}
	return (EXIT_SUCCESS);
}

static int	crawl_sym(t_file *f, t_symc *sym, char swap)
{
	t_nlist		*st;
	char		*str;
	uint32_t	off;
	uint32_t	i;

	if ((f->sym = malloc(sizeof(t_sym) * (sym->nsyms))) == NULL)
		return (ft_nm_err(f->name, "': Malloc error.\n", 0));
	st = f->ptr + sym->symoff;
	str = f->ptr + sym->stroff;
	if ((void *)st > f->ptr + sym->symoff || (void *)str > f->ptr + sym->stroff)
		return (ft_nm_err(f->name, STR_FILE_TOO_SMALL, 0));
	off = 0;
	i = 0;
	swap_nlist(st, sym->nsyms, swap);
	while (i < sym->nsyms)
	{
		if ((void *)&st[i] + sizeof(*st) > f->ptr + f->size)
			return (ft_nm_err(f->name, STR_LC_CMD_TOO_SMALL, 0));
		if (st[i].n_un.n_strx > 0)
			if (copy_sym(st[i], str, f, &f->sym_idx) != EXIT_SUCCESS)
				return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	handle_seg32(t_lc *lc, uint32_t *nb, t_file *file, char swap)
{
	t_segc		*seg;
	t_symc		*sym;

	if (lc->cmd == LC_SEGMENT)
	{
		seg = (void *)lc;
		if ((void *)seg + sizeof(t_segc) > file->ptr + file->size)
			return (ft_nm_err(file->name, STR_FILE_TOO_SMALL, 0));
		swap_segment_command(seg, swap);
		*nb += seg->nsects;
	}
	else if (lc->cmd == LC_SYMTAB)
	{
		sym = (void *)lc;
		if ((void *)lc + sizeof(t_symc) > file->ptr + file->size)
			return (ft_nm_err(file->name, STR_FILE_TOO_SMALL, 0));
		swap_symtab_command(sym, swap);
		if (crawl_sym(file, sym, swap) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int			nm_handle_32(t_file *f, char swap)
{
	t_mhdr			*hdr;
	t_lc			*lc;
	uint32_t		sect_nb;
	uint32_t		i;

	if (f->ptr + f->size < f->ptr + sizeof(t_mhdr))
		return (ft_nm_err(f->name, STR_FILE_TOO_SMALL, 0));
	setflags32(f, f->ptr);
	hdr = f->ptr;
	swap_mach_header(hdr, swap);
	lc = (void *)hdr + sizeof(t_mhdr);
	i = 0;
	while (i++ < hdr->ncmds)
	{
		swap_load_command(lc, swap);
		if (test_lc_32(lc, f) != EXIT_SUCCESS
				|| handle_seg32(lc, &sect_nb, f, swap) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
		lc = (void *)lc + lc->cmdsize;
	}
	if (crawl_section(f, hdr->ncmds, sect_nb) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	ft_nm_header(f);
	sort_f(f);
	return (print_f(f));
}
