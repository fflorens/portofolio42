/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 06:26:56 by fflorens          #+#    #+#             */
/*   Updated: 2014/03/22 19:21:26 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		LEMIN_H
# define	LEMIN_H
# define	FLAG_START		"##start"
# define	FLAG_END		"##end"
# define	STATE_NOTHING	0
# define	STATE_ANT		2
# define	STATE_START		4
# define	STATE_END		8
# define	STATE_PASSED	16
# define	STATE_OK		32
# define	COMMENT			'#'
# define	BUFF_SIZE		1024
# define	W_LINK_ERROR	"%s \"%s\" and \"%s\" %s"
# define	W_LINK_ERROR1	"Warning: Cannot create link between rooms"
# define	W_LINK_ERROR2	" please check if they both exists.\n"
# define	W_LINK_EXIST	"Warning: Link from room \"%s\" to room \"%s\" %s"
# define	W_LINK_EXIST2	"already exists.\n"
# define	E_ROOM_EXIST	"Error: Room name already in use : \"%s\"\n."
# define	E_MALLOC_FAIL	"Error: malloc failed\n"
# define	E_NOSTART		"Error: No starting room found!\n"
# define	E_NOEND			"Error: No end room found!\n"
# define	E_NOSOL			"Error: No solution exist!\n"
# define	ROOM(a)			((t_room *) a)

typedef struct	s_link		t_link;
typedef struct	s_room		t_room;
typedef struct	s_list		t_list;
typedef struct	s_map		t_map;
typedef struct	s_gnl
{
	char		*buffer;
	int			i;
}				t_gnl;

typedef struct	s_lemin
{
  t_map			*map;
  t_list		*paths;
  t_room		*start;
  int			nants;
}				t_lemin;

struct			s_link
{
  t_room		*room;
  t_link		*next;
};

struct			s_room
{
  char			*name;
  unsigned int	state;
  int			n;
  t_link		*link;
};

struct			s_list
{
  void			*data;
  t_list		*next;
};

struct			s_map
{
  t_list		*graph;
  int			nnode;
  int			nlink;
};

/*
** algo.c
*/
t_list			*ft_pathfinder(t_map *map, t_room *start);

/*
** cleanup,c
*/
t_room			*ft_destroy_room(t_room *room);
t_map			*ft_destroy_map(t_map *map);
int				ft_lstdestroy(t_list *lst);
void			ft_destroypaths(t_list *s);
void			ft_strdel(char **as);

/*
** error.c
*/
int				ft_error(const char *fmt, ...);
void			*ft_malloc_noerror(unsigned int sz);

/*
** ft_gnl.c
*/
int				ft_gnl(const int fd, char **line);

/*
** list.c
*/
t_list			*ft_lstnewappend(void *data, t_list *next);
t_list			*ft_lstpushback(t_list *lst, void *new);
unsigned int	ft_lstlen(t_list *lst);

/*
** move.c
*/
void			ft_show_the_magic(t_room *a);
int				ft_move_rec(t_list *lst, int *antsd, int *nants, int antsnb);

/*
** new.c
*/
t_room			*ft_newroom(char *name, unsigned int state);
t_link			*ft_newlink(t_room *room, t_link *next);

/*
** parsing.c
*/
void			ft_get_the_infos(t_lemin *lemin);

/*
** search.c
*/
t_room			*ft_find_room_flagged(t_list *lst, unsigned int flag);
t_room			*ft_getroom(t_list *lst, char *name);
int				ft_roomexist(t_list *lst, char *name);
int				ft_existlink(t_link *link, t_room *room);

/*
** cleanup.c
*/
int				ft_strcmp(const char *s1, const char *s2);
int				ft_flexstrcmp(char *line, char *s);
char			*ft_strchr(char *s, char c);
char			*ft_strdup(const char *s);
int				ft_strlen(const char *s);

/*
** utils.c
*/
void			ft_putendl(char *s);
void			ft_set_state_pass(t_room *room);
void			ft_unset_state_pass(t_room *room);
void			ft_set_state_done(t_room *room);

#endif		/* !LEMIN_H */
