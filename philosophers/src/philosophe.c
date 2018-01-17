/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/05 18:36:06 by bgauci            #+#    #+#             */
/*   Updated: 2014/05/11 23:10:16 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philosophe.h"
#include	"debug.h"
#include	<errno.h>
#include	<pthread.h>
#include	<unistd.h>
#include	<stdlib.h>

extern int	g_forcequit;

static int	lock_stick(t_philo *this, int need_to_eat)
{
	int nb_stick;

	nb_stick = 0;
	if (pthread_mutex_trylock(&(this->stick[RIGHT]->mutex)) == 0)
	{
		this->stick[RIGHT]->phid = this->id;
		nb_stick++;
	}
	if (!need_to_eat && nb_stick)
		return (nb_stick);
	if (pthread_mutex_trylock(&(this->stick[LEFT]->mutex)) == 0)
	{
		this->stick[LEFT]->phid = this->id;
		nb_stick++;
	}
	return (nb_stick);
}

void		eat(t_philo *this)
{
	this->stat = EATING;
	usleep(EAT_T * MUL_SECOND);
	this->stick[RIGHT]->phid = -1;
	pthread_mutex_unlock(&(this->stick[RIGHT]->mutex));
	this->stick[LEFT]->phid = -1;
	pthread_mutex_unlock(&(this->stick[LEFT]->mutex));
	this->pv = MAX_LIFE;
}

void		think(t_philo *this)
{
	this->stat = THINKING;
	if (this->stick[RIGHT]->phid == this->id)
		pthread_mutex_unlock(&(this->stick[RIGHT]->mutex));
	if (this->stick[LEFT]->phid == this->id)
		pthread_mutex_unlock(&(this->stick[LEFT]->mutex));
	usleep(THINK_T * MUL_SECOND);
}

void		rest(t_philo *this)
{
	this->stat = NOTHING;
	usleep(THINK_T * MUL_SECOND);
}

void		*phil(void *data)
{
	t_philo *this;
	int		nb_stick;
	int		need_to_eat;

	this = (t_philo*)data;
	while (!g_forcequit)
	{
		need_to_eat = ((this->pv < MAX_LIFE * 3 / 4 + 1) ? 1 : 0);
		nb_stick = lock_stick(this, need_to_eat);
		if (nb_stick == 2)
			eat(this);
		else if (nb_stick == 1)
			think(this);
		else
			rest(this);
	}
	return (NULL);
}
