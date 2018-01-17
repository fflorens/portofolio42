/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzak <jzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 00:28:14 by jzak              #+#    #+#             */
/*   Updated: 2014/03/27 21:44:56 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "libft.h"
#include "array.h"
#include "completion.h"

t_uint64			get_path_hash(const char **path)
{
	unsigned int	i;
	struct stat		folder;
	t_uint64		ret;

	i = 0;
	ret = 0;
	while (path[i] != NULL)
	{
		if (stat(path[i], &folder) == 0)
			ret ^= folder.st_ctime;
		++i;
	}
	return (ret);
}
