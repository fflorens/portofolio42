/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 17:19:36 by fflorens          #+#    #+#             */
/*   Updated: 2017/08/09 11:45:42 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ar.h>
#include <unistd.h>
#include "libft.h"
#include "ft_nm_otool.h"

extern char	*g_arch;

int		ft_nm_err(char *name, char *msg, char arch)
{
	ft_putstr_fd("ft_nm: '", STDERR_FILENO);
	ft_putstr_fd(name, STDERR_FILENO);
	if (arch)
		ft_putstr_fd("' does not contains arch '", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	if (arch)
		ft_putstr_fd("'\n", STDERR_FILENO);
	return (EXIT_FAILURE);
}

int		check_has_arch(t_file *file)
{
	NXArchInfo	*info;
	cpu_type_t	type;
	cpu_type_t	archtype;

	if (!g_arch)
		return (EXIT_SUCCESS);
	else if (*(unsigned int *)file->ptr == MH_CIGAM)
		type = ft_swap_32(((t_mhdr *)file->ptr)->cputype);
	else if (*(unsigned int *)file->ptr == MH_MAGIC)
		type = ((t_mhdr *)file->ptr)->cputype;
	else if (*(unsigned int *)file->ptr == MH_CIGAM_64)
		type = ft_swap_32(((t_mhdr64 *)file->ptr)->cputype);
	else if (*(unsigned int *)file->ptr == MH_MAGIC_64)
		type = ((t_mhdr64 *)file->ptr)->cputype;
	else
		return (EXIT_SUCCESS);
	if ((info = (NXArchInfo *)NXGetArchInfoFromName(g_arch)) == NULL)
		return (ft_nm_err(file->name, "' arch error\n", 0));
	archtype = info->cputype;
	if (g_arch && ft_strcmp(g_arch, "all") && archtype != type)
		return (ft_nm_err(file->name, "' no architecture specified\n", 0));
	return (EXIT_SUCCESS);
}

int		ft_nm(t_file *file)
{
	static int	not_first = 0;

	file->first = (file->first ? 1 : not_first);
	not_first = 1;
	if (check_has_arch(file) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (*(unsigned int *)file->ptr == FAT_CIGAM)
		return (nm_handle_fat(file, SWAP));
	else if (*(unsigned int *)file->ptr == FAT_MAGIC)
		return (nm_handle_fat(file, NOSWAP));
	else if (*(unsigned int *)file->ptr == MH_CIGAM)
		return (nm_handle_32(file, SWAP));
	else if (*(unsigned int *)file->ptr == MH_MAGIC)
		return (nm_handle_32(file, NOSWAP));
	else if (*(unsigned int *)file->ptr == MH_CIGAM_64)
		return (nm_handle_64(file, SWAP));
	else if (*(unsigned int *)file->ptr == MH_MAGIC_64)
		return (nm_handle_64(file, NOSWAP));
	else if (file->size < SARMAG)
		return (ft_nm_err(file->name, "' file size too small\n", 0));
	else if (!ft_strncmp(file->ptr, ARMAG, SARMAG))
		return (nm_handle_ar(file, NOSWAP));
	else
		return (ft_nm_err(file->name, "' Unknown or unsupported format\n", 0));
}
