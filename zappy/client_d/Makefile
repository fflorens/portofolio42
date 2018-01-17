# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/03 17:52:28 by bgauci            #+#    #+#              #
#    Updated: 2014/06/27 11:20:23 by bgauci           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = client

CC = /usr/bin/clang
export CC
RMF = rm -rf

all: $(NAME)

$(NAME):
	ln -s ia.rb $(NAME)

manuel:
	ln -s interative_clientelle.rb $(NAME)

clean:
	echo "prout"

fclean: clean
	$(RMF) $(NAME)

clear: clean
re: fclean all

.PHONY: clear clean fclean re all
