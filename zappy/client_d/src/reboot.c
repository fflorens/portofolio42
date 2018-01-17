/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reboot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 13:16:39 by fflorens          #+#    #+#             */
/*   Updated: 2014/06/25 18:30:33 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	"interface.h"
#include	"client.h"
#define		SLAVE		0
#define		MASTER		1

void		exec_ia(int status)
{
	char		*recieved;
	static int	layed = 0;
	static int	people = 0;

	if (!layed)
	{
		ft_fork();
		layed = !layed;
	}
	prendre("nourriture");
	if (status == MASTER)
	{
		if (people < 6)
		{
			broadcast_send("#TOTO COME HERE ME BEAUTY");
			broadcast_recieve(&recieved);
			if (recieved && !strcmp(recieved, "#TOTO I arrived"))
				people++;
		}
		else
			incantation();
	}
	else
	{
		broadcast_recieve(&recieved);
		if (recieved && !strcmp("#TOTO COME HERE ME BEAUTY", recieved))
		{
			people = *(recieved + 8);
			if (people == 0)
				broadcast_send("#TOTO I arrived");
			else if (people == 1 || people == 2 || people == 8)
				avance();
			else if (people > 5)
				droite();
			else
				gauche();
			recieved = NULL;
		}
	}
}
static t_params	*checkoptions(char **av, int ac)
{
	static t_params	out;

	if (ac < 5 || (ac & 1) == 0)
		return (NULL);
	if (strcmp(av[1], "-n") || strcmp(av[3], "-p"))
		return (NULL);
	if (ac == 7 && strcmp(av[5], "-h"))
		return (NULL);
	out.addr = (ac == 7 ? av[6] : "127.0.0.1");
	out.port = atoi(av[4]);
	out.team = av[2];
	return (&out);
}

int main(int ac, char **av)
{
	int			pid;
	int			status;
	t_params	*params;
	pthread_t	*network_t;

	if ((params = checkoptions(av, av)) == NULL)
		return (usage(av[0]));
	if (pthread_create(network_t, NULL, network, (void *)params) != 0)
		return (EXIT_FAILURE);

	while (1)
	{
		if (connect_nb())
		{
			if ((pid = fork()) == -1)
				return (printf("fork error, exiting"));
			if (!pid)
				status = SLAVE;
			else
				status = MASTER;
		}
		exec_ia(status);
	}
}

