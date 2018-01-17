/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_hdr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 11:00:26 by fflorens          #+#    #+#             */
/*   Updated: 2017/08/08 16:02:41 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_nm_otool.h"

extern char	*g_arch;

static int	ft_is_text_hdr(t_file *file)
{
	return ((!file->flag || file->flag == 8 || file->flag == 32)
			&& g_arch && !ft_strcmp(g_arch, "all"));
}

static int	ft_has_good_arch(t_file *file)
{
	if (file->flag == 148 || file->flag == 144
			|| file->flag == 209 || (g_arch && ft_strcmp(g_arch, "all")))
		return (EXIT_SUCCESS);
	else if ((file->flag & FLAG_ARCH || file->flag == 0
				|| file->flag == 32 || file->flag == 8)
			&& !g_arch)
		return (EXIT_SUCCESS);
	else if (file->flag == 1 && file->best_arch)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

void		ft_otool_header(t_file *file)
{
	if (ft_is_text_hdr(file))
	{
		ft_putstr("Contents of (__TEXT,__text) section\n");
		return ;
	}
	if (ft_has_good_arch(file) != EXIT_FAILURE)
	{
		ft_putstr(file->name);
		ft_putstr(":\n");
	}
	else
	{
		ft_putstr(file->name);
		ft_putstr(" (architecture ");
		ft_putstr(file->archname);
		ft_putstr("):\n");
	}
	if (!file->sec)
		return ;
	ft_putstr("Contents of (__TEXT,__text) section\n");
}
