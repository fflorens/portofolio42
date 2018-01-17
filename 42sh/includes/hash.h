/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzak <jzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 19:18:42 by jzak              #+#    #+#             */
/*   Updated: 2014/03/26 19:42:11 by jzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_H
# define HASH_H

# include <stdlib.h>

# define HASHTABLE_SIZE 16383
# define MAX_COLISION 500

# define HASH_KEY_1 0x880355f21e6d1965ULL
# define HASH_KEY_2 0x2127599bf4325c37ULL
# define HASH_SALT 42ULL

# define HASHFN(key)	hash_function((const void*)key, ft_strlen(key) + 1)
# define EQFN(a, b)		(!ft_memcmp((a), (b), (ft_strlen(a) + 1)))

typedef unsigned long long		t_uint64;

typedef struct				s_hash
{
	t_uint64				result;
	const t_uint64			*pos;
	const t_uint64			*end;
	const unsigned char		*strpos;
}							t_hash;

typedef struct				s_entry
{
	struct s_entry			*next;
	const char				*key;
	const char				*val;
	size_t					index;
}							t_entry;

typedef struct				s_chainhash
{
	size_t					mask;
	size_t					overload;
	t_entry					**tbl;
	struct s_chainhash		*next;
}							t_chainhash;

/*
** Internal hash function
*/
t_uint64					hash_function(const void *content,
												size_t content_size);

/*
** Public api
*/
t_chainhash					*chainhash_init(size_t min);
t_entry						*chainhash_get(t_chainhash *ch, const char *key);
int							chainhash_set(t_chainhash **ch, const char *key,
															const void *data);
void						chainhash_del(t_entry *e);
void						chainhash_clear(t_chainhash *ch);
void						chainhash_destroy(t_chainhash *ch);

#endif
