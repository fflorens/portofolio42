#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <zproject.h>
#include "read.h"
#include "write.h"

#include <string>

using namespace std;

#define R	0
#define W	1
#define E	2

char	*g_buff_write;
int		g_sock;

void	exit_perror(const char *txt, int i)
{
	perror(txt);
	exit(i);
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
	static fd_set	fd_read;
	static fd_set	fd_write;
	static fd_set	fd_exep;

	while (true)
	{
		FD_ZERO(&fd_read);
		FD_ZERO(&fd_write);
		FD_ZERO(&fd_exep);
		FD_SET(sock, &fd_read);
		if (g_buff_write != NULL)
			FD_SET(sock, &fd_write);
		select(sock + 1, &fd_read, &fd_write, &fd_exep, NULL);
		if (FD_ISSET(sock, &fd_read))
			read_fd(sock);
		if (FD_ISSET(sock, &fd_write))
			write_fd(sock);
	}
}

void		*network(void *ptr)
{
	int		sock;

	sock = create_client(((t_net *)ptr)->addr, ((t_net *)ptr)->port);
	g_sock = sock;
	if (sock < 0)
	{
		printf ("erreur de connection\n");
		exit(-1);
	}
	write(sock, "IHM\n", 4);
	boucle(sock);
	close(sock);
	return (NULL);
}
