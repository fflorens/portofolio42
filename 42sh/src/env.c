/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 01:06:32 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/27 22:29:34 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char			**g_env = NULL;

void			*sh_envmanager(int action)
{
	extern char		**environ;
	int				len;
	int				b_len;

	if (action == ENV_INIT && g_env == NULL)
		g_env = ft_strarrdup(environ, -1);
	if (action == ENV_GETPTR)
		return (g_env);
	if (action == ENV_FREE)
	{
		ft_strarrdel(&g_env, -1);
		g_env = NULL;
	}
	if (action != ENV_ADDSLOT)
		return (NULL);
	len = (int)ft_strarrlen((const char**)g_env);
	b_len = (len) * sizeof(char *);
	g_env = (char**)ft_realloc(g_env, b_len, b_len + 2 * sizeof(char *));
	g_env[len] = ft_strnew(0);
	g_env[len + 1] = NULL;
	return (NULL);
}

char			*sh_getenv(const char *name)
{
	int		sep_pos;
	int		i;
	int		name_len;

	if (!g_env)
		return (NULL);
	name_len = ft_strlen(name);
	i = 0;
	while (g_env[i])
	{
		sep_pos = ft_indexof(g_env[i], '=');
		if (sep_pos == name_len && ft_memcmp(name, g_env[i], sep_pos) == 0)
			return (g_env[i] + sep_pos + 1);
		i++;
	}
	return (NULL);
}

int				sh_setenv(const char *name, const char *value, int overwrite)
{
	int		sep_pos;
	int		i;
	char	*tmp_str;

	if (!sh_getenv(name))
		sh_envmanager(ENV_ADDSLOT);
	else if (!overwrite)
		return (-1);
	i = 0;
	while (g_env[i])
	{
		sep_pos = ft_indexof(g_env[i], '=');
		if (!*g_env[i] || (sep_pos > 0 && !ft_memcmp(g_env[i], name, sep_pos)))
		{
			tmp_str = FT_STRJOIN(name, "=", value);
			ft_strdel(&g_env[i]);
			g_env[i] = tmp_str;
			return (0);
		}
		i++;
	}
	return (-1);
}

int				sh_putenv(char *string)
{
	char	*sep;

	sh_envmanager(ENV_INIT);
	sep = ft_strchr(string, '=');
	if (sep == NULL || sep == string)
		return (-1);
	*sep = '\0';
	return (sh_setenv(string, (sep + 1), 1));
}

int				sh_unsetenv(const char *name)
{
	int		sep_pos;
	int		i;
	int		j;

	sh_envmanager(ENV_INIT);
	if (!sh_getenv(name))
		return (-1);
	i = 0;
	j = 0;
	while (g_env[i])
	{
		sep_pos = ft_indexof(g_env[i], '=');
		if (sep_pos > 0 && ft_memcmp(g_env[i], name, sep_pos) == 0)
		{
			ft_strdel(&g_env[i]);
			j++;
		}
		g_env[i++] = g_env[j++];
	}
	return (0);
}
