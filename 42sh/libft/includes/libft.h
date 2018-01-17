/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:51:22 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/25 21:25:16 by jzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

/*
** define for ft_getline bufferization
*/
# define GETLINE_BUFF_SIZE (2048)

/*
** Special fake function handlers
*/
# define FT_NEWPTR(obj, size) ((obj*)ft_calloc(sizeof(obj) * size))
# define FT_ARRPUSH(arr, str) ((arr)[ft_strarrlen((const char**)(arr))] = str)
# define FT_STRJOIN(...) (ft_strjoin_va(0, __VA_ARGS__, NULL))
# define FT_ERROR(...) (ft_error_va(0, __VA_ARGS__, NULL))

/*
** Linked list manipulation
*/
typedef struct		s_list
{
	void			*data;
	size_t			size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(const void *data, size_t size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstdup(t_list *lst);
t_list				*ft_strarrtolst(int argc, char **argv);
int					ft_lstaddstr(t_list **alst, char *str);
int					ft_lstaddnew(t_list **alst, const void *data, size_t size);
void				ft_lstdelif(t_list **alst, void (*del)(void *, size_t),
		void *data_ref, int (*cmp)(void *, void *));
void				ft_lstaddsort(t_list **alst, t_list *new,
		int (*cmp)(void *, void *));
t_list				*ft_lstdupone(t_list *lst);
size_t				ft_lstlen(t_list *lst);
void				ft_lstrev(t_list **begin_list);
void				ft_lstsort(t_list *begin, int (*cmp)(void *, void *));

/*
** double linked lists
*/
typedef struct		s_dlist
{
	void			*data;
	size_t			size;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

t_dlist				*ft_dlstnew(const void *data, size_t size);
void				ft_dlstadd(t_dlist **alst, t_dlist *new);
int					ft_dlstaddnew(t_dlist **alst, const void *data,
						size_t size);

/*
** circular double linked lists
*/
typedef struct		s_clist
{
	t_dlist			*first;
	t_dlist			*last;
	size_t			size;
}					t_clist;

void				ft_clstclean(t_clist **alst);
t_clist				*ft_clstnew(const void *data, size_t size);
void				ft_clstadd(t_clist **alst, t_clist *new);
int					ft_clstaddnew(t_clist **alst, const void *data,
						size_t size);
t_dlist				*ft_clstpop(t_clist *clst, t_dlist *pop);

/*
** Secure memory handlers
*/
void				*ft_xmalloc(size_t size);
void				ft_xmalloc_error(void);
void				*ft_xmalloc_catch(void *ptr);

/*
** Memory handlers
*/
void				ft_bzero(void *s, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_memdel(void **ap);
void				*ft_calloc(size_t size);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *s1, const void *s2, size_t n);
void				*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void				*ft_memmove(void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memdup(void *data, size_t size);
void				*ft_realloc(void *ptr, size_t old_size, size_t new_size);
void				ft_memrev(void *s, size_t n);

/*
** String manipulation
*/
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *s1, const char *s2);
char				*ft_strncpy(char *s1, const char *s2, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin_va(int ignored, ...);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
size_t				ft_strcount(const char *s, int c);
char				*ft_strltrim(char const *s);
char				*ft_strrtrim(char const *s);
int					ft_indexof(const char *s, char c);
char				*ft_basename(char *path);
char				*ft_dirname(char *path);
char				*ft_pathjoin(char const *s1, char const *s2);

/*
** Datatype converters
*/
unsigned int		ft_abasetoui(const char *str, const char *base);
int					ft_atoi(const char *str);
unsigned int		ft_atoui(const char *str);
int					ft_getnbr(char *str, int *nbr);
char				*ft_itoa(int n);
char				*ft_uitobase(unsigned int n, const char *base);
char				*ft_uitoa(unsigned int n);
char				*ft_ltoa(long n);
char				*ft_ultoa(unsigned long n);
char				*ft_itobase(unsigned int value, int radix);
char				*ft_ltobase(unsigned long value, int radix);

/*
** Char type boolean testers
*/
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_islower(int c);
int					ft_isupper(int c);

/*
** Int Manipulation
*/
int					ft_abs(int i);
int					ft_intcmp(int i1, int i2);
int					ft_intlen(int n);

/*
** Array Manipulation
*/
size_t				ft_strarrlen(const char **array);
void				ft_strarrdel(char ***array_ptr, int size);
char				**ft_strarrdup(char **array, int size);
int					ft_optiter(int argc, char **argv,
		int (*setopt)(char, void *), void *container);

/*
** File I/O & Display functions
*/
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_error_va(int ignored, ...);
int					ft_fmterror(const char *fmt, ...);
int					ft_getline(int const fd, char **line);

/*
** Math
*/
long				ft_powl(long x, long y);

/*
** Unix handlers
*/
const char			*ft_strerror(int errnum);

#endif
