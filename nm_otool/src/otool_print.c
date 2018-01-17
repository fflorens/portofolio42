/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 17:14:20 by fflorens          #+#    #+#             */
/*   Updated: 2017/08/08 16:03:11 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <mach/machine.h>
#include "ft_nm_otool.h"
#include "libft.h"
#define HEXBASE "0123456789abcdef"

static void	swap_ref(cpu_type_t type, void *cur, void *ref, off_t size)
{
	char	*s;
	char	c;

	if (type != CPU_TYPE_ARM && type != CPU_TYPE_ARM64)
		return ;
	s = cur;
	if (((cur + 4) - ref) > size)
		return ;
	c = s[0];
	s[0] = s[3];
	s[3] = c;
	c = s[2];
	s[2] = s[1];
	s[1] = c;
}

static void	print_hex_char(unsigned char c)
{
	char hex[3];

	hex[2] = 0;
	hex[1] = HEXBASE[c % 16];
	hex[0] = HEXBASE[(c / 16) % 16];
	ft_putstr(hex);
}

static void	hexdump(void *ref, off_t size, int width, cpu_type_t cputype)
{
	void	*cur;
	int		i;

	cur = ref;
	while ((cur - ref) < 16)
	{
		swap_ref(cputype, cur, ref, size);
		i = 0;
		while (i++ < width)
		{
			if ((cur - ref) >= size)
				return ;
			else
				print_hex_char(*(unsigned char *)cur);
			cur++;
		}
		ft_putchar(' ');
	}
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
	s[i] = '\t';
	write(STDOUT_FILENO, s, i + 1);
}

int			print_f(t_file *file)
{
	uint64_t	off;
	t_sec		*sec;

	off = 0;
	if (!file->sec)
		return (EXIT_SUCCESS);
	sec = file->sec;
	while (off < sec->size)
	{
		print_hex_addr(sec->addr + off, file->cpu);
		if (file->cputype == CPU_TYPE_ARM ||
				file->cputype == CPU_TYPE_ARM64 ||
				file->cputype == CPU_TYPE_POWERPC ||
				file->cputype == CPU_TYPE_POWERPC64)
			hexdump(sec->base + off, sec->size - off, 4, file->cputype);
		else
			hexdump(sec->base + off, sec->size - off, 1, file->cputype);
		ft_putstr("\n");
		off += 16;
	}
	return (EXIT_SUCCESS);
}
