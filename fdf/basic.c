/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 18:10:50 by fflorens          #+#    #+#             */
/*   Updated: 2013/12/22 19:03:47 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "fdf.h"

void			fdf_fill_list(t_fdf *fdf, const int fd)
{
	char		*line;
	int			c[3];
	int			i;

	line = NULL;
	c[0] = 0;
	while (gnl(fd, &line))
	{
		i = 0;
		c[1] = 0;
		while (line[i])
		{
			while (!ft_isdigit(line[i]) && line[i])
				i++;
			c[2] = ft_atoi(line + i);
			if (!(fdf->list))
				fdf->list = ft_new_lstp(ft_project(c[1], c[0], c[2], fdf));
			else
				ft_add_lstp(ft_project(c[1], c[0], c[2], fdf), fdf->list);
			while (ft_isdigit(line[i]))
				i++;
			c[1] += 1;
		}
		c[0] += 1;
	}
}

t_2dp			*ft_project(int x, int y, int z, t_fdf *fdf)
{
	t_2dp		*point;

	if ((point = (t_2dp *)malloc(sizeof(t_2dp))) == NULL)
		return (NULL);
	point->x2d = CST1 * x - CST2 * y;
	point->y2d = ((CST1 * x + CST2 * y) / 2) - z;
	point->z3d = z;
	point->x3d = x;
	point->y3d = y;
	fdf->x2dmax = MAX(fdf->x2dmax, point->x2d);
	fdf->x2dmin = MIN(fdf->x2dmin, point->x2d);
	fdf->y2dmax = MAX(fdf->y2dmax, point->y2d);
	fdf->y2dmin = MIN(fdf->y2dmin, point->y2d);
	fdf->z3dmax = MAX(fdf->z3dmax, point->z3d);
	fdf->z3dmin = MIN(fdf->z3dmin, point->z3d);
	return (point);
}

void			ft_draw_line(t_2dp *start, t_2dp *end, t_fdf *fdf)
{
	t_2dp		tmp;
	t_linetmp	er;

	tmp = *start;
	tmp.z3d = MAX(start->z3d, end->z3d);
	er.dx = ABS(start->x2d - end->x2d);
	er.dy = ABS(start->y2d - end->y2d);
	er.sx = ((start->x2d < end->x2d) ? 1 : -1);
	er.sy = ((start->y2d < end->y2d) ? 1 : -1);
	er.e1 = er.dx - er.dy;
	ft_pixel_draw(&tmp, fdf);
	while (tmp.x2d != end->x2d || tmp.y2d != end->y2d)
	{
		er.e2 = 2 * er.e1;
		if (er.e2 > -1 * er.dy)
		{
			er.e1 -= er.dy;
			tmp.x2d += er.sx;
		}
		if (er.e2 < er.dx)
			er.e1 += er.dx;
		if (er.e2 < er.dx)
			tmp.y2d += er.sy;
		ft_pixel_draw(&tmp, fdf);
	}
}

void			ft_pixel_draw(t_2dp *pt, t_fdf *fdf)
{
	int			color;

	color = 0xFFFFFF - ((fdf->z3dmax - pt->z3d) * 0x101010);
	mlx_pixel_put(fdf->mlx, fdf->win, pt->x2d, pt->y2d, color);
}

void			fdf_list_resize(t_fdf *fdf)
{
	t_2dp		*tmp;
	int			ratio;
	t_lstp		*lst;

	lst = fdf->list;
	ratio = 1;
	while (lst)
	{
		tmp = lst->p;
		tmp->x2d *= ratio;
		tmp->x2d += (WIDTH / 2);
		tmp->y2d *= ratio;
		tmp->y2d += (HEIGHT / 2);
		lst = lst->next;
	}
}
