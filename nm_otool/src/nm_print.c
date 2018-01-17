/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 13:19:45 by fflorens          #+#    #+#             */
/*   Updated: 2017/08/08 13:31:11 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach-o/nlist.h>
#include <mach-o/stab.h>
#include <unistd.h>
#include <stdio.h>
#include "ft_nm_otool.h"
#include "libft.h"
#define HEXBASE "0123456789abcdef"

static char	get_type(t_sec *sec, uint32_t sec_nb, t_sym sym)
{
	char	letter;

	letter = ' ';
	(void)sec_nb;
	if (sym.type == N_UNDF && sym.addr)
		letter = 'c';
	else if (sym.type == N_UNDF && !sym.addr)
		letter = 'u';
	else if (sym.type == N_ABS)
		letter = 'a';
	else if (sym.type == N_INDR)
		letter = 'i';
	else if (sym.type == N_SECT)
		letter = sec[sym.sectnb].letter;
	if (sym.ext)
		letter = ft_toupper(letter);
	if (sym.stab)
		letter = '-';
	return (letter);
}

static void	print_hex_addr(uint64_t addr, int cpu)
{
	char	s[17];
	int		i;

	ft_bzero(s, 8);
	i = (cpu == 64) ? 16 : 8;
	while (i--)
	{
		s[i] = HEXBASE[addr % 16];
		addr /= 16;
	}
	i = (cpu == 64) ? 16 : 8;
	s[i] = ' ';
	write(STDOUT_FILENO, s, i + 1);
}

int			print_f(t_file *f)
{
	uint32_t	i;
	char		type;

	i = 0;
	while (i < f->sym_idx)
	{
		type = get_type(f->sec, f->sec_idx, f->sym[i]);
		if (f->sym[i].name && !f->sym[i].stab)
		{
			if (!(!f->sym[i].addr && f->sym[i].type == N_UNDF))
				print_hex_addr(f->sym[i].addr, f->sym[i].cpu);
			else if (f->sym[i].cpu == 32)
				ft_putstr("         ");
			else if (f->sym[i].cpu == 64)
				ft_putstr("                 ");
		}
		ft_putchar(type);
		ft_putstr(" ");
		if (f->sym[i].name)
			ft_putstr(f->sym[i].name);
		ft_putstr("\n");
		i++;
	}
	return (EXIT_SUCCESS);
}
