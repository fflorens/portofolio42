/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_next_word.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzak <jzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 18:20:28 by jzak              #+#    #+#             */
/*   Updated: 2014/03/26 18:20:49 by jzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

void			move_to_next_word_evt(t_nboon *l)
{
	t_utf8		c;

	c = 32;
	while (l->b_pos < l->b_len && (c == ' ' || c == '\t'))
	{
		c = get_next_char(l->buf, &l->b_pos);
		l->b_curor += get_display_width(c);
	}
	c = 0;
	while (l->b_pos < l->b_len && (c != ' ' && c != '\t'))
	{
		c = get_next_char(l->buf, &l->b_pos);
		l->b_curor += get_display_width(c);
	}
	g_refresh_fn(l);
}
