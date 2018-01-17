# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/28 12:35:43 by nmokrane          #+#    #+#              #
#    Updated: 2014/03/22 17:32:45 by jzak             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= printf
ifndef CC
  CC		= /usr/bin/clang
endif
CFLAGS		= -Wall -Wextra -Werror
LIBROOT		= ../..
LIBFT		= $(LIBROOT)/libft.a
INCDIR		= $(LIBROOT)/includes
SRCDIR		= src
OBJDIR		= obj
SRC			= printf.c printf_core.c printf_format_int.c \
			  printf_type_d.c printf_type_s.c printf_type_x.c

OBJ			= $(patsubst %.c, $(OBJDIR)/%.o, $(SRC))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(LIBFT) $(OBJ)

$(OBJDIR)/%.o: $(addprefix $(SRCDIR)/, %.c)
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	/bin/rm -f $(OBJ)
	@rmdir $(OBJDIR) 2>/dev/null || true

fclean: clean

re: fclean all
