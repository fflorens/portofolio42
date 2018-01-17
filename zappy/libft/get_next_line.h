/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 16:37:35 by bgauci            #+#    #+#             */
/*   Updated: 2014/05/16 17:25:23 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1024

typedef struct	s_static
{
	char		**buff;
	int			nb_buff;
}				t_static;

static int		get_next_line2(char **buff, char **line, int fd);
static void		ft_upgrade(t_static **static_buff, int const fd);
static void		ft_upgrade2(t_static **static_buff, int const fd);

#endif
