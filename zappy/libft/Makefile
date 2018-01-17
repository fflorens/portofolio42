# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 11:59:50 by bgauci            #+#    #+#              #
#    Updated: 2014/05/23 16:45:30 by bgauci           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
OBJ =	ft_atoi.o		ft_isalpha.o	ft_isprint.o		ft_memccpy.o	\
		ft_memcpy.o		ft_memset.o		ft_putendl.o		ft_putnbr_fd.o	\
		ft_strcat.o		ft_strcmp.o		ft_strdup.o			ft_striteri.o	\
		ft_strlen.o		ft_strncat.o	ft_strnequ.o		ft_strrchr.o	\
		ft_strsub.o		ft_toupper.o	ft_bzero.o			ft_isascii.o	\
		ft_itoa.o		ft_memchr.o		ft_memdel.o			ft_putchar.o	\
		ft_putendl_fd.o	ft_putstr.o		ft_strchr.o			ft_strcpy.o		\
		ft_strequ.o		ft_strjoin.o	ft_strmap.o			ft_strncmp.o	\
		ft_strnew.o		ft_strsplit.o	ft_strtrim.o		ft_isalnum.o	\
		ft_isdigit.o	ft_memalloc.o	ft_memcmp.o			ft_memmove.o	\
		ft_putchar_fd.o	ft_putnbr.o		ft_putstr_fd.o		ft_strclr.o		\
		ft_strdel.o		ft_striter.o	ft_strlcat.o		ft_strmapi.o	\
		ft_strncpy.o	ft_strnstr.o	ft_strstr.o			ft_tolower.o	\
		ft_strfastcat.o	ft_strfastdup.o	ft_strfastjoin.o	ft_strfastnew.o	\
		ft_lstnew.o		ft_lstdelone.o	ft_lstdel.o			ft_lstadd.o		\
		ft_lstaddend.o	ft_lstiter.o	ft_lstmap.o			ft_strreverse.o	\
		ft_strlstnew.o	ft_strlstadd.o	ft_strlstaddend.o	ft_strlstdel.o	\
		ft_strlstiter.o	ft_strlstmap.o	ft_strlstdelone.o	ft_pgcd.o		\
		ft_strjcat.o	ft_lstswap.o	ft_strfastsub.o		ft_strhach.o	\
		tree_avl.o		tree_avl2.o		ft_truncate.o		get_next_line.o	\
		tree_avl3.o		tree_avl4.o		ft_intlstadd.o		ft_intlstnew.o	\
		ft_intlstiter.o	ft_intlstmap.o	ft_intlstaddend.o	ft_intlstdelone.o \
		ft_intlstdel.o	ft_strnjoin.o	ft_strnjcat.o		ft_perror.o
FLAGS = -Wall -Werror -Wextra
CC = /usr/bin/gcc
RMF = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	@makedepend -Y. *.c 2>/dev/null
	$(RMF) Makefile.bak
	ar rcs $(NAME) $(OBJ)
	ranlib $(NAME)
clear: clean
clean:
	$(RMF) $(OBJ)
%.o: %.c
		$(CC) -o $@ -c $< $(FLAGS) $(FLAG_GDB)
fclean: clean
	$(RMF) $(NAME)
re: fclean all
depend:
	makedepend -Y. *.c
.PHONY: all re clean fclean depend
# DO NOT DELETE

