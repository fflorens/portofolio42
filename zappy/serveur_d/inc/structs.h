/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 17:37:33 by dbenoit           #+#    #+#             */
/*   Updated: 2014/06/18 21:46:59 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "zappy.h"

typedef struct		s_case
{
	int				x;
	int				y;
	int				res[7];
}					t_case;

typedef struct		s_map
{
	int				time;
	int				width;
	int				height;
	struct s_case	**cases;
}					t_map;

typedef struct		s_team
{
	char			*name;
	struct s_team	*next;
}					t_team;

typedef struct		s_egg
{
	int				x;
	int				y;
	struct s_team	*team;
	int				turnalive;
	int				turndead;
	struct s_egg	*next;
}					t_egg;

typedef struct		s_player
{
	int				clientid;
	char			*name;
	struct s_team	*team;
	int				level;
	int				x;
	int				y;
	int				angle;
	enum e_cmd		action;
	int				actionturnleft;
	char			*actionparams;
	int				res[7];
	struct s_player	*next;
}					t_player;

typedef struct		s_req
{
	int				clientid;
	enum e_cmd		cmd;
	char			*params;
	struct s_req	*next;
}					t_req;

#endif
