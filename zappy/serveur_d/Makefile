# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/03 17:52:28 by bgauci            #+#    #+#              #
#    Updated: 2014/06/26 22:07:30 by bgauci           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = serveur

INCDIR	= inc
SRCDIR	= src
OBJDIR	= obj/src

LIBDIR  = ../libft
LIBINC  = $(LIBDIR)

FLAGS_INCLUDES = -I$(INCDIR) -I$(LIBINC)
CFLAGS = $(FLAGS_ERROR) $(FLAGS_INCLUDES) $(FLAG_GDB)
LDFLAGS = -L$(LIBDIR) -lft $(FLAG_GDB)

FLAGS_ERROR = -Wall -Werror -Wextra

SRC_MAIN =	main.c
SRC	=	server.c \
		tools.c \
		listreq.c \
		clock.c \
		actions.c \
		requests.c \
		ressources.c \
		export.c \
		player.c \
		player2.c \
		listplayer.c \
		requestsfunctions.c \
		actionsfunctions.c \
		team.c \
		listteam.c \
		egg.c \
		listegg.c \
		execconnect.c \
		execmoves.c \
		execsee.c \
		execinv.c \
		exectakedrop.c \
		execkick.c \
		execbroadcast.c \
		execchanneling.c \
		\
		reseau.c \
		fn_reseau.c \
		write.c \
		read.c \
		interface_serveur.c \
		interface_serveur2.c \
		lst_connexion.c \
		main2.c

OBJ = $(patsubst %.c, $(OBJDIR)/%.o, $(SRC))
OBJ_MAIN = $(patsubst %.c, $(OBJDIR)/%.o, $(SRC_MAIN))

$(OBJDIR)/%.o: $(addprefix $(SRCDIR)/, %.c)
	@mkdir -p `dirname $@`
	$(CC) $(CFLAGS) -c $< -o $@

CC = /usr/bin/clang
export CC
RMF = rm -rf

all: $(NAME)

lib:
	$(MAKE) -C $(LIBDIR) FLAG_GDB=$(FLAG_GDB)

$(NAME): $(OBJ) $(OBJ_MAIN)
	$(MAKE) lib
	@$(MAKE) depend
	$(CC) -o $(NAME) $(OBJ) $(OBJ_MAIN) $(LDFLAGS)

reseau: $(OBJ)
	$(CC) -c $(SRCDIR)/main_reseau.c -o $(OBJDIR)/main_reseau.o $(CFLAGS)
	$(MAKE) lib
	$(CC) -o $(NAME) $(OBJDIR)/main_reseau.o $(OBJ) $(LDFLAGS)

gdb:
	$(MAKE) re FLAG_GDB=-g

clean:
	$(RMF) $(OBJ)
	$(RMF) $(OBJDIR)

fclean: clean
	$(MAKE) -C $(LIBDIR) $@ FLAG_GDB=$(FLAG_GDB)
	$(RMF) $(NAME)

clear: clean
re: fclean all

depend:
	@makedepend -pobj/ -Y. $(FLAGS_INCLUDES) $(addprefix $(SRCDIR)/, $(SRC)) 2>/dev/null
	@$(RMF) Makefile.bak

.PHONY: depend clear clean fclean re all gdb lib
# DO NOT DELETE

