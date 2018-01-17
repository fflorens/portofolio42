/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/22 18:35:06 by bgauci            #+#    #+#             */
/*   Updated: 2014/06/26 21:05:59 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRITE_H
# define WRITE_H

# include "struct_reseau.h"

void	add_write(char	*txt, t_connexion *fd);
void	write_fd(t_connexion *fd);
void	send_data(int id, char *txt);

#endif
