/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realpath.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 18:17:56 by fflorens          #+#    #+#             */
/*   Updated: 2014/03/25 20:47:19 by jzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	simplifydotnb(char **tmp, int i, int nb)
{
	if (i && nb == 2)
	{
		free(tmp[i]);
		free(tmp[i - 1]);
		tmp[i - 1] = NULL;
		tmp[i] = NULL;
		while (tmp[i + 1])
		{
			tmp[i - 1] = tmp[i + 1];
			tmp[i + 1] = NULL;
			i++;
		}
	}
	else
	{
		free(tmp[i]);
		tmp[i] = NULL;
		while (tmp[i + 1])
		{
			tmp[i] = tmp[i + 1];
			tmp[i + 1] = NULL;
			i++;
		}
	}
}

static char	*tab_to_abspath(char **tmp)
{
	int		i;
	int		len;
	char	*out;

	len = 0;
	if (!tmp[0])
		return (ft_strdup("/"));
	i = -1;
	while (tmp[++i])
		len += 1 + ft_strlen(tmp[i]);
	if (!(out = ft_strnew(len)))
		return (NULL);
	i = -1;
	while (tmp[++i])
	{
		ft_strcat(out, "/");
		ft_strcat(out, tmp[i]);
	}
	return (out);
}

static void	simplifypath(char **pwd)
{
	char	**tmp;
	char	*new;
	int		i;
	int		j;

	if (!(tmp = ft_strsplit(*pwd, '/')))
		return ;
	i = -1;
	j = 1;
	while (j--)
	{
		while (tmp[++i])
		{
			if (!ft_strcmp(tmp[i], ".") && ++j)
				simplifydotnb(tmp, i, 1);
			else if (!ft_strcmp(tmp[i], "..") && ++j)
				simplifydotnb(tmp, i, 2);
		}
	}
	if (!(new = tab_to_abspath(tmp)))
		return ;
	ft_strdel(pwd);
	ft_strarrdel(&tmp, i);
	*pwd = new;
}

char		*sh_realpath(char **orig_ptr)
{
	if (!*orig_ptr || **orig_ptr == '\0')
		return (*orig_ptr);
	sh_abspath(orig_ptr);
	simplifypath(orig_ptr);
	return (*orig_ptr);
}
