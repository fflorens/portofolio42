/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 03:52:31 by fflorens          #+#    #+#             */
/*   Updated: 2014/02/23 15:17:12 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
#include	<lemin.h>

void		ft_putendl(char *s)
{
	int		i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
	write(1, "\n", 1);
}

void		ft_set_state_pass(t_room *room)
{
	room->state |= STATE_PASSED;
}

void		ft_unset_state_pass(t_room *room)
{
	room->state &= ~STATE_PASSED;
}

void		ft_set_state_done(t_room *room)
{
	room->state |= STATE_OK;
}
