/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 21:06:34 by bgauci            #+#    #+#             */
/*   Updated: 2014/06/26 21:09:39 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# define DEFAULT_PORT		4242
# define DEFAULT_LARGEUR	30
# define DEFAULT_HAUTEUR	30
# define DEFAULT_TEMPO		2
# define DEFAULT_NB_CLIENT	5

int		init_port(int ac, char **av);
int		init_largeur(int ac, char **av);
int		init_hauteur(int ac, char **av);
int		init_tempo(int ac, char **av);
int		init_nb_client(int ac, char **av);

#endif
