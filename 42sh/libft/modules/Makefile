# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/28 12:35:43 by nmokrane          #+#    #+#              #
#    Updated: 2014/01/18 16:43:37 by nmokrane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= modules
LIBS		= dynbuf printf xmem sigconf

.PHONY: all clean fclean re $(NAME) $(LIBS)

all: $(LIBS)

$(NAME):
	$(MAKE)

$(LIBS):
	$(MAKE) -C $@ $(MAKECMDGOALS)

clean: $(LIBS)

fclean: $(LIBS)

re: $(LIBS)
