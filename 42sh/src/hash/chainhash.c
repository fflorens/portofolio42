/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chainhash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzak <jzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 21:46:55 by jzak              #+#    #+#             */
/*   Updated: 2014/03/27 21:46:56 by jzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "hash.h"

t_entry		*chainhash_get(t_chainhash *ch, const char *key)
{
	t_entry				*e;
	size_t				h;

	h = HASHFN(key) & ch->mask;
	e = NULL;
	while (ch)
	{
		e = ch->tbl[h];
		while (e)
		{
			if (EQFN(e->key, key))
				return (e);
			e = e->next;
		}
		ch = ch->next;
	}
	return (e);
}

int			chainhash_set(t_chainhash **ch, const char *key, const void *data)
{
	t_entry				*e;
	size_t				h;
	t_chainhash			*new;

	if ((*ch)->overload >= MAX_COLISION)
	{
		new = chainhash_init((*ch)->mask);
		new->next = *ch;
		*ch = new;
	}
	else
		new = *ch;
	h = HASHFN(key) & new->mask;
	e = (t_entry*)ft_xmalloc(sizeof(t_entry));
	e->key = key;
	e->val = data;
	e->next = NULL;
	if (new->tbl[h] != NULL)
	{
		new->overload++;
		e->next = new->tbl[h];
	}
	new->tbl[h] = e;
	return (0);
}

void		chainhash_del(t_entry *e)
{
	free(e);
}
