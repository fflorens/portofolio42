/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_libft.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/22 22:24:21 by bgauci            #+#    #+#             */
/*   Updated: 2014/05/22 22:24:47 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_LIBFT_H
# define STRUCT_LIBFT_H

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_strlist
{
	char				*content;
	struct s_strlist	*next;
}				t_strlist;

typedef struct	s_intlist
{
	int					value;
	struct s_intlist	*next;
}				t_intlist;

#endif
