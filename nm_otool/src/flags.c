/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 11:04:07 by fflorens          #+#    #+#             */
/*   Updated: 2017/08/08 14:29:39 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_nm_otool.h"
#include "libft.h"

void		setflags32(t_file *file, t_mhdr *hdr)
{
	file->cpu = 32;
	if (hdr->filetype == MH_DYLIB)
		file->flag |= FLAG_DYLIB;
	if (hdr->filetype == MH_OBJECT)
		file->flag |= FLAG_OBJ;
	if (hdr->filetype == MH_DYLINKER)
		file->flag |= FLAG_DYLINK;
	if (hdr->filetype == MH_OBJECT)
		file->flag |= FLAG_LIB;
	if (hdr->filetype == MH_DYLIB_STUB)
		file->flag |= FLAG_DYLIB;
	file->cputype = file->cputype ? file->cputype : hdr->cputype;
}

void		setflags64(t_file *file, t_mhdr64 *hdr)
{
	file->cpu = 64;
	if (hdr->filetype == MH_DYLIB)
		file->flag |= FLAG_DYLIB;
	if (hdr->filetype == MH_OBJECT)
		file->flag |= FLAG_OBJ;
	if (hdr->filetype == MH_DYLINKER)
		file->flag |= FLAG_DYLINK;
	if (hdr->filetype == MH_BUNDLE)
		file->flag |= FLAG_BUNDLE;
	if (hdr->filetype == MH_DYLIB_STUB)
		file->flag |= FLAG_DYLIB;
	file->cputype = file->cputype ? file->cputype : hdr->cputype;
}