ft_atoi.o: libft.h struct_libft.h tree_avl.h
ft_bzero.o: libft.h struct_libft.h tree_avl.h
ft_intlstadd.o: libft.h struct_libft.h tree_avl.h
ft_intlstaddend.o: libft.h struct_libft.h tree_avl.h
ft_intlstdel.o: libft.h struct_libft.h tree_avl.h
ft_intlstdelone.o: libft.h struct_libft.h tree_avl.h
ft_intlstiter.o: libft.h struct_libft.h tree_avl.h
ft_intlstmap.o: libft.h struct_libft.h tree_avl.h
ft_intlstnew.o: libft.h struct_libft.h tree_avl.h
ft_isalnum.o: libft.h struct_libft.h tree_avl.h
ft_itoa.o: libft.h struct_libft.h tree_avl.h
ft_lstadd.o: libft.h struct_libft.h tree_avl.h
ft_lstaddend.o: libft.h struct_libft.h tree_avl.h
ft_lstdel.o: libft.h struct_libft.h tree_avl.h
ft_lstdelone.o: libft.h struct_libft.h tree_avl.h
ft_lstiter.o: libft.h struct_libft.h tree_avl.h
ft_lstmap.o: libft.h struct_libft.h tree_avl.h
ft_lstnew.o: libft.h struct_libft.h tree_avl.h
ft_lstswap.o: libft.h struct_libft.h tree_avl.h
ft_memalloc.o: libft.h struct_libft.h tree_avl.h
ft_memccpy.o: libft.h struct_libft.h tree_avl.h
ft_memchr.o: libft.h struct_libft.h tree_avl.h
ft_memcmp.o: libft.h struct_libft.h tree_avl.h
ft_memcpy.o: libft.h struct_libft.h tree_avl.h
ft_memdel.o: libft.h struct_libft.h tree_avl.h
ft_memmove.o: libft.h struct_libft.h tree_avl.h
ft_memset.o: libft.h struct_libft.h tree_avl.h
ft_perror.o: libft.h struct_libft.h tree_avl.h
ft_putendl.o: libft.h struct_libft.h tree_avl.h
ft_putendl_fd.o: libft.h struct_libft.h tree_avl.h
ft_putnbr.o: libft.h struct_libft.h tree_avl.h
ft_putnbr_fd.o: libft.h struct_libft.h tree_avl.h
ft_putstr.o: libft.h struct_libft.h tree_avl.h
ft_putstr_fd.o: libft.h struct_libft.h tree_avl.h
ft_strcat.o: libft.h struct_libft.h tree_avl.h
ft_strchr.o: libft.h struct_libft.h tree_avl.h
ft_strclr.o: libft.h struct_libft.h tree_avl.h
ft_strcmp.o: libft.h struct_libft.h tree_avl.h
ft_strcpy.o: libft.h struct_libft.h tree_avl.h
ft_strdel.o: libft.h struct_libft.h tree_avl.h
ft_strdup.o: libft.h struct_libft.h tree_avl.h
ft_strequ.o: libft.h struct_libft.h tree_avl.h
ft_strfastcat.o: libft.h struct_libft.h tree_avl.h
ft_strfastdup.o: libft.h struct_libft.h tree_avl.h
ft_strfastjoin.o: libft.h struct_libft.h tree_avl.h
ft_strfastnew.o: libft.h struct_libft.h tree_avl.h
ft_strfastsub.o: libft.h struct_libft.h tree_avl.h
ft_strhach.o: libft.h struct_libft.h tree_avl.h ft_strhach.h
ft_striter.o: libft.h struct_libft.h tree_avl.h
ft_striteri.o: libft.h struct_libft.h tree_avl.h
ft_strjcat.o: libft.h struct_libft.h tree_avl.h
ft_strjoin.o: libft.h struct_libft.h tree_avl.h
ft_strlcat.o: libft.h struct_libft.h tree_avl.h
ft_strlen.o: libft.h struct_libft.h tree_avl.h
ft_strlstadd.o: libft.h struct_libft.h tree_avl.h
ft_strlstaddend.o: libft.h struct_libft.h tree_avl.h
ft_strlstdel.o: libft.h struct_libft.h tree_avl.h
ft_strlstdelone.o: libft.h struct_libft.h tree_avl.h
ft_strlstiter.o: libft.h struct_libft.h tree_avl.h
ft_strlstmap.o: libft.h struct_libft.h tree_avl.h
ft_strlstnew.o: libft.h struct_libft.h tree_avl.h
ft_strmap.o: libft.h struct_libft.h tree_avl.h
ft_strmapi.o: libft.h struct_libft.h tree_avl.h
ft_strncat.o: libft.h struct_libft.h tree_avl.h
ft_strncmp.o: libft.h struct_libft.h tree_avl.h
ft_strncpy.o: libft.h struct_libft.h tree_avl.h
ft_strnequ.o: libft.h struct_libft.h tree_avl.h
ft_strnew.o: libft.h struct_libft.h tree_avl.h
ft_strnjcat.o: libft.h struct_libft.h tree_avl.h
ft_strnjoin.o: libft.h struct_libft.h tree_avl.h
ft_strnstr.o: libft.h struct_libft.h tree_avl.h
ft_strrchr.o: libft.h struct_libft.h tree_avl.h
ft_strreverse.o: libft.h struct_libft.h tree_avl.h
ft_strsplit.o: libft.h struct_libft.h tree_avl.h
ft_strstr.o: libft.h struct_libft.h tree_avl.h
ft_strsub.o: libft.h struct_libft.h tree_avl.h
ft_strtrim.o: libft.h struct_libft.h tree_avl.h
ft_truncate.o: libft.h struct_libft.h tree_avl.h
get_next_line.o: get_next_line.h libft.h struct_libft.h tree_avl.h
tree_avl.o: tree_avl.h libft.h struct_libft.h
tree_avl2.o: tree_avl.h libft.h struct_libft.h
tree_avl3.o: tree_avl.h libft.h struct_libft.h
tree_avl4.o: tree_avl.h libft.h struct_libft.h
