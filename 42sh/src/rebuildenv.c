/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rebuildenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 17:49:28 by fflorens          #+#    #+#             */
/*   Updated: 2014/03/27 23:19:35 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include			<pwd.h>
#include			<grp.h>
#include			<unistd.h>
#include			<sys/types.h>
#include			"libft.h"
#include			"structs.h"
#include			"shell.h"

static int			g_rebuild = 1;

int					opt_rebuild(char **av, int ac, void *userdata)
{
	(void)av;
	(void)ac;
	(void)userdata;
	g_rebuild = 0;
	return (0);
}

static char			*ft_path(int i)
{
	if (i == 0)
		return ("/usr/local/bin");
	if (i == 1)
		return ("/usr/bin");
	if (i == 2)
		return ("/bin");
	if (i == 3)
		return ("/usr/sbin");
	if (i == 4)
		return ("/sbin");
	if (i == 5)
		return ("/opt/X11/bin");
	if (i == 6)
		return ("/usr/textbin");
	else
		return (NULL);
}

static char			*rebuild_path(char *pwd)
{
	char			*tmp1;
	char			*tmp2;
	unsigned int	i;

	i = -1;
	tmp1 = NULL;
	tmp2 = NULL;
	while (ft_path(++i))
	{
		if (chdir(ft_path(i)) != -1)
		{
			if (tmp2)
			{
				tmp1 = FT_STRJOIN(tmp2, ":");
				ft_strdel(&tmp2);
			}
			if (tmp1)
				tmp2 = FT_STRJOIN(tmp1, ft_path(i));
			else
				tmp2 = ft_strdup(ft_path(i));
			ft_strdel(&tmp1);
		}
	}
	chdir(pwd);
	return (tmp2);
}

void				sh_rebuildenv(void)
{
	t_group			group;
	t_group			*tmp;
	t_passwd		passwd;
	t_passwd		*tmppwd;
	char			buffer[200];

	if (g_rebuild == 0)
		return ;
	getpwuid_r(getuid(), &passwd, buffer, 200, &tmppwd);
	if (sh_getenv("USER") == NULL)
		sh_setenv("USER", ft_strdup(passwd.pw_name), 1);
	if (sh_getenv("HOME") == NULL)
		sh_setenv("HOME", ft_strdup(passwd.pw_dir), 1);
	if (sh_getenv("PWD") == NULL)
		sh_setenv("PWD", getcwd(NULL, 0), 1);
	getgrgid_r(getgid(), &group, buffer, 200, &tmp);
	if (sh_getenv("GROUP") == NULL)
		sh_setenv("GROUP", ft_strdup(group.gr_name), 1);
	if (sh_getenv("PATH") == NULL)
		sh_setenv("PATH", rebuild_path(sh_getenv("PWD")), 1);
}
