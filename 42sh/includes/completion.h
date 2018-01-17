/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzak <jzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 19:14:15 by jzak              #+#    #+#             */
/*   Updated: 2014/03/27 15:31:24 by jzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLETION_H
# define COMPLETION_H

# include "nboon.h"
# include "hash.h"
# include "array.h"

# define COMP_SIZE_TABLE 16384

typedef struct			s_completion
{
	t_uint64			path_hash;
	t_array				*bin;
	t_array				*result;
}						t_completion;

typedef struct dirent	t_dir;

/*
** Global
*/
extern t_completion		*g_comp;

/*
** PUBLIC API
** callback.c completion.c
*/
char					*autocomplete_line(const t_line *l, const char *word,
																	size_t n);
void					refresh_completion_table(const char **path);
void					free_completion(void);

/*
** bin.c
*/
void					complete_bin(t_array *arr, const char *word, size_t n);

/*
** file.c
*/
void					complete_file(t_array *arr, const char *path, size_t n);

/*
** display.c
*/
void					completion_display(t_array *arr);

/*
** util.c
*/
t_uint64				get_path_hash(const char **path);

#endif
