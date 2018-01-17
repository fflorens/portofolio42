/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 17:17:03 by fflorens          #+#    #+#             */
/*   Updated: 2017/05/30 09:57:20 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach-o/nlist.h>
#include <mach-o/stab.h>
#include "ft_nm_otool.h"
#include "libft.h"

extern char	*g_arch;

cpu_type_t	arch_cpu_type(void)
{
	cpu_type_t	out;
	NXArchInfo	*info;

	out = 0;
	if (!g_arch)
		return (out);
	if ((info = (NXArchInfo *)NXGetArchInfoFromName(g_arch)) == NULL)
		return (out);
	out = info->cputype;
	return (out);
}

static int	cmp_sym(t_sym s1, t_sym s2)
{
	int ret;

	if (!s1.name && !s2.name)
		ret = 0;
	else if (!s1.name && s2.name)
		ret = -1;
	else if (s1.name && !s2.name)
		ret = 1;
	else
		ret = ft_strcmp(s1.name, s2.name);
	if (ret == 0)
		ret = s1.addr - s2.addr;
	return (ret);
}

void		sort_f(t_file *file)
{
	uint32_t	i;
	uint32_t	j;
	uint32_t	k;
	t_sym		sym;

	i = 0;
	while (i < file->sym_idx)
	{
		j = i;
		k = j;
		while (j < file->sym_idx)
		{
			if (j != k && cmp_sym(file->sym[k], file->sym[j]) > 0)
				k = j;
			++j;
		}
		if (i != k)
		{
			sym = file->sym[i];
			file->sym[i] = file->sym[k];
			file->sym[k] = sym;
		}
		i++;
	}
}
