/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/31 18:29:04 by dbenoit           #+#    #+#             */
/*   Updated: 2014/06/25 17:02:20 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "zappy.h"
# include "structs.h"
# include "libft.h"
# include "reseau.h"

typedef int	(*t_chk)(int clientid, char *params);

t_map		g_map;
t_player	*g_players;
t_req		*g_requests;
t_team		*g_teams;
t_egg		*g_eggs;

int			init_map(void);

int			imin(int a, int b);
int			imax(int a, int b);
int			ft_strxcat(char **str, char *add);

double		get_turn_time_left(int reset);
t_tval		*generate_timeval(double waittime);
int			process_first_request2(t_req *req);
int			process_first_request(void);
int			process_actions_requests(void);
int			delete_first_request(void);
int			process_actions_requests(void);
int			verify_player_actions(void);
int			generate_ressources(int pattern, int turn);
int			process_new_turn(int *turn);

t_player	*get_player_by_id(int clientid);
int			players_new_turn(int turn);
int			player_has_action_by_id(int clientid);
int			player_clear_action_by_id(int clientid);
int			player_clear_action(t_player *player);
int			execute_player_action(t_player *player);
int			set_player_action(int clientid, int cmd, char *params);
int			player_delete_by_id(int clientid);

t_team		*get_team_by_name(char *name);
int			team_get_num_players(t_team *team);

int			chk_has_action(t_player *player);
int			check_actions(void);
int			turn_loop(void);

t_req		*request_new(int clientid, enum e_cmd cmd, char *params);
void		request_add(t_req **list, t_req *item);
void		request_delete(t_req **list, t_req *item);

t_player	*player_new(int clientid, char *name);
void		player_add(t_player **list, t_player *item);
void		player_delete(t_player **list, t_player *item);

t_team		*team_new(int maxplayers, char *name);
void		team_add(t_team **list, t_team *item);
void		team_delete(t_team **list, t_team *item);

t_egg		*egg_new(int x, int y, t_team *team, int type);
void		egg_add(t_egg **list, t_egg *item);
void		egg_delete(t_egg **list, t_egg *item);

int			egg_random(int num, t_team *team);
int			degen_eggs(void);
int			get_available_eggs(t_team *team);
t_egg		*get_first_egg(t_team *team);

int			usage(char *c);

int			check_team_victory(t_team *team);

int			connect_new_player(int clientid, t_team *team);
int			exec_connect(int clientid, char *params);
int			exec_avance(int clientid, char *params);
int			exec_gauche(int clientid, char *params);
int			exec_droite(int clientid, char *params);
void		exec_voir_players(t_player *player, char **str, int x, int y);
void		exec_voir_res(char **str, int x, int y);
void		exec_voir_row(t_player *player, char **str, int row);
int			exec_voir(int clientid, char *params);
void		exec_inv2(t_player *player, char **str);
int			exec_inv(int clientid, char *params);
int			exec_prend(int clientid, char *params);
int			exec_pose(int clientid, char *params);
int			get_num_by_angle(t_player *player, int angle);
int			exec_expulse2(t_player *pl);
int			exec_expulse(int clientid, char *params);
int			get_br_angle(int destx, int desty, int srcx, int srcy);
int			get_br_num(t_player *dest, t_player *src);
int			exec_broadcast(int clientid, char *params);
int			check_start_inc(t_player *pl);
int			set_start_inc(t_player *pl);
int			exec_start_inc(int clientid, char *params);
int			exec_inc(int clientid, char *params);

void		export_map_player_infos(char **str, t_player *player);
void		export_map_players(char **str);
void		export_map_cases(char **str);
char		*export_map(void);

#endif
