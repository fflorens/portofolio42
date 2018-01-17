/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 14:43:34 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/18 14:45:25 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int		ft_atoui(const char *str)
{
	unsigned int	result;

	while ((*str > 8 && *str < 14) || (*str == ' '))
		str++;
	result = 0;
	while (*str >= '0' && *str <= '9')
		result = (result * 10) + (*str++ - '0');
	return (result);
}
