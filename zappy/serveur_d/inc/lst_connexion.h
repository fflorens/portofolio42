/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_connexion.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 17:34:59 by bgauci            #+#    #+#             */
/*   Updated: 2014/06/08 17:35:25 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_CONNEXION_H
# define LST_CONNEXION_H

# include "reseau.h"

t_connexion		*connexion_new		(int fd);
void			connexion_del		(t_connexion **base, t_connexion *current);
void			connexion_add		(t_connexion **base, t_connexion *new);

#endif
