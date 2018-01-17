/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expandvar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 18:06:49 by bgauci            #+#    #+#             */
/*   Updated: 2014/03/25 18:05:56 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <glob.h>
#include "exec.h"

static void			concat_var(t_dynbuf *buf, char *str, int *idx)
{
	char			*tmp_str;
	int				i;

	i = *idx + 1;
	while (ft_isalnum(str[i]) || (str[i] == '_' && str[i + 1] == '\0'))
		i++;
	tmp_str = ft_strsub(str, ((*idx) + 1), (i - (*idx) - 1));
	dynbuf_write(buf, (char*)sh_getvar(tmp_str), -1);
	ft_strdel(&tmp_str);
	*idx = i;
}

static void			concat_special_var(t_dynbuf *buf, char *str, int *idx)
{
	char			*tmp_str;

	tmp_str = ft_strsub(str, (*idx + 1), 1);
	dynbuf_write(buf, (char*)sh_getvar(tmp_str), -1);
	ft_strdel(&tmp_str);
	*idx = *idx + 2;
}

char				*sh_expandvar(char **orig_ptr)
{
	t_dynbuf		*buf;
	int				i;
	char			*old;

	buf = dynbuf_new(64);
	old = *orig_ptr;
	i = 0;
	while (old[i] != '\0')
	{
		if (old[i] == '$' && ft_strchr("!@#$*1234567890-?", old[i + 1]))
			concat_special_var(buf, old, &i);
		else if (old[i] == '$' && (ft_isalpha(old[i + 1]) || old[i + 1] == '_'))
			concat_var(buf, old, &i);
		else
			dynbuf_write(buf, &old[i++], 1);
	}
	ft_strdel(&old);
	*orig_ptr = dynbuf_tostr(buf);
	dynbuf_del(&buf);
	return (*orig_ptr);
}
