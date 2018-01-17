/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 17:50:52 by bgauci            #+#    #+#             */
/*   Updated: 2014/05/10 19:37:11 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# define DEBUG 1

int		put_nbr_fd(int n, int fd);
int		put_str_fd(char *txt, int fd);
void	debug(char *txt);
void	debug_nb(int nb);
void	debug_lock(void);
void	debug_unlock(void);
#endif
