#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/17 14:45:02 by fflorens          #+#    #+#              #
#    Updated: 2013/12/22 18:49:25 by fflorens         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=		fdf
SRCS=		fdf.c			\
			gnl.c			\
			ft_open.c		\
			show_me.c		\
			lstp.c			\
			hook.c			\
			ft_strcat.c		\
			ft_strncpy.c	\
			ft_bzero.c		\
			ft_strchr.c		\
			ft_strdup.c		\
			ft_memalloc.c	\
			ft_strjoin.c	\
			ft_strnew.c		\
			ft_strsub.c		\
			basic.c

OBJS=		$(SRCS:.c=.o)

CFLAGS=		-Wall -Wextra -Werror -g

CC=			/usr/bin/gcc

RM=			/bin/rm -f

LIB=		-lmlx -lXext -lX11 -L/usr/X11/lib

$(NAME):	$(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(LIB) -g

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all re clean fclean
