# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 15:32:40 by nmokrane          #+#    #+#              #
#    Updated: 2014/03/22 17:24:17 by fflorens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
ifndef CC
  CC		= /usr/bin/clang
endif
ifeq ($(config), debug)
  CFLAGS	= -g3
else
  CFLAGS	= -Wall -Wextra -Werror
endif
SRCDIR		= src
OBJDIR		= obj
INCDIR		= includes
MODULES		= modules
SRC			= ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
			  ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
			  ft_memcpy.c ft_memmove.c ft_memset.c ft_strcat.c ft_strchr.c \
			  ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strlcat.c ft_strlen.c \
			  ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnstr.c ft_strrchr.c \
			  ft_strstr.c ft_tolower.c ft_toupper.c ft_calloc.c ft_memdel.c \
			  ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
			  ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
			  ft_strjoin_va.c ft_strtrim.c ft_strsplit.c ft_itoa.c \
			  ft_putchar.c ft_uitobase.c ft_abasetoui.c \
			  ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
			  ft_putstr_fd.c ft_putendl_fd.c ft_putendl.c ft_putnbr_fd.c \
			  ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
			  ft_abs.c ft_isupper.c ft_islower.c ft_strcount.c ft_strarrlen.c \
			  ft_memdup.c ft_lstdup.c ft_strarrtolst.c ft_lstaddnew.c \
			  ft_lstaddstr.c ft_basename.c ft_dirname.c ft_lstsort.c \
			  ft_lstdelif.c ft_strrtrim.c ft_strltrim.c ft_realloc.c \
			  ft_lstaddsort.c ft_lstdupone.c ft_intcmp.c ft_lstlen.c \
			  ft_pathjoin.c ft_getnbr.c ft_indexof.c ft_ltoa.c ft_memrev.c \
			  ft_itobase.c ft_ltobase.c ft_uitoa.c ft_ultoa.c ft_intlen.c \
			  ft_xmalloc.c ft_strarrdel.c ft_strarrdup.c \
			  ft_lstnew.c ft_optiter.c ft_lstrev.c ft_error_va.c \
			  ft_fmterror.c ft_getline.c \
			  ft_clstadd.c ft_clstaddnew.c ft_clstnew.c ft_dlstadd.c \
			  ft_dlstaddnew.c ft_dlstnew.c ft_clstclean.c ft_clstpop.c \
			  ft_powl.c ft_atoui.c ft_strerror.c

OBJ			= $(patsubst %.c, $(OBJDIR)/%.o, $(SRC))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	$(MAKE) -C $(MODULES)
	ranlib $(NAME)

$(OBJDIR)/%.o: $(addprefix $(SRCDIR)/, %.c)
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(OPTI) -I$(INCDIR) -c $< -o $@

clean:
	$(MAKE) -C $(MODULES) $@
	/bin/rm -f $(OBJ)
	@rmdir $(OBJDIR) 2>/dev/null || true

fclean: clean
	$(MAKE) -C $(MODULES) $@
	/bin/rm -f $(NAME)

re: fclean all
