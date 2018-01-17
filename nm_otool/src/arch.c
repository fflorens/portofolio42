/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arch.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 10:07:54 by fflorens          #+#    #+#             */
/*   Updated: 2017/08/08 14:36:22 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/sysctl.h>
#include <sys/utsname.h>
#include "ft_nm_otool.h"
#include "libft.h"

extern char	*g_arch;

NXArchInfo	*get_host_arch(void)
{
	int			mib[2];
	char		name[_SYS_NAMELEN];
	size_t		len;

	mib[0] = CTL_HW;
	mib[1] = HW_MACHINE;
	len = sizeof(name);
	if (sysctl(mib, 2, &name, &len, NULL, 0) == -1)
		return (NULL);
	return ((NXArchInfo *)NXGetArchInfoFromName(name));
}

t_farch		*get_best_arch(t_farch *arch, uint32_t narch)
{
	t_farch		*bestarch;
	NXArchInfo	*info;

	if (g_arch && !ft_strcmp(g_arch, "all"))
		return (NULL);
	else if (g_arch)
		info = (NXArchInfo *)NXGetArchInfoFromName(g_arch);
	else
		info = get_host_arch();
	bestarch = NXFindBestFatArch(info->cputype, info->cpusubtype, arch, narch);
	if (!bestarch && narch == 1)
		if (arch->cpusubtype == info->cpusubtype)
		{
			if (arch->cputype == info->cputype)
				return (arch);
			else if (arch->cputype == 7 && info->cputype == 16777223)
				return (arch);
		}
	return (bestarch);
}

void		set_arch(t_file *file, t_farch *arch)
{
	NXArchInfo	*info;

	info = (NXArchInfo *)NXGetArchInfoFromCpuType(arch->cputype,
			arch->cpusubtype);
	if (info)
	{
		ft_strcat(file->archname, info->name);
		file->cputype = info->cputype;
		if (!ft_strcmp(info->name, "armv5"))
			file->archname[5] = 'e';
		if (!ft_strcmp(info->name, "armv7m")
				|| !ft_strcmp(info->name, "armv7em"))
		{
			file->archname[0] = '\0';
			ft_strcat(file->archname, "thumb");
			ft_strcat(file->archname, &(info->name[3]));
		}
	}
}
