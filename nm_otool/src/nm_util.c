/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 13:11:37 by fflorens          #+#    #+#             */
/*   Updated: 2017/08/08 17:05:12 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach-o/nlist.h>
#include <mach-o/stab.h>
#include "ft_nm_otool.h"
#include "libft.h"

int			test_lc_64(t_lc *lc, t_file *f)
{
	if ((void *)lc + sizeof(t_lc) > f->ptr + f->size)
		return (ft_nm_err(f->name, STR_FILE_TOO_SMALL, 0));
	if (lc->cmdsize < sizeof(*lc))
		return (ft_nm_err(f->name, STR_LCS_TOO_SMALL, 0));
	return (EXIT_SUCCESS);
}

t_sect64	*copy_sect64(t_sect64 *sect, t_file *f, uint32_t idx)
{
	f->sec[idx].secname = sect->sectname;
	f->sec[idx].segname = sect->segname;
	if (!ft_strcmp(sect->segname, SEG_TEXT)
			&& !ft_strcmp(sect->sectname, SECT_TEXT))
		f->sec[idx].letter = 't';
	else if (!ft_strcmp(sect->segname, SEG_DATA) &&
			!ft_strcmp(sect->sectname, SECT_DATA))
		f->sec[idx].letter = 'd';
	else if (!ft_strcmp(sect->segname, SEG_DATA) &&
			!ft_strcmp(sect->sectname, SECT_BSS))
		f->sec[idx].letter = 'b';
	else
		f->sec[idx].letter = 's';
	sect++;
	return (sect);
}

int			test_lc_32(t_lc *lc, t_file *f)
{
	if ((void *)lc + sizeof(t_lc) > f->ptr + f->size)
		return (ft_nm_err(f->name, STR_FILE_TOO_SMALL, 0));
	if (lc->cmdsize < sizeof(*lc))
		return (ft_nm_err(f->name, STR_LCS_TOO_SMALL, 0));
	return (EXIT_SUCCESS);
}

t_sect		*copy_sect32(t_sect *sect, t_file *f, uint32_t idx)
{
	f->sec[idx].secname = sect->sectname;
	f->sec[idx].segname = sect->segname;
	if (!ft_strcmp(sect->segname, SEG_TEXT)
			&& !ft_strcmp(sect->sectname, SECT_TEXT))
		f->sec[idx].letter = 't';
	else if (!ft_strcmp(sect->segname, SEG_DATA) &&
			!ft_strcmp(sect->sectname, SECT_DATA))
		f->sec[idx].letter = 'd';
	else if (!ft_strcmp(sect->segname, SEG_DATA) &&
			!ft_strcmp(sect->sectname, SECT_BSS))
		f->sec[idx].letter = 'b';
	else
		f->sec[idx].letter = 's';
	sect++;
	return (sect);
}
