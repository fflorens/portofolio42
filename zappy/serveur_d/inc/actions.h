/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 22:39:28 by dbenoit           #+#    #+#             */
/*   Updated: 2014/06/09 22:40:03 by dbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

int		chk_connect(t_req *request);
int		chk_prend(t_req *request);
int		chk_pose(t_req *request);
int		chk_expulse(t_req *request);

int		exec_rien(int clientid, char *params);
int		exec_connect(int clientid, char *params);
int		exec_avance(int clientid, char *params);
int		exec_gauche(int clientid, char *params);
int		exec_droite(int clientid, char *params);
int		exec_voir(int clientid, char *params);
int		exec_inv(int clientid, char *params);
int		exec_prend(int clientid, char *params);
int		exec_pose(int clientid, char *params);
int		exec_expulse(int clientid, char *params);
int		exec_broadcast(int clientid, char *params);
int		exec_start_inc(int clientid, char *params);
int		exec_inc(int clientid, char *params);
int		exec_fork(int clientid, char *params);
int		exec_conbr(int clientid, char *params);

#endif
