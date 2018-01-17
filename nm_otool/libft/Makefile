#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 12:05:30 by fflorens          #+#    #+#              #
#    Updated: 2013/11/29 11:26:53 by fflorens         ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME = libft.a

OBJ =	ft_bzero.o		ft_memccpy.o	ft_memchr.o		ft_memcmp.o		\
		ft_memcpy.o 	ft_memmove.o 	ft_memset.o		ft_putnbr.o		\
		ft_strcat.o		ft_strcpy.o 	ft_strdup.o 	ft_strlen.o		\
	 	ft_strncat.o	ft_strncpy.o	ft_strchr.o		ft_strrchr.o	\
		ft_strcmp.o		ft_strncmp.o	ft_strnstr.o	ft_strstr.o		\
		ft_memalloc.o	ft_strnew.o		ft_putchar_fd.o	ft_putstr_fd.o	\
		ft_putendl_fd.o	ft_putnbr_fd.o	ft_putchar.o	ft_putstr.o		\
		ft_isalpha.o	ft_isdigit.o	ft_islower.o	ft_isupper.o	\
		ft_isalnum.o	ft_isascii.o	ft_isprint.o	ft_toupper.o	\
		ft_tolower.o	ft_atoi.o		ft_memdel.o		ft_strlcat.o	\
		ft_strdel.o		ft_strclr.o		ft_striteri.o	ft_striter.o	\
		ft_strmapi.o	ft_strmap.o		ft_strequ.o		ft_strnequ.o	\
		ft_strsub.o		ft_strjoin.o	ft_itoa.o		ft_strtrim.o	\
		ft_strsplit.o 	ft_putendl.o	ft_lstnew.o		ft_lstdelone.o	\
		ft_lstdel.o		ft_lstadd.o		ft_lstiter.o	ft_lstmap.o		\
		ft_lstd_new.o	ft_lstd_addb.o	ft_lstd_addf.o	ft_error.o		\
		ft_swap.o

FLAGS = -Wall -Werror -Wextra -O3 -I./  -fno-builtin -g
CC = /usr/bin/gcc
RMF = /bin/rm -f

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	$(RMF) $(OBJ)

%.o: %.c
		$(CC) -o $@ -c $< $(FLAGS)

fclean: clean
	$(RMF) $(NAME)

re: fclean all

.PHONY: clean fclean re all
