/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 22:58:03 by bgauci            #+#    #+#             */
/*   Updated: 2014/06/25 18:07:57 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "struct.h"
#include "libft.h"
#include <stdbool.h>

#define 	AVANCE			1
#define		DROITE			2
#define		GAUCHE			3
#define		VOIR			4
#define		INVENTAIRE		5
#define		PREND			6
#define		POSE			7
#define		EXPULSE			8
#define		BROADCAST		9
#define		INCANTATION		10
#define		FORK			11
#define		CONNECT_NBR		12
#define		AUTRE			13
#define		SNAPSHOT		14

int	g_sock;

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

void	init(int sock, fd_set *rfd, fd_set *wfd, fd_set *efd)
{
	FD_ZERO(rfd);
	FD_ZERO(wfd);
	FD_ZERO(efd);
	FD_SET(sock, rfd);
	FD_SET(0, rfd);
}

void	affichage()
{
	printf("menus possible :\n");
	printf("\t avance      : 1\n");
	printf("\t droite      : 2\n");
	printf("\t gauche      : 3\n");
	printf("\t voir        : 4\n");
	printf("\t inventaire  : 5\n");
	printf("\t prend       : 6\n");
	printf("\t pose        : 7\n");
	printf("\t expulse     : 8\n");
	printf("\t broadcast   : 9\n");
	printf("\t incantation : 10\n");
	printf("\t fork        : 11\n");
	printf("\t connect_nbr : 12\n");
	printf("\t autre       : 13\n");
	printf("\t snapshot    : 14\n");
}

void	avance(void)
{
	char *txt = "avance\n";
	write(g_sock, txt, strlen(txt));
}

void	droite(void)
{
	char *txt = "droite\n";
	write(g_sock, txt, strlen(txt));
}

void	gauche(void)
{
	char *txt = "gauche\n";
	write(g_sock, txt, strlen(txt));
}

void	voir(void)
{
	char *txt = "voir\n";
	write(g_sock, txt, strlen(txt));
}

void	inventaire(void)
{
	char *txt = "inventaire\n";
	write(g_sock, txt, strlen(txt));
}

void	prend(void)
{
	char	buff[100];
	char	*txt = "prend ";
	int		r;

	r = read(0, &buff, 100);
	write(g_sock, txt, strlen(txt));
	write(g_sock, buff, r);
}

void	pose(void)
{
	char	buff[100];
	char	*txt = "pose ";
	int		r;

	r = read(0, &buff, 100);
	write(g_sock, txt, strlen(txt));
	write(g_sock, buff, r);
}

void	expulse(void)
{
	char *txt = "expulse\n";
	write(g_sock, txt, strlen(txt));
}

void	broadcast(void)
{
	char	buff[100];
	char	*txt = "broadcast ";
	int		r;

	r = read(0, &buff, 100);
	write(g_sock, txt, strlen(txt));
	write(g_sock, buff, r);
}

void	incantation(void)
{
	char *txt = "incantation\n";
	write(g_sock, txt, strlen(txt));
}

void	ft_fork(void)
{
	char *txt = "fork\n";
	write(g_sock, txt, strlen(txt));
}

void	connect_nbr(void)
{
	char *txt = "connectnbr\n";
	write(g_sock, txt, strlen(txt));
}

void	snapshot(void)
{
	char *txt = "snapshot\n";
	write(g_sock, txt, strlen(txt));
}

void	autre(void)
{
	char	buff[100];
	int		r;

	r = read(0, &buff, 100);
	write(g_sock, buff, r);
}

void	boucle(int sock, fd_set *rfd, fd_set *wfd, fd_set *efd)
{
	int		r, i;
	char	buff[1024];

	while (true)
	{
		affichage();
		init(sock, rfd, wfd, efd);
		select(sock + 1, rfd, wfd, efd, NULL);
		if (FD_ISSET(0, rfd))
		{
			r = read(0, buff, 1024);
			buff[r] = '\0';
			i = atoi(buff);
			if (i == AVANCE)
				avance();
			if (i == DROITE)
				droite();
			if (i == GAUCHE)
				gauche();
			if (i == VOIR)
				voir();
			if (i == INVENTAIRE)
				inventaire();
			if (i == PREND)
				prend();
			if (i == POSE)
				pose();
			if (i == EXPULSE)
				expulse();
			if (i == BROADCAST)
				broadcast();
			if (i == INCANTATION)
				incantation();
			if (i == FORK)
				ft_fork();
			if (i == CONNECT_NBR)
				connect_nbr();
			if (i == AUTRE)
				autre();
			if (i == SNAPSHOT)
				snapshot();
		}
		if (FD_ISSET(sock, rfd))
		{
			if ((r = read(sock, buff, 1024)) == -1)
				exit_perror("read", -1);
			write(1, buff, r);
		}
	}
}

int		reseau(void *params)
{
	int		port;
	fd_set	*rfd;
	fd_set	*wfd;
	fd_set	*efd;

	if (ac != 3)
		usage(av[0]);
	port = atoi(av[2]);
	g_sock = create_client(av[1], port);
	signal(SIGPIPE, SIG_IGN);
	rfd = malloc(sizeof(fd_set));
	wfd = malloc(sizeof(fd_set));
	efd = malloc(sizeof(fd_set));
	if (g_sock < 0)
	{
		printf ("erreur de connection\n");
		exit(-1);
	}
	boucle(g_sock, rfd, wfd, efd);
	close(g_sock);
	return (0);
}
