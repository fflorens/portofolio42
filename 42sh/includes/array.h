/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzak <jzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 19:13:37 by jzak              #+#    #+#             */
/*   Updated: 2014/03/27 14:02:56 by jzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include <stdlib.h>

typedef struct	s_array
{
	size_t		size;
	size_t		used;
	char		**data;
}				t_array;

/*
** An array struct that grows automaticaly
** you can sort the array with cmp (function pointer)
*/
typedef int		(*t_cmp_fn)(const char*, const char*);

t_array			*init_array(size_t size);
void			array_push(t_array *arr, char *str);
void			*array_pop(t_array *arr);
void			array_clear(t_array *arr, void (*free_fn)(void*));
unsigned int	array_get_size(t_array *arr);
void			destroy_array(t_array *arr, void (*free_fn)(void*));
void			array_sort(t_array *arr, t_cmp_fn cmp);
void			array_riter(t_array *arr, void (*fn)(const char*));
void			array_iter(t_array *arr, void (*fn)(const char*));
int				array_find(t_array *arr, const char *name);
char			*array_to_str(t_array *arr, char *str);

#endif
