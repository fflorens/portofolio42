/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 13:46:35 by fflorens          #+#    #+#             */
/*   Updated: 2017/08/08 13:47:47 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned short		ft_swap_16(unsigned short val)
{
	return (((val & 0xff00) >> 8) |
			((val & 0x00ff) << 8));
}

unsigned int		ft_swap_32(unsigned int val)
{
	return (((val & 0xff000000) >> 24) |
			((val & 0x00ff0000) >> 8) |
			((val & 0x0000ff00) << 8) |
			((val & 0x000000ff) << 24));
}

unsigned long long	ft_swap_64(unsigned long long val)
{
	return (((val & 0xff00000000000000ULL) >> 56) |
			((val & 0x00ff000000000000ULL) >> 40) |
			((val & 0x0000ff0000000000ULL) >> 24) |
			((val & 0x000000ff00000000ULL) >> 8) |
			((val & 0x00000000ff000000ULL) << 8) |
			((val & 0x0000000000ff0000ULL) << 24) |
			((val & 0x000000000000ff00ULL) << 40) |
			((val & 0x00000000000000ffULL) << 56));
}
