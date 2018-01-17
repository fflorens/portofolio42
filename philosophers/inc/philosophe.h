/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophe.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/05 18:30:46 by bgauci            #+#    #+#             */
/*   Updated: 2014/05/11 23:21:04 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHE_H
# define PHILOSOPHE_H

# include <pthread.h>

# define MAX_LIFE	20
# define EAT_T		3
# define REST_T		3
# define THINK_T	4
# define TIMEOUT_T	100
# define THRESHOLD	((EAT_T + REST_T) * 3)
# define MUL_SECOND	1000000
# define NB_PHIL	7
# define TRUE		1
# define FALSE		0
# define BOOL		char
# define RIGHT		0
# define LEFT		1
# define CURR_PV	table->philotab[i].pv
# define CURR_STAT	table->philotab[i].stat

typedef enum		e_status
{
	EATING,
	NOTHING,
	THINKING,
	DEAD
}					t_status;

typedef struct		s_condi
{
	char	c;
	int		stick;
	int		philo;
}					t_condi;

typedef struct		s_stick
{
	pthread_mutex_t	mutex;
	int				phid;
}					t_stick;

typedef struct		s_philo
{
	int				id;
	int				pv;
	enum e_status	stat;
	t_stick			*stick[2];
	pthread_t		self;
}					t_philo;

typedef struct		s_table
{
	t_philo			philotab[NB_PHIL];
	t_stick			sticktab[NB_PHIL];
	int				turn;
}					t_table;

int					display(t_philo *ptab, t_stick *stab, int nb);
void				*phil(void *data);
int					init(t_table **table_ptr);
int					set_term(void);
void				restore_term(void);
void				ft_clear_display(void);
t_table				*get_table(void);
extern int			g_forcequit;
#endif
