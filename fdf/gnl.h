/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 18:52:57 by fflorens          #+#    #+#             */
/*   Updated: 2013/12/22 18:52:57 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H
# include <string.h>
# define BUFF_SIZE 300
typedef struct	s_static
{
	char		**buff;
	int			nb_buff;
}				t_static;
void	*ft_memalloc(size_t size);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnew(size_t size);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
int		gnl(int const fd, char ** line);
int		gnl2(char **buff, char **line, int fd);
void	ft_upgrade(t_static **static_buff, int const fd);
void	ft_upgrade2(t_static **static_buff, int const fd);
char	*ft_truncate(char **s, char c);
char	*ft_strncpy(char *s1, const char *s2, size_t n);
void	ft_bzero(void *s, size_t n);
#endif
