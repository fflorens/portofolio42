/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/05 19:35:07 by bgauci            #+#    #+#             */
/*   Updated: 2014/05/11 23:12:20 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philosophe.h"
#include	"debug.h"
#include	<unistd.h>
#include	<fcntl.h>

extern	int g_fd;
t_condi g_condi[21] = {
	{'a', 0, 0},
	{'A', 0, -1},
	{'b', 0, 1},
	{'B', 1, 1},
	{'c', 1, -1},
	{'C', 1, 2},
	{'d', 2, 2},
	{'D', 2, -1},
	{'e', 2, 3},
	{'E', 3, 3},
	{'f', 3, -1},
	{'F', 3, 4},
	{'g', 4, 4},
	{'G', 4, -1},
	{'h', 4, 5},
	{'H', 5, 5},
	{'i', 5, -1},
	{'I', 5, 6},
	{'j', 6, 6},
	{'J', 6, -1},
	{'k', 6, 0},
};

static void		aff_philo(char c, t_philo *ptab)
{
	int			i;
	t_status	stat;

	i = c - 'l';
	stat = ptab[i].stat;
	if (stat == EATING)
		write(g_fd, "\033[31m", 5);
	else if (stat == NOTHING)
		write(g_fd, "\033[32m", 5);
	else if (stat == THINKING)
		write(g_fd, "\033[36m", 5);
	else if (stat == DEAD)
		write(g_fd, "\033[33m", 5);
	else
		write(g_fd, "\033i[37m", 5);
	write(g_fd, "@", 1);
	write(g_fd, "\033[0m", 4);
}

static void		aff_stick(char c, t_stick *stab, t_philo *ptab)
{
	char	res;
	int		i;

	res = ' ';
	i = 0;
	while (i < 21)
	{
		if (g_condi[i].c == c)
		{
			if (g_condi[i].philo == -1)
			{
				if (stab[g_condi[i].stick].phid == -1)
					res = '@';
			}
			else if (stab[g_condi[i].stick].phid == ptab[g_condi[i].philo].id)
				res = '@';
		}
		i++;
	}
	write(g_fd, &res, 1);
}

static int		aff_pv_philo(char c, t_philo *ptab)
{
	if (c == 's')
		return (put_nbr_fd(ptab[0].pv, g_fd));
	else if (c == 't')
		return (put_nbr_fd(ptab[1].pv, g_fd));
	else if (c == 'u')
		return (put_nbr_fd(ptab[2].pv, g_fd));
	else if (c == 'v')
		return (put_nbr_fd(ptab[3].pv, g_fd));
	else if (c == 'w')
		return (put_nbr_fd(ptab[4].pv, g_fd));
	else if (c == 'x')
		return (put_nbr_fd(ptab[5].pv, g_fd));
	else if (c == 'y')
		return (put_nbr_fd(ptab[6].pv, g_fd));
	return (0);
}

static int		select_aff(char c, t_philo *ptab, t_stick *stab)
{
	t_stick		tmp[NB_PHIL];
	int			j;

	j = -1;
	while (++j < NB_PHIL)
		tmp[j].phid = stab[j].phid;
	if (c >= 'l' && c <= 'r')
		aff_philo(c, ptab);
	else if ((c >= 'a' && c <= 'k')
			|| (c >= 'A' && c <= 'J'))
		aff_stick(c, tmp, ptab);
	else if (c >= 's' && c <= 'y')
		return (aff_pv_philo(c, ptab) - 1);
	else if (c == 'K')
		return (put_str_fd("le philo", g_fd) - 1);
	else if (c == 'L')
		return (put_str_fd("a encore", g_fd) - 1);
	else if (c == 'M')
		return (put_str_fd("pv", g_fd) - 1);
	else
		write(g_fd, &c, 1);
	return (0);
}

int				display(t_philo *ptab, t_stick *stab, int nb)
{
	static char	img[16000];
	static int	len = 0;
	int			j;

	if (g_fd != STDOUT_FILENO)
		ft_clear_display();
	if (len == 0)
		len = read(open("src/img.img", O_RDONLY), img, 16000);
	put_str_fd("\033[31mmange \033[36mpense \033[32mrepos ", g_fd);
	put_str_fd("\033[33mmort \033[37minconnue\033[0m", g_fd);
	put_str_fd(" | tour ", g_fd);
	put_nbr_fd(nb, g_fd);
	put_str_fd("\n", g_fd);
	j = -1;
	while (++j < len)
		j += select_aff(img[j], ptab, stab);
	if (nb == TIMEOUT_T && !g_forcequit)
		put_str_fd("Now, it is time... To DAAAAAAAANCE ! ! !\n", g_fd);
	return (-1);
}
