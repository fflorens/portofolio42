/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 18:11:14 by fflorens          #+#    #+#             */
/*   Updated: 2014/06/25 18:42:11 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		CLIENT_H
# define	CLIENT_H

typedef struct			s_params
{
	char				*addr;
	char				*port;
	char				*team;
}						t_params;
typedef struct			s_shared_data
{
	pthread_mutex_t		mutex;
	char				*recieved;
	int					nb_connect;
}						t_shared_data;
#endif
