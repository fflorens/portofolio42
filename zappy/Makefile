# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/03 17:52:28 by bgauci            #+#    #+#              #
#    Updated: 2014/06/27 11:19:43 by bgauci           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

IHMNAME		= gfx
IANAME		= client
SERVERNAME	= serveur

IHMDIR		= gfx_d
IADIR		= client_d
SERVERDIR	= serveur_d

RMF = rm -f

all: $(IHMNAME) $(IANAME) $(SERVERNAME)

$(IHMNAME):
	@$(MAKE) install -C $(IHMDIR) $@
	@$(MAKE) -C $(IHMDIR) $@
	mv $(IHMDIR)/$(IHMNAME) .

$(IANAME):
	@$(MAKE) -C $(IADIR) $@
	ln $(IADIR)/$(IANAME) client

$(SERVERNAME):
	@$(MAKE) -C $(SERVERDIR) $@
	mv $(SERVERDIR)/$(SERVERNAME) .

clean:
	@$(MAKE) -C $(IHMDIR) $@
	@$(MAKE) -C $(IADIR) $@
	@$(MAKE) -C $(SERVERDIR) $@

fclean: clean
	@$(MAKE) -C $(IHMDIR) $@
	@$(MAKE) -C $(IADIR) $@
	@$(MAKE) -C $(SERVERDIR) $@
	$(RMF) $(IHMNAME)
	$(RMF) $(IANAME)
	$(RMF) $(SERVERNAME)

clear: clean

re: fclean all

.PHONY: clear clean fclean re all
