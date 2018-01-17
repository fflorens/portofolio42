/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm_otool.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 11:00:13 by fflorens          #+#    #+#             */
/*   Updated: 2017/08/08 16:01:26 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_OTOOL_H
# define FT_NM_OTOOL_H
# include "ft_structs.h"
# define SWAP 1
# define NOSWAP 0
# define ARCHX86 86
# define ARCHX64 64
# define ALLARCH 1
# define UNDEFARCH 0
# ifdef __x86_64__
#  define CURRARCH ARCHX64
# elif defined __i386__
#  define CURRARCH ARCHX86
# else
#  define CURRARCH UNDEFARCH
# endif
# define EXIT_DONE ((EXIT_FAILURE + EXIT_SUCCESS) * 2)
# define LONGSPACE "                \0"
# define SHORTSPACE "        \0"
# define FLAG_FAT   	1
# define FLAG_DYLINK	2
# define FLAG_LIB		4
# define FLAG_DYLIB		8
# define FLAG_OBJ		16
# define FLAG_BUNDLE	32
# define FLAG_ARCH		64
# define FLAG_AR		128
# define SHORT_PRINT	256
# define SLTM "': Mach-O segment load command contains too many sections.\n"
# define STR_LC_TOO_MANY SLTM
# define SLCTS "': Mach-O segment load command size is too small.\n"
# define STR_LC_CMD_TOO_SMALL SLCTS
# define SFTS "': Mach-O object file is too small.\n"
# define STR_FILE_TOO_SMALL SFTS
# define SLTS "': Mach-O load command with size < 8 bytes.\n"
# define STR_LCS_TOO_SMALL SLTS

int			ft_nm(t_file *file);
int			ft_otool(t_file *file);
int			otool_handle_fat(t_file *file, char swap);
int			otool_handle_32(t_file *file, char swap);
int			otool_handle_64(t_file *file, char swap);
int			otool_handle_ar(t_file *file, char swap);
int			nm_handle_fat(t_file *file, char swap);
int			nm_handle_32(t_file *file, char swap);
int			nm_handle_64(t_file *file, char swap);
int			nm_handle_ar(t_file *file, char swap);
int			ft_error(char *str, char *extra);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		swap_fat_header(t_fhdr *hdr, char swap);
void		swap_mach_header(t_mhdr *hdr, char swap);
void		swap_mach_header_64(t_mhdr64 *hdr, char swap);
void		swap_fat_arch(t_farch *archs, uint32_t nfat_arch, char sw);
void		swap_load_command(t_lc *lc, char swap);
void		swap_segment_command(t_segc *seg, char swap);
void		swap_segment_command_64(t_segc64 *seg, char swap);
void		swap_section(t_sect *sect, uint32_t nsects, char swap);
void		swap_section64(t_sect64 *sect, uint32_t nsects, char swap);
void		swap_symtab_command(t_symc *symt, char swap);
void		dump(t_file *file, uint32_t off, uint32_t size);
void		sort_f(t_file *file);
int			print_f(t_file *file);
void		setflags32(t_file *file, t_mhdr *hdr);
void		setflags64(t_file *file, t_mhdr64 *hdr);
int			ft_otool_err(char *name, char *msg, char arch);
int			ft_nm_err(char *name, char *msg, char arch);
t_sect64	*copy_sect64(t_sect64 *sect, t_file *f, uint32_t idx);
t_sect		*copy_sect32(t_sect *sect, t_file *f, uint32_t idx);
void		swap_nlist(struct nlist *sym, unsigned long nsym, char swap);
void		swap_nlist64(struct nlist_64 *sym, unsigned long nsym, char swap);
void		ft_nm_header(t_file *file);
void		ft_otool_header(t_file *file);
NXArchInfo	*get_host_arch();
t_farch		*get_best_arch(t_farch *arch, uint32_t narch);
void		set_arch(t_file *file, t_farch *arch);
int			otool_test_lc(t_lc *lc, t_file *f);
int			nm_test_lc(t_lc *lc, t_file *f);
t_sec		*copy_sec(t_sect *sec, t_file *file);
t_sec		*copy_sec64(t_sect64 *sec, t_file *file);
int			test_lc_32(t_lc *lc, t_file *f);
int			test_lc_64(t_lc *lc, t_file *f);
void		ft_otool_ar_hdr(t_file *f);
cpu_type_t	arch_cpu_type(void);
int			check_has_arch(t_file *file);
void		ft_otool_header(t_file *file);
int			check_sec(t_file *file);
#endif
