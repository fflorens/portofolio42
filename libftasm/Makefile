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
NAME = libfts.a

OBJ =	ft_bzero.o		\
		ft_cat.o		\
		ft_isalnum.o	\
		ft_isalpha.o	\
		ft_isascii.o	\
		ft_isdigit.o	\
		ft_islower.o	\
		ft_isprint.o	\
		ft_isupper.o	\
		ft_memcpy.o		\
		ft_memset.o		\
		ft_puts.o		\
		ft_strcat.o		\
		ft_strdup.o		\
		ft_strlen.o		\
		ft_tolower.o	\
		ft_toupper.o

RMF := rm -rf
NASM := nasm
ASMFLAGS := -f macho64

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	$(RMF) $(OBJ)

%.o: %.s
		$(NASM) $(ASMFLAGS) $< -o $@

fclean: clean
	$(RMF) $(NAME)

re: fclean all

.PHONY: clean fclean re all



