/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 13:44:46 by bgauci            #+#    #+#             */
/*   Updated: 2014/06/26 22:39:35 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include "struct_libft.h"
# include "tree_avl.h"

void		ft_perror		(char *txt);
void		exit_perror		(char *txt, int i);
void		*ft_memalloc	(size_t size);
void		ft_memdel		(void **ap);
char		*ft_strnew		(size_t size);
void		ft_strdel		(char **as);
void		ft_strclr		(char *s);
void		ft_striter		(char *s, void (*f)(char *));
void		ft_striteri		(char *s, void (*f)(unsigned int, char *));
char		*ft_strmap		(char const *s, char (*f)(char));
char		*ft_strmapi		(char const *s, char (*f)(unsigned int, char));
int			ft_strequ		(char const *s1, char const *s2);
int			ft_strnequ		(char const *s1, char const *s2, size_t n);
char		*ft_strsub		(char const *s, unsigned int start, size_t len);
char		*ft_strjoin		(char const *s1, char const *s2);
char		*ft_strtrim		(char const *s);
char		**ft_strsplit	(char const *s, char c);
char		*ft_itoa		(int n);
void		ft_putchar		(char c);
void		ft_putstr		(char const *s);
void		ft_putendl		(char const *s);
void		ft_putnbr		(int n);
void		ft_putchar_fd	(char c, int fd);
void		ft_putstr_fd	(char const *s, int fd);
void		ft_putendl_fd	(char const *s, int fd);
void		ft_putnbr_fd	(int n, int fd);

int			ft_toupper		(int c);
int			ft_tolower		(int c);
void		*ft_memset		(void *b, int c, size_t len);
void		ft_bzero		(void *s, size_t n);
void		*ft_memcpy		(void *s1, const void *s2, size_t n);
void		*ft_memccpy		(void *s1, const void *s2, int c, size_t n);
void		*ft_memmove		(void *s1, const void *s2, size_t n);
void		*ft_memchr		(const void *s, int c, size_t n);
int			ft_memcmp		(const void *s1, const void *s2, size_t n);
size_t		ft_strlen		(const char *s);
char		*ft_strdup		(const char *s1);
char		*ft_strcpy		(char *s1, const char *s2);
char		*ft_strncpy		(char *s1, const char *s2, size_t n);
char		*ft_strcat		(char *s1, const char *s2);
char		*ft_strncat		(char *s1, const char *s2, size_t n);
size_t		ft_strlcat		(char *dst, const char *src, size_t size);
char		*ft_strchr		(const char *s, int c);
char		*ft_strrchr		(const char *s, int c);
char		*ft_strnstr		(const char *s1, const char *s2, size_t n);
char		*ft_strstr		(const char *s1, const char *s2);
int			ft_strcmp		(const char *s1, const char *s2);
int			ft_strncmp		(const char *s1, const char *s2, size_t n);
int			ft_strrncmp		(const char *s1, const char *s2, size_t n);
int			ft_atoi			(const char *str);
int			ft_isalpha		(int c);
int			ft_isdigit		(int c);
int			ft_isalnum		(int c);
int			ft_isascii		(int c);
int			ft_isprint		(int c);
void		ft_strjcat		(char **s1, const char *s2);
char		*ft_truncate	(char **s, char c);
void		ft_strreverse	(char *s);
char		*ft_strnjoin	(char const *s1, char const *s2, int nb);
void		ft_strnjcat		(char **s1, const char *s2, int nb);
char		*ft_strndup		(const char *s1, int nb);

t_list		*ft_lstnew		(void const *content, size_t content_size);
void		ft_lstdelone	(t_list **alst, void (*del)(void *, size_t));
void		ft_lstdel		(t_list **alst, void (*del)(void *, size_t));
void		ft_lstadd		(t_list **alst, t_list *root);
void		ft_lstaddend	(t_list **alst, t_list *root);
void		ft_lstiter		(t_list *lst, void (*f)(t_list *elem));
t_list		*ft_lstmap		(t_list *lst, t_list *(*f)(t_list *elem));
void		ft_lstswap		(t_list *a, t_list *b);

t_strlist	*ft_strlstnew	(char const *content);
void		ft_strlstdelone	(t_strlist **alst);
void		ft_strlstdel	(t_strlist **alst);
void		ft_strlstadd	(t_strlist **alst, t_strlist *root);
void		ft_strlstaddend	(t_strlist **alst, t_strlist *root);
void		ft_strlstiter	(t_strlist *lst, void (*f)(t_strlist *elem));
t_strlist	*ft_strlstmap	(t_strlist *lst, t_strlist *(*f)(t_strlist *elem));

t_intlist	*ft_intlstnew	(int value);
void		ft_intlstdelone	(t_intlist **alst);
void		ft_intlstdel	(t_intlist **alst);
void		ft_intlstadd	(t_intlist **alst, t_intlist *root);
void		ft_intlstaddend	(t_intlist **alst, t_intlist *root);
void		ft_intlstiter	(t_intlist *lst, void (*f)(t_intlist *elem));
t_intlist	*ft_intlstmap	(t_intlist *lst, t_intlist *(*f)(t_intlist *elem));

int			pgcd			(int a, int b);
char		*ft_strfastcat	(char *s1, const int s1_len, const char *s2);
char		*ft_strfastdup	(const char *s1, const int s1_len);
void		ft_strfastjoin	(char **s1, const char *s2, int s1_len, int s2_len);
char		*ft_strfastnew	(const size_t size);
char		*ft_strfastsub	(char *s, size_t start, size_t len, size_t s_len);
char		*ft_fasttruncate(char **s, int s_len, char *tmp);

int			ft_strhach_bis	(char *str);
int			ft_strhach		(char *str);

int			gnl				(int const fd, char **line);
int			get_next_line	(int const fd, char **line);

#endif
