/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 13:11:37 by fflorens          #+#    #+#             */
/*   Updated: 2017/08/08 17:05:31 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_nm_otool.h"
#include "libft.h"

int		otool_test_lc(t_lc *lc, t_file *f)
{
	if ((void *)lc + sizeof(t_lc) > f->ptr + f->size)
		return (ft_otool_err(f->name, STR_FILE_TOO_SMALL, 0));
	if (lc->cmdsize < sizeof(*lc))
		return (ft_otool_err(f->name, STR_LCS_TOO_SMALL, 0));
	return (EXIT_SUCCESS);
}

t_sec	*copy_sec64(t_sect64 *sec, t_file *file)
{
	t_sec	*out;

	if ((out = malloc(sizeof(t_sec))) == NULL)
	{
		ft_putstr_fd("ft_otool: malloc error\n", STDERR_FILENO);
		return (NULL);
	}
	out->addr = sec->addr;
	out->base = file->ptr + sec->offset;
	out->size = sec->size;
	return (out);
}

t_sec	*copy_sec(t_sect *sec, t_file *file)
{
	t_sec	*out;

	if ((out = malloc(sizeof(t_sec))) == NULL)
	{
		ft_putstr_fd("ft_otool: malloc error\n", STDERR_FILENO);
		return (NULL);
	}
	out->addr = sec->addr;
	out->base = file->ptr + sec->offset;
	out->size = sec->size;
	return (out);
}

int		check_sec(t_file *file)
{
	if (!file->sec)
		return (EXIT_SUCCESS);
	if ((void *)(file->sec->size + file->sec->base)
			> (void *)file->ptr + file->size)
		return (ft_otool_err(file->name, STR_FILE_TOO_SMALL, 0));
	return (EXIT_SUCCESS);
}
