#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/08 06:21:12 by fflorens          #+#    #+#              #
#    Updated: 2014/02/23 06:02:51 by fflorens         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC		=	gcc
CFLAGS  =	-Wall -Werror -Wextra -pedantic -ansi -g
NAME   	=	lem-in
PROJ    =	lem-in
INCDIR	=	includes
SRCDIR  =	srcs
OBJDIR  =	objs
SRC		=	algo.c			\
			cleanup.c		\
			error.c			\
			ft_gnl.c		\
			list.c			\
			main.c			\
			move.c			\
			new.c			\
			parsing.c		\
			search.c		\
			str.c			\
			utils.c

OBJ	 	=	$(patsubst %.c, $(OBJDIR)/%.o, $(SRC))

.PHONY: all clean fclean re

all : $(LIB) $(NAME)

$(NAME) : $(OBJ)
	@echo "[$(PROJ)]: Assembling $(NAME)"
	@$(CC) $(OBJ) -o $(NAME) $(CFLAGS)
	@echo "[$(PROJ)]: Done !"

$(OBJDIR)/%.o : $(addprefix $(SRCDIR)/, %.c)
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -o $@ -c $^ -I $(INCDIR)

clean :
	@echo "[$(PROJ)]: Deleting objects"
	@rm -rf $(OBJ)
	@rm -rf $(OBJDIR)
	@echo "[$(PROJ)]: Done !"

fclean : clean
	@echo "[$(PROJ)]: Deleting $(NAME)"
	@rm -f $(NAME)
	@echo "[$(PROJ)]: Done !"

re : fclean all
