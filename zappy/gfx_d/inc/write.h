/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/22 18:35:06 by bgauci            #+#    #+#             */
/*   Updated: 2014/06/26 16:25:12 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRITE_H
# define WRITE_H

# include "struct_reseau.h"

void	snapshot(void);
void	add_write(char	*txt);
void	write_fd(int fd);

#endif
