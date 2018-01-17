/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_redirector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 19:34:32 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/27 15:32:04 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include "exec.h"

static int			open_file(char *name, int flag, int mode)
{
	int				fd;
	struct stat		info;

	if ((stat(name, &info) >= 0) && S_ISDIR(info.st_mode))
		ERROR(NAME, name, ft_strerror(EISDIR));
	else if ((fd = open(name, flag, mode)) < 0)
		ERROR(NAME, name, ERRNO);
	else
		return (fd);
	return (-1);
}

static t_bool		build_redirector_file(char **file_ptr)
{
	char			*file;
	char			**tab;

	file = *file_ptr;
	tab = sh_globalize(file);
	if (ft_strarrlen((const char**)tab) != 1)
	{
		ft_strarrdel(&tab, -1);
		ERROR(NAME, *file_ptr, "ambiguous redirect");
		return (FALSE);
	}
	ft_strdel(&file);
	*file_ptr = tab[0];
	ft_memdel((void**)&tab);
	return (TRUE);
}

static t_bool		build_redirector(t_redirector *redir)
{
	int				fd;

	if (redir->heredoc_label != NULL)
		return (TRUE);
	if (redir->file != NULL)
	{
		if (build_redirector_file(&redir->file) == FALSE)
			return (FALSE);
		fd = open_file(redir->file, redir->open_flag, redir->open_mode);
		if (fd < 0)
			return (FALSE);
		redir->new_fd = fd;
	}
	else if (redir->new_fd == FD_OUT_OF_RANGE)
	{
		ERROR(NAME, "file descriptor out of range", EBADF);
		return (FALSE);
	}
	if (dup2(redir->new_fd, redir->old_fd) >= 0)
		return (TRUE);
	ERROR(NAME, ERRNO);
	return (FALSE);
}

t_bool				build_process_redirectors(t_process *process)
{
	t_bool			status;
	t_redirector	*redir;

	status = TRUE;
	redir = process->first_redirector;
	while ((status == TRUE) && (redir != NULL))
	{
		if (build_redirector(redir) == FALSE)
			status = FALSE;
		redir = redir->next;
	}
	return (status);
}

t_bool				build_process_heredoc(t_process *process, int fd)
{
	t_redirector	*hdoc;
	t_redirector	*redirector;

	hdoc = NULL;
	redirector = process->first_redirector;
	while (redirector != NULL)
	{
		if (redirector->heredoc_buf != NULL)
			hdoc = redirector;
		redirector = redirector->next;
	}
	if (hdoc == NULL)
		return (TRUE);
	if (hdoc->old_fd != STDIN_FILENO)
		fd = hdoc->old_fd;
	if (write(fd, hdoc->heredoc_buf->ptr, hdoc->heredoc_buf->pos) < 0)
		return (FALSE);
	return (TRUE);
}
