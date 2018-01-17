/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_reseau.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 15:37:51 by bgauci            #+#    #+#             */
/*   Updated: 2014/06/26 16:22:43 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_RESEAU_H
# define STRUCT_RESEAU_H

# include <stdbool.h>

enum	e_type
{
	IHM,
	IA,
	NEW
};

typedef struct	s_connexion
{
	int					fd;
	char				*buffer_read;
	char				*buffer_write;
	enum e_type			type;
	bool				dead;
	int					id;
	struct s_connexion	*next;
}				t_connexion;

#endif

