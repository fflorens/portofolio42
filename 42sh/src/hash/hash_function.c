/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 18:07:41 by bgauci            #+#    #+#             */
/*   Updated: 2014/03/27 21:47:43 by jzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

static t_uint64		mix_hash(t_uint64 hash, const t_uint64 *end, size_t size)
{
	const unsigned char		*endbyte;
	size_t					octopus;
	t_uint64				mixer;

	endbyte = (const unsigned char*)end;
	octopus = size & 7;
	mixer = 0;
	if (octopus)
	{
		while (octopus > 0)
		{
			mixer ^= (t_uint64)endbyte[octopus - 1] << ((octopus - 1) * 8);
			octopus--;
		}
		mixer ^= mixer >> 23;
		mixer *= HASH_KEY_2;
		hash ^= mixer ^ (mixer >> 47);
		hash *= HASH_KEY_1;
	}
	return (hash);
}

t_uint64			hash_function(const void *content, size_t content_size)
{
	t_uint64			hash;
	t_uint64			mixer;
	const t_uint64		*pos;
	const t_uint64		*end;

	pos = (const t_uint64*)content;
	end = pos + (content_size >> 3);
	hash = content_size * HASH_KEY_1 ^ HASH_SALT;
	while (pos < end)
	{
		mixer = *pos++;
		mixer ^= mixer >> 23;
		mixer *= HASH_KEY_2;
		hash ^= mixer ^ (mixer >> 47);
		hash *= HASH_KEY_1;
	}
	hash = mix_hash(hash, pos, content_size);
	hash = (hash ^ (hash >> 23)) * HASH_KEY_2;
	return (hash ^ (hash >> 47));
}
