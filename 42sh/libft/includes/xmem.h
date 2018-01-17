/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmem.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 16:46:38 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/25 20:09:11 by jzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** A magic malloc handler that saves allocated pointers into a static
** linked list, and free all of them if called with XMEM_FREE flag
*/

#ifndef XMEM_H
# define XMEM_H

# ifndef NULL
#  define NULL ((void*)0)
# endif

# define XMEM_ALLOC 0
# define XMEM_FREE_TAG 1
# define XMEM_FREE_ALL 2

typedef struct		s_xmem_link
{
	void			*ptr;
	int				tag;
}					t_xmem_link;

void				*xmem_core(int action, void *ptr, int tag);
void				*xmem(void *ptr, int tag);
void				xmem_free(int tag);
void				xmem_free_all(void);

#endif
