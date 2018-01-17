/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chainhash_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzak <jzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 21:47:08 by jzak              #+#    #+#             */
/*   Updated: 2014/03/27 21:47:22 by jzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "hash.h"

/*
** Create a fresh chainhash of 'min' size.
** The size is converted to multiple of 8 with a binary trick
*/
t_chainhash			*chainhash_init(size_t min)
{
	t_chainhash		*ch;

	ch = (t_chainhash*)malloc(sizeof(t_chainhash));
	if (ch == NULL)
		return (NULL);
	--min;
	min |= min >> 1;
	min |= min >> 2;
	min |= min >> 4;
	min |= min >> 8;
	min |= min >> 16;
	if (sizeof(size_t) == 8)
		min |= (unsigned long long)min >> 32;
	ch->tbl = (t_entry **)malloc(sizeof(t_entry*) * (min + 1));
	if (ch->tbl == NULL)
	{
		free(ch);
		return (NULL);
	}
	ch->overload = 0;
	ch->next = NULL;
	ch->mask = min;
	return (ch);
}

void				chainhash_clear(t_chainhash *ch)
{
	size_t		i;
	size_t		mask;
	t_entry		*e;
	t_entry		*next;

	i = 0;
	mask = ch->mask;
	while (i <= mask)
	{
		if (ch->tbl[i])
		{
			e = ch->tbl[i];
			while (e != NULL)
			{
				next = e->next;
				free(e);
				e = next;
			}
			ch->tbl[i] = NULL;
		}
		++i;
	}
}

void				chainhash_destroy(t_chainhash *ch)
{
	while (ch)
	{
		chainhash_clear(ch);
		free(ch->tbl);
		free(ch);
		ch = ch->next;
	}
}
