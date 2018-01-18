# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fflorens <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/12 12:23:32 by fflorens          #+#    #+#              #
#    Updated: 2018/01/10 16:21:59 by fflorens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	Sully Grace Colleen

SRCS_SULLY		=	Sully.c
SRCS_COLLEEN	=	Colleen.c
SRCS_GRACE		=	Grace.c

OBJDIR			=   obj
SRCDIR			=	src
CFLAGS			=	-Werror -Wall -Wextra
CC				=	clang
RMF				=	rm -rf
MKD				=	mkdir -p

all: $(NAME)

Sully:
	$(CC) -o $@ $(SRCDIR)/$(SRCS_SULLY)

Colleen:
	$(CC) -o $@ $(SRCDIR)/$(SRCS_COLLEEN)

Grace:
	$(CC) -o $@ $(SRCDIR)/$(SRCS_GRACE)


clean:
	@true

fclean: clean
	$(RMF) $(NAME)
	$(RMF) Sully_? Sully_?.c Grace_kid.c


re: fclean all

check_auteur:
	@bash -c 'diff <(echo "$(USER)") auteur > /dev/null && echo "Auteur: Ok" && exit 0 || echo "Auteur: Fail" && exit 1'

correction: fclean check_auteur test

test: all
	@echo "Test Colleen"
	@bash -c 'diff <(./Colleen) src/Colleen.c' && echo Ok || echo Fail
	@echo "Test Grace"
	@./Grace
	@diff src/Grace.c Grace_kid.c && echo Ok || echo Fail
	@echo "Test Sully"
	@./Sully
	diff src/Sully.c Sully_5.c || True
	@test `diff src/Sully.c Sully_5.c| wc -l | tr -d ' '` -eq 4 && echo Ok || echo Fail
	diff src/Sully.c Sully_4.c || True
	@test `diff src/Sully.c Sully_4.c| wc -l | tr -d ' '` -eq 4 && echo Ok || echo Fail
	diff src/Sully.c Sully_3.c || True
	@test `diff src/Sully.c Sully_3.c| wc -l | tr -d ' '` -eq 4 && echo Ok || echo Fail
	diff src/Sully.c Sully_2.c || True
	@test `diff src/Sully.c Sully_2.c| wc -l | tr -d ' '` -eq 4 && echo Ok || echo Fail
	diff src/Sully.c Sully_1.c || True
	@test `diff src/Sully.c Sully_1.c| wc -l | tr -d ' '` -eq 4 && echo Ok || echo Fail
	diff src/Sully.c Sully_0.c || True
	@test `diff src/Sully.c Sully_0.c| wc -l | tr -d ' '` -eq 4 && echo Ok || echo Fail

check: check_auteur norme test

bonus:
	@bash -c 'cd Bonus && ./test'
	$(RMF) Bonus/Sully_?.py Bonus/Grace_kid.py

.PHONY: clean fclean re all norme check_auteur $(NAME) bonus
