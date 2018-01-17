/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 14:45:31 by fflorens          #+#    #+#             */
/*   Updated: 2013/12/22 18:41:19 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FTF_H
# define HEIGHT 480
# define WIDTH 640
# define TITLE "FDF"
# define CST1 15
# define CST2 15
# define MAX(A,B) (((A) > (B)) ? (A) : (B))
# define MIN(A,B) (((A) < (B)) ? (A) : (B))
# define ABS(A) (((A) < 0) ? (-1 * (A)) : (A))
# include <string.h>
# include "gnl.h"
typedef struct	s_2dp
{
	int			x2d;
	int			y2d;
	int			x3d;
	int			y3d;
	int			z3d;
}				t_2dp;

typedef struct	s_linetmp
{
	int			dx;
	int			dy;
	int			e1;
	int			e2;
	int			sx;
	int			sy;
}				t_linetmp;

typedef struct		s_lstp
{
	t_2dp			*p;
	struct s_lstp	*next;
}					t_lstp;

typedef struct	s_fdf
{
	void		*mlx;
	void		*win;
	int			x2dmax;
	int			y2dmax;
	int			x2dmin;
	int			y2dmin;
	int			z3dmax;
	int			z3dmin;
	t_lstp		*list;
}				t_fdf;


/*
** basic.c
*/
t_2dp				*ft_project(int x, int y, int z, t_fdf *fdf);
void				fdf_fill_list(t_fdf *fdf, const int fd);
void				ft_draw_line(t_2dp *start, t_2dp *end, t_fdf *fdf);
void				ft_pixel_draw(t_2dp *pt, t_fdf *fdf);
void				fdf_list_resize(t_fdf *fdf);
/*
** ft_open.c
*/
int					ft_open(char *name);

/*
** hook.c
*/
int					key_hook(int keycode, t_fdf *fdf);
int					expose_hook(t_fdf *fdf);

/*
** lstp.c
*/
t_lstp				*ft_new_lstp(t_2dp *point);
void				ft_add_lstp(t_2dp *point, t_lstp *lst);
int					ft_atoi(const char *s);
int					ft_isdigit(int c);
void				fdfdestroylst(t_lstp *lst);

/*
** fdf.c
*/
void				fdfdestroy(t_fdf **fdf);
t_fdf				*fdfinit(void);
size_t				ft_strlen(char *str);
int					usage(char *name, int status);

/*
** show_me.c
*/
void				show_me_the_magic(t_fdf *fdf);
#endif				/*		!FDF_H		*/
