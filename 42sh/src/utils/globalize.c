/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 18:07:28 by bgauci            #+#    #+#             */
/*   Updated: 2014/03/25 20:40:12 by jzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <glob.h>
#include "utils.h"
#include "libft.h"

static char		**globalize_str(char *pattern)
{
	int			ret;
	glob_t		obj;
	char		**array;

	if (pattern == NULL)
		return (FT_NEWPTR(char*, 1));
	ft_bzero(&obj, sizeof(obj));
	ret = glob(pattern, GLOB_NOCHECK, NULL, &obj);
	if (ret < 0)
	{
		array = FT_NEWPTR(char*, 2);
		array[0] = ft_strdup(pattern);
	}
	else
		array = ft_strarrdup(obj.gl_pathv, -1);
	globfree(&obj);
	return (array);
}

char			**sh_globalize(char *pattern)
{
	char				*str_copy;
	char				**result;

	str_copy = ft_strdup(pattern);
	sh_expandvar(&str_copy);
	sh_expanduser(&str_copy);
	result = globalize_str(str_copy);
	ft_strdel(&str_copy);
	return (result);
}
