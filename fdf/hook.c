/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 16:12:51 by fflorens          #+#    #+#             */
/*   Updated: 2013/12/22 19:06:03 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <mlx.h>
#include <stdlib.h>
#include "fdf.h"

int		key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == 65307)
	{
		fdfdestroy(&fdf);
		exit(0);
	}
	return (0);
}

int		expose_hook(t_fdf *fdf)
{
	show_me_the_magic(fdf);
	return (0);
}
