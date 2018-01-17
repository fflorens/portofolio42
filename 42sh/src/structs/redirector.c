/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 16:38:58 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/27 21:33:07 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "dynbuf.h"
#include "structs.h"

void			redirector_init(t_redirector *redirector)
{
	ft_bzero(redirector, sizeof(*redirector));
	redirector->open_mode = 0666;
	redirector->open_flag = (O_CREAT | O_WRONLY);
	redirector->old_fd = FD_UNSET;
	redirector->new_fd = FD_UNSET;
}

t_redirector	*redirector_new(void)
{
	t_redirector	redirector;
	t_redirector	*copy;

	redirector_init(&redirector);
	copy = ft_memdup(&redirector, sizeof(redirector));
	return (copy);
}

void			redirector_del(t_redirector **ptr)
{
	t_redirector	*redirector;

	redirector = *ptr;
	if (redirector == NULL)
		return ;
	ft_strdel(&redirector->file);
	ft_strdel(&redirector->heredoc_label);
	dynbuf_del(&redirector->heredoc_buf);
	*ptr = redirector->next;
	ft_memdel((void**)&redirector);
}

void			redirector_add(t_redirector **list, t_redirector *new)
{
	t_redirector	*redirector;

	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	redirector = *list;
	while (redirector->next != NULL)
		redirector = redirector->next;
	redirector->next = new;
}