obj/src/server.o: inc/zappy.h inc/server.h inc/structs.h ../libft/libft.h
obj/src/server.o: ../libft/struct_libft.h ../libft/tree_avl.h inc/reseau.h
obj/src/server.o: inc/struct_reseau.h
obj/src/tools.o: inc/zappy.h inc/server.h inc/structs.h ../libft/libft.h
obj/src/tools.o: ../libft/struct_libft.h ../libft/tree_avl.h inc/reseau.h
obj/src/tools.o: inc/struct_reseau.h
obj/src/listreq.o: inc/zappy.h inc/server.h inc/structs.h ../libft/libft.h
obj/src/listreq.o: ../libft/struct_libft.h ../libft/tree_avl.h inc/reseau.h
obj/src/listreq.o: inc/struct_reseau.h
obj/src/clock.o: inc/zappy.h inc/server.h inc/structs.h ../libft/libft.h
obj/src/clock.o: ../libft/struct_libft.h ../libft/tree_avl.h inc/reseau.h
obj/src/clock.o: inc/struct_reseau.h
obj/src/actions.o: inc/zappy.h inc/server.h inc/structs.h ../libft/libft.h
obj/src/actions.o: ../libft/struct_libft.h ../libft/tree_avl.h inc/reseau.h
obj/src/actions.o: inc/struct_reseau.h inc/actions.h
obj/src/requests.o: inc/zappy.h inc/server.h inc/structs.h ../libft/libft.h
obj/src/requests.o: ../libft/struct_libft.h ../libft/tree_avl.h inc/reseau.h
obj/src/requests.o: inc/struct_reseau.h inc/actions.h
obj/src/ressources.o: inc/zappy.h inc/server.h inc/structs.h ../libft/libft.h
obj/src/ressources.o: ../libft/struct_libft.h ../libft/tree_avl.h
obj/src/ressources.o: inc/reseau.h inc/struct_reseau.h
obj/src/export.o: inc/zappy.h inc/server.h inc/structs.h ../libft/libft.h
obj/src/export.o: ../libft/struct_libft.h ../libft/tree_avl.h inc/reseau.h
obj/src/export.o: inc/struct_reseau.h
obj/src/player.o: inc/zappy.h inc/server.h inc/structs.h ../libft/libft.h
obj/src/player.o: ../libft/struct_libft.h ../libft/tree_avl.h inc/reseau.h
obj/src/player.o: inc/struct_reseau.h
obj/src/player2.o: inc/zappy.h inc/server.h inc/structs.h ../libft/libft.h
obj/src/player2.o: ../libft/struct_libft.h ../libft/tree_avl.h inc/reseau.h
obj/src/player2.o: inc/struct_reseau.h
obj/src/listplayer.o: inc/zappy.h inc/server.h inc/structs.h ../libft/libft.h
obj/src/listplayer.o: ../libft/struct_libft.h ../libft/tree_avl.h
obj/src/listplayer.o: inc/reseau.h inc/struct_reseau.h
obj/src/requestsfunctions.o: inc/zappy.h inc/server.h inc/structs.h
obj/src/requestsfunctions.o: ../libft/libft.h ../libft/struct_libft.h
obj/src/requestsfunctions.o: ../libft/tree_avl.h inc/reseau.h
obj/src/requestsfunctions.o: inc/struct_reseau.h
obj/src/actionsfunctions.o: inc/zappy.h inc/server.h inc/structs.h
obj/src/actionsfunctions.o: ../libft/libft.h ../libft/struct_libft.h
obj/src/actionsfunctions.o: ../libft/tree_avl.h inc/reseau.h
obj/src/actionsfunctions.o: inc/struct_reseau.h inc/actions.h
obj/src/team.o: inc/zappy.h inc/server.h inc/structs.h ../libft/libft.h
obj/src/team.o: ../libft/struct_libft.h ../libft/tree_avl.h inc/reseau.h
obj/src/team.o: inc/struct_reseau.h
obj/src/listteam.o: inc/zappy.h inc/server.h inc/structs.h ../libft/libft.h
obj/src/listteam.o: ../libft/struct_libft.h ../libft/tree_avl.h inc/reseau.h
obj/src/listteam.o: inc/struct_reseau.h
obj/src/egg.o: inc/zappy.h inc/server.h inc/structs.h ../libft/libft.h
obj/src/egg.o: ../libft/struct_libft.h ../libft/tree_avl.h inc/reseau.h
obj/src/egg.o: inc/struct_reseau.h
obj/src/listegg.o: inc/zappy.h inc/server.h inc/structs.h ../libft/libft.h
obj/src/listegg.o: ../libft/struct_libft.h ../libft/tree_avl.h inc/reseau.h
obj/src/listegg.o: inc/struct_reseau.h
obj/src/execconnect.o: inc/zappy.h inc/server.h inc/structs.h
obj/src/execconnect.o: ../libft/libft.h ../libft/struct_libft.h
obj/src/execconnect.o: ../libft/tree_avl.h inc/reseau.h inc/struct_reseau.h
obj/src/execconnect.o: inc/actions.h
obj/src/execmoves.o: inc/zappy.h inc/server.h inc/structs.h ../libft/libft.h
obj/src/execmoves.o: ../libft/struct_libft.h ../libft/tree_avl.h inc/reseau.h
obj/src/execmoves.o: inc/struct_reseau.h inc/actions.h
obj/src/execsee.o: inc/zappy.h inc/server.h inc/structs.h ../libft/libft.h
obj/src/execsee.o: ../libft/struct_libft.h ../libft/tree_avl.h inc/reseau.h
obj/src/execsee.o: inc/struct_reseau.h inc/actions.h
obj/src/execinv.o: inc/zappy.h inc/server.h inc/structs.h ../libft/libft.h
obj/src/execinv.o: ../libft/struct_libft.h ../libft/tree_avl.h inc/reseau.h
obj/src/execinv.o: inc/struct_reseau.h inc/actions.h
obj/src/exectakedrop.o: inc/zappy.h inc/server.h inc/structs.h
obj/src/exectakedrop.o: ../libft/libft.h ../libft/struct_libft.h
obj/src/exectakedrop.o: ../libft/tree_avl.h inc/reseau.h inc/struct_reseau.h
obj/src/exectakedrop.o: inc/actions.h
obj/src/execkick.o: inc/zappy.h inc/server.h inc/structs.h ../libft/libft.h
obj/src/execkick.o: ../libft/struct_libft.h ../libft/tree_avl.h inc/reseau.h
obj/src/execkick.o: inc/struct_reseau.h inc/actions.h
obj/src/execbroadcast.o: inc/zappy.h inc/server.h inc/structs.h
obj/src/execbroadcast.o: ../libft/libft.h ../libft/struct_libft.h
obj/src/execbroadcast.o: ../libft/tree_avl.h inc/reseau.h inc/struct_reseau.h
obj/src/execbroadcast.o: inc/actions.h
obj/src/execchanneling.o: inc/zappy.h inc/server.h inc/structs.h
obj/src/execchanneling.o: ../libft/libft.h ../libft/struct_libft.h
obj/src/execchanneling.o: ../libft/tree_avl.h inc/reseau.h
obj/src/execchanneling.o: inc/struct_reseau.h inc/actions.h
obj/src/reseau.o: inc/reseau.h inc/structs.h inc/zappy.h inc/struct_reseau.h
obj/src/reseau.o: inc/server.h ../libft/libft.h ../libft/struct_libft.h
obj/src/reseau.o: ../libft/tree_avl.h
obj/src/fn_reseau.o: inc/structs.h inc/zappy.h inc/reseau.h
obj/src/fn_reseau.o: inc/struct_reseau.h inc/lst_connexion.h inc/write.h
obj/src/fn_reseau.o: inc/read.h ../libft/libft.h ../libft/struct_libft.h
obj/src/fn_reseau.o: ../libft/tree_avl.h inc/server.h
obj/src/write.o: inc/reseau.h inc/structs.h inc/zappy.h inc/struct_reseau.h
obj/src/write.o: inc/write.h ../libft/libft.h ../libft/struct_libft.h
obj/src/write.o: ../libft/tree_avl.h inc/server.h
obj/src/read.o: inc/reseau.h inc/structs.h inc/zappy.h inc/struct_reseau.h
obj/src/read.o: inc/read.h ../libft/libft.h ../libft/struct_libft.h
obj/src/read.o: ../libft/tree_avl.h inc/write.h inc/lst_connexion.h
obj/src/read.o: inc/server.h
obj/src/interface_serveur.o: inc/reseau.h inc/structs.h inc/zappy.h
obj/src/interface_serveur.o: inc/struct_reseau.h inc/write.h ../libft/libft.h
obj/src/interface_serveur.o: ../libft/struct_libft.h ../libft/tree_avl.h
obj/src/interface_serveur.o: inc/server.h
obj/src/interface_serveur2.o: inc/reseau.h inc/structs.h inc/zappy.h
obj/src/interface_serveur2.o: inc/struct_reseau.h inc/write.h
obj/src/interface_serveur2.o: ../libft/libft.h ../libft/struct_libft.h
obj/src/interface_serveur2.o: ../libft/tree_avl.h inc/server.h
obj/src/lst_connexion.o: inc/lst_connexion.h inc/reseau.h inc/structs.h
obj/src/lst_connexion.o: inc/zappy.h inc/struct_reseau.h ../libft/libft.h
obj/src/lst_connexion.o: ../libft/struct_libft.h ../libft/tree_avl.h
obj/src/main2.o: ../libft/libft.h ../libft/struct_libft.h ../libft/tree_avl.h
obj/src/main2.o: inc/structs.h inc/zappy.h inc/server.h inc/reseau.h
obj/src/main2.o: inc/struct_reseau.h inc/main.h
