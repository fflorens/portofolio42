/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 11:01:00 by fflorens          #+#    #+#             */
/*   Updated: 2017/08/08 11:51:40 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCTS_H
# define FT_STRUCTS_H
# include <mach-o/arch.h>
# include <mach-o/nlist.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <mach-o/fat.h>
# include <mach-o/loader.h>
# include "ft_nm_otool.h"

typedef struct fat_header			t_fhdr;
typedef struct mach_header			t_mhdr;
typedef struct mach_header_64		t_mhdr64;
typedef struct fat_arch				t_farch;
typedef struct load_command			t_lc;
typedef struct segment_command		t_segc;
typedef struct segment_command_64	t_segc64;
typedef struct section				t_sect;
typedef struct section_64			t_sect64;
typedef struct symtab_command		t_symc;

typedef struct stat					t_stat;
typedef struct nlist				t_nlist;
typedef struct nlist_64				t_nlist64;
typedef struct ar_hdr				t_ar;

typedef struct						s_sec
{
	char		*secname;
	char		*segname;
	char		letter;
	uint64_t	addr;
	void		*base;
	uint64_t	size;
}									t_sec;
typedef struct						s_sym
{
	uint64_t	addr;
	uint32_t	sectnb;
	char		ext;
	char		stab;
	char		type;
	char		cpu;
	char		*name;
}									t_sym;
typedef struct						s_file
{
	void		*ptr;
	off_t		size;
	char		*name;
	int			cpu;
	cpu_type_t	cputype;
	cpu_type_t	hostcpu;
	int			flag;
	char		archname[50];
	uint32_t	sym_idx;
	uint32_t	sec_idx;
	int			first;
	t_sym		*sym;
	t_sec		*sec;
	t_farch		*best_arch;
}									t_file;

#endif
