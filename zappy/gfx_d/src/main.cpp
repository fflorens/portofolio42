// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: abanvill <abanvill@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/06/20 19:09:30 by abanvill          #+#    #+#             //
//   Updated: 2014/06/20 19:09:30 by abanvill         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <zproject.h>
#include <SDL/SDL.h>
#include <SDL/SDL_thread.h>
#include <stdio.h>

#include <iostream>

int					main(int argc, char *argv[])
{
	t_net				*net;

	if (argc != 3)
		displayUsage(argv);
	if (!(net = (t_net *)malloc(sizeof(t_net))))
		exitFailure("Allocation error::network\n");
	net->addr = strdup(argv[1]);
	net->port = atoi(argv[2]);
	printf("Address[%s] | Port[%d]\n", net->addr, net->port);
	if (linkNetwork(net))
		printf("Initialized: Network\n");
	initGlobal();
	return (0);
}

void				displayUsage(char *argv[])
{
	fprintf(stderr, "\n%s", "usage: \n");
	fprintf(stderr, "%s %s", argv[0], "<Address> <Port>\n");
	fprintf(stderr, "%s %s %s", "Example:", argv[0], " 127.0.0.1 4242\n\n");
	exit(EXIT_FAILURE);
}
