/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 20:38:59 by bgauci            #+#    #+#             */
/*   Updated: 2014/03/27 13:16:37 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/stat.h>
#include "shell.h"
#include "printf.h"

#define OPT_N		1
#define OPT_E		2

static int		get_opt(char c, void *container)
{
	char	*opt;

	opt = (char *)container;
	if (c == 'n')
		*opt = *opt | OPT_N;
	else if (c == 'e')
		*opt = *opt | OPT_E;
	else if (c == 'E')
		*opt = (*opt & ~OPT_E);
	else
	{
		ft_dprintf(2, "echo : -%c: invalid option\n", c);
		ft_dprintf(2, "%s: usage: echo [-neE] [string ...] \n", NAME);
		return (-1);
	}
	return (0);
}

static void		ft_octal_write(int fd, char *txt, int *i)
{
	char			*value;
	char			buf[2];

	if (!ft_isdigit(txt[*i]) && txt[*i] > '7')
		return ;
	if (!ft_isdigit(txt[*i + 1]) && txt[*i] > '7')
		return ;
	if (!ft_isdigit(txt[*i + 2]) && txt[*i] > '7')
		return ;
	value = ft_strnew(3);
	ft_strncpy(value, txt + *i, 3);
	buf[0] = (char)ft_abasetoui(value, "01234567");
	buf[1] = '\0';
	free(value);
	*i = *i + 3;
	write(fd, buf, 1);
}

static void		echo_character_sequences(char *txt, int *i)
{
	if (txt[*i] == 'a')
		write(1, "\a", 1);
	else if (txt[*i] == 'b')
		write(1, "\b", 1);
	else if (txt[*i] == 'f')
		write(1, "\f", 1);
	else if (txt[*i] == 'n')
		write(1, "\n", 1);
	else if (txt[*i] == 'r')
		write(1, "\r", 1);
	else if (txt[*i] == 't')
		write(1, "\t", 1);
	else if (txt[*i] == 'v')
		write(1, "\v", 1);
	else if (txt[*i] == '\\')
		write(1, "\\", 1);
	else if (ft_isdigit(txt[*i]))
		ft_octal_write(1, txt, i);
	else
		return ;
	(*i) += 1;
}

static void		echo_printf(char	*txt, char opt)
{
	int	i;

	i = 0;
	while (txt[i])
	{
		if (txt[i] == '\\' && (opt & OPT_E))
		{
			i++;
			echo_character_sequences(txt, &i);
		}
		else
		{
			write(1, txt + i, 1);
			i++;
		}
	}
}

int				echo_builtin(char **argv)
{
	int		i;
	char	opt;
	int		argc;

	opt = '\0';
	argc = ft_strarrlen((const char **)argv);
	if ((i = ft_optiter(argc, argv, get_opt, (void*)&opt)) == -1)
		return (1);
	while (i < argc)
	{
		echo_printf(argv[i], opt);
		i++;
		if (i < argc)
			write(1, " ", 1);
	}
	if (!(opt & OPT_N))
		write(1, "\n", 1);
	return (0);
}
