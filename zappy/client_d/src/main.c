/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 22:58:03 by bgauci            #+#    #+#             */
/*   Updated: 2014/06/24 18:47:23 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
//#include "struct.h"
#include "libft.h"
#include <stdbool.h>

void	usage(char *str)
{
	printf("Usage: %s <host> <port>\n", str);
	exit(-1);
}

int		create_client(char *addr, int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;

	if ((proto = getprotobyname("tcp")) == 0)
		exit_perror("getprotobyname", -1);
	if ((sock = socket(PF_INET, SOCK_STREAM, proto->p_proto)) < 0)
		exit_perror("socket", -1);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = inet_addr(addr);
	if (connect(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
		exit_perror("connect", -1);
	return (sock);
}

void	boucle(int sock)
{
	int		r;
	char	buff[1024];
	bool	avance;

	while (true)
	{
		r = read(sock, buff, 1024);
		buff[r] = '\0';
		if (strcmp(buff, "dead") == 0)
			exit(1);
		if (avance)
		{
			avance = false;
			write(sock, "prend nouriture\n", 16);
		}
		else
		{
			avance = true;
			write(sock, "avance\n", 7);
		}
	}
}
int		init(char *addr, int port)
{
	int sock;

	sock = create_client(addr, port);
	if (sock < 0)
	{
		printf("connection failure, exiting");
		exit(EXIT_FAILURE);
	}
}
int		main(int ac, char **av)
{
	int		port;
	int		sock;

	if (ac != 3)
		usage(av[0]);
	port = atoi(av[2]);
	sock = create_client(av[1], port);
	if (sock < 0)
	{
		printf("erreur de connection\n");
		exit(EXIT_FAILURE);
	}
	boucle(sock);
	close(sock);
	return (EXIT_SUCESS);
}
