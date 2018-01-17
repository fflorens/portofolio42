/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_handle_ar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 13:17:12 by fflorens          #+#    #+#             */
/*   Updated: 2017/05/24 13:17:14 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach-o/ranlib.h>
#include <ar.h>
#include "libft.h"
#include "ft_nm_otool.h"

static unsigned int	archive_size(void *ptr)
{
	char *end;

	end = ft_strchr(ptr, '/');
	if (!end)
		return (0);
	return (ft_atoi(end + 1));
}

static char			*make_name(t_file *file, t_ar *ar)
{
	char	*t;
	char	*tmp;
	char	*tmp2;
	char	*out;

	if ((tmp = ft_strjoin(file->name, "(")) == NULL)
		return (NULL);
	if (!ft_strncmp("#1/", ar->ar_name, 3))
		t = ft_strdup((char *)(ar + 1));
	else
	{
		t = ft_strchr(ar->ar_name, ' ');
		t = ft_strndup(ar->ar_name, t - ar->ar_name);
	}
	if ((tmp2 = ft_strjoin(t, ")")) == NULL)
	{
		free(tmp);
		free(t);
		return (NULL);
	}
	free(t);
	out = ft_strjoin(tmp, tmp2);
	free(tmp);
	free(tmp2);
	return (out);
}

static int			handle_lib(t_file *file, t_ar *ar)
{
	int		res;
	t_file	f;

	ft_bzero(&f, sizeof(t_file));
	if ((f.name = make_name(file, ar)) == NULL)
		return (ft_error("Malloc error\n", NULL));
	ft_strcat(f.archname, file->archname);
	f.cpu = file->cpu;
	f.flag = file->flag | FLAG_AR;
	f.ptr = (void *)ar + sizeof(t_ar) + archive_size(ar->ar_name);
	f.size = ft_atoi(ar->ar_size);
	res = ft_otool(&f);
	free(f.sym);
	free(f.sec);
	free(f.name);
	return (res);
}

int					otool_handle_ar(t_file *f, char swap)
{
	t_ar	*ar;
	int		sz;

	(void)swap;
	ar = f->ptr + SARMAG;
	sz = ft_atoi(ar->ar_size);
	ar = f->ptr + SARMAG + sizeof(t_ar) + sz;
	if ((void *)ar + sizeof(t_ar) > f->ptr + f->size)
		return (ft_error("f too small\n", NULL));
	ft_otool_ar_hdr(f);
	while ((void *)ar + ft_atoi(ar->ar_size) + sizeof(*ar) <= f->ptr + f->size)
	{
		if (handle_lib(f, ar) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
		ar = (void *)ar + ft_atoi(ar->ar_size) + sizeof(t_ar);
	}
	return (EXIT_SUCCESS);
}
