# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/03 17:52:28 by bgauci            #+#    #+#              #
#    Updated: 2014/05/11 19:35:13 by fflorens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

INCDIR   = inc
SRCDIR   = src
OBJDIR   = obj

# all flags
FLAGS_INCLUDES = -I$(INCDIR)
CFLAGS = $(FLAGS_ERROR) $(FLAGS_INCLUDES)
LFLAGS = $(CFLAGS)

FLAGS_ERROR = -Wall -Werror -Wextra

SRC =		$(SRCDIR)/philosophe.c	\
			$(SRCDIR)/display.c		\
			$(SRCDIR)/main.c		\
			$(SRCDIR)/debug.c		\
			$(SRCDIR)/init.c		\
			$(SRCDIR)/term.c
OBJ =		$(OBJDIR)/philosophe.o	\
			$(OBJDIR)/main.o		\
			$(OBJDIR)/debug.o		\
			$(OBJDIR)/display.o		\
			$(OBJDIR)/init.o		\
			$(OBJDIR)/term.o

OBJECTS  := $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
CC = /usr/bin/gcc
RMF = rm -rf

all: $(NAME)

$(NAME): $(OBJECTS)
	@makedepend -Y. $(FLAGS_INCLUDES) $(SRC) 2>/dev/null
	@$(RMF) Makefile.bak
	gcc -pthread -o $(NAME) $(OBJ) -ltermcap

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RMF) $(OBJ)
	$(RMF) $(OBJDIR)

fclean: clean
	$(RMF) -r $(NAME).dSYM
	$(RMF) $(NAME)

clear: clean
re: fclean all

depend:
	@makedepend -Y. $(FLAGS_INCLUDES) $(SRC) 2>/dev/null
	@$(RMF) Makefile.bak

.PHONY: gdb depend clear clean fclean re all
# DO NOT DELETE

src/philosophe.o: inc/philosophe.h inc/debug.h
src/display.o: inc/philosophe.h inc/debug.h
src/main.o: inc/philosophe.h inc/debug.h
src/debug.o: inc/debug.h
src/init.o: inc/philosophe.h
src/term.o: inc/debug.h inc/philosophe.h
