# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fflorens <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/12 12:23:32 by fflorens          #+#    #+#              #
#    Updated: 2017/08/09 10:51:42 by fflorens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_nm ft_otool

SRCS_COMMON	=	arch.c				\
				flags.c				\
				swap_nlist.c		\
				swap_util.c			\
				swap_utils.c

SRCS_NM		=	ft_nm.c				\
				nm.c				\
				nm_handle_fat.c		\
				nm_handle_32.c		\
				nm_handle_64.c		\
				nm_handle_ar.c		\
				nm_header.c			\
				nm_print.c			\
				nm_util.c			\
				nm_utils.c

SRCS_OTOOL	=	ft_otool.c			\
				otool.c				\
				otool_handle_fat.c	\
				otool_handle_32.c	\
				otool_handle_64.c	\
				otool_handle_ar.c	\
				otool_hdr.c			\
				otool_util.c		\
				otool_print.c

OBJDIR		=	obj
SRCDIR		=	src
INCDIR		=	include
LIBDIR		=	libft
LIBINCDIR	=	libft
OBJS_COMMON	=	$(patsubst %.c, $(OBJDIR)/%.o, $(SRCS_COMMON))
OBJS_NM		=	$(patsubst %.c, $(OBJDIR)/%.o, $(SRCS_NM))
OBJS_OTOOL	=	$(patsubst %.c, $(OBJDIR)/%.o, $(SRCS_OTOOL))
#CFLAGS		=	-Werror -Wall -Wextra -g -O0
CFLAGS		=	-Wall -Wextra -g -O0
CC			=	gcc
RMF			=	rm -rf
MKD			=	mkdir -p

all: lib $(NAME)

lib:
	make -C $(LIBDIR)

ft_nm: $(OBJS_NM) $(OBJS_COMMON)
	$(CC) -o $@ $(OBJS_COMMON) $(OBJS_NM) -L $(LIBDIR) -lft

ft_otool: $(OBJS_OTOOL) $(OBJS_COMMON)
	$(CC) -o $@ $(OBJS_COMMON) $(OBJS_OTOOL) -L $(LIBDIR) -lft

$(OBJDIR)/%.o: $(addprefix $(SRCDIR)/, %.c)
	@$(MKD) $(OBJDIR)
	$(CC) -c -o $@ $(CFLAGS) -I $(INCDIR)/ -I $(LIBINCDIR) $^

clean:
	make -C $(LIBDIR) $@
	$(RMF) $(OBJDIR)

fclean: clean
	make -C $(LIBDIR) $@
	$(RMF) $(NAME)
	$(RMF) $(ARCH_NAME)

re: fclean all

norme:
	@$(eval FAIL := $(shell norminette $(SRCDIR) $(INCDIR) 2>&1 | grep 'Error\|from' 2>&1  1> /dev/null ; echo $$?))
	@if [ "$(FAIL)" != "0" ] ; then echo 'Norme: Ok' ; else echo 'Norme: Fail' ; fi

check_auteur:
	@bash -c 'diff <(echo "$(USER)") auteur > /dev/null && echo "Auteur: Ok" && exit 0 || echo "Auteur: Fail" && exit 1'

correction: fclean norme check_auteur test

test: all
	@python3 unit_test.py -eR /bin /sbin /usr/sbin /usr/bin /usr/lib custom_tests

check: check_auteur norme test

.PHONY: clean fclean re all norme check_auteur $(NAME)
