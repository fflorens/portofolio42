/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_me.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 15:00:20 by fflorens          #+#    #+#             */
/*   Updated: 2013/12/22 18:56:33 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			show_me_the_magic(t_fdf *fdf)
{
	t_lstp		*t;
	t_lstp		*cur;

	cur = fdf->list;
	while (cur)
	{
		t = cur;
		while (t)
		{
			if (t->p->x3d == cur->p->x3d && t->p->y3d == (cur->p->y3d + 1))
				ft_draw_line(cur->p, t->p, fdf);
			else if (t->p->x3d == (cur->p->x3d + 1) && t->p->y3d == cur->p->y3d)
				ft_draw_line(cur->p, t->p, fdf);
			t = t->next;
		}
		cur = cur->next;
	}
}
