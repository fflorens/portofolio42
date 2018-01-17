/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 03:52:16 by fflorens          #+#    #+#             */
/*   Updated: 2014/02/23 15:13:29 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		<stdlib.h>
#include		<unistd.h>
#include		<lemin.h>

static void		ft_putnbr(int n)
{
	char		c;

	if (n < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-1 * n);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
	}
}

void			ft_show_the_magic(t_room *room)
{
	static int	space = 0;

	if (!room)
	{
		if (space)
			write(1, "\n", 1);
		space = 0;
	}
	else if (room)
	{
		if (space)
			write(1, " ", 1);
		else
			space = 1;
		write(1, "L", 1);
		ft_putnbr(room->n);
		write(1, "-", 1);
		write(1, room->name, ft_strlen(room->name));
	}
}

int				ft_move_rec(t_list *lst, int *antsd, int *nants, int antsnb)
{
	if (!lst || !lst->next)
		return (0);
	ft_move_rec(lst->next, antsd, nants, antsnb);
	if (ROOM(lst->data)->state & STATE_ANT)
	{
		ROOM(lst->next->data)->state |= STATE_ANT;
		ROOM(lst->next->data)->n = ROOM(lst->data)->n;
		ROOM(lst->data)->state &= ~STATE_ANT;
		ft_show_the_magic(lst->next->data);
		if (ROOM(lst->next->data)->state & STATE_END)
			(*antsd)++;
	}
	else if ((ROOM(lst->data)->state & STATE_START) && (*nants > 0))
	{
		ROOM(lst->next->data)->state |= STATE_ANT;
		ROOM(lst->next->data)->n = antsnb - (*nants) + 1;
		*nants -= 1;
		ft_show_the_magic(lst->next->data);
		if (ROOM(lst->next->data)->state & STATE_END)
			(*antsd)++;
	}
	return (0);
}
