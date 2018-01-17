/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 18:36:30 by bgauci            #+#    #+#             */
/*   Updated: 2014/06/27 06:54:14 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <vector>

#include "string.h"
#include "zproject.h"

using namespace std;

extern pthread_mutex_t mutex_init;

void split(vector<string>& vecteur, string chaine, char separateur)
{
	vecteur.clear();

	string::size_type stTemp = chaine.find(separateur);

	while(stTemp != string::npos)
	{
		vecteur.push_back(chaine.substr(0, stTemp));
		chaine = chaine.substr(stTemp + 1);
		stTemp = chaine.find(separateur);
	}

	vecteur.push_back(chaine);
}

void	ft_cases(string s, int map_x, int map_y)
{
	string s_cases, r, dp = ":";
	int	x = 0, y = 0;

	vector<string>	v;
	split(v, s, ',');
	while (!v.empty())
	{
		s_cases = v.front();
		v.erase(v.begin());
		
		r = strtok(strdup(s_cases.c_str()), dp.c_str());
		caseSetFood(x, y, SET, atoi(r.c_str()));
		r = strtok(NULL, dp.c_str());
		caseSetGem(x, y, LINEMATE, SET, atoi(r.c_str()));
		r = strtok(NULL, dp.c_str());
		caseSetGem(x, y, DERAUMERE, SET, atoi(r.c_str()));
		r = strtok(NULL, dp.c_str());
		caseSetGem(x, y, SIBUR, SET, atoi(r.c_str()));
		r = strtok(NULL, dp.c_str());
		caseSetGem(x, y, MENDIANE, SET, atoi(r.c_str()));
		r = strtok(NULL, dp.c_str());
		caseSetGem(x, y, PHIRAS, SET, atoi(r.c_str()));
		r = strtok(NULL, dp.c_str());
		caseSetGem(x, y, THYSTAME, SET, atoi(r.c_str()));
		x++;
		if (x >= map_x)
		{
			x = 0;
			y++;
			if (y > map_y)
				printf("Size overflow [x:%d,y:%d]\n", x, y);
		}
	}
}

void	ft_player(string s)
{
	string s_player, dp = ":";
	char *rest;
	int	id, x, y, angle, lvl;

	vector<string>	v;
	split(v, s, ',');
	while (!v.empty())
	{
		s_player = v.back();
		v.pop_back();
		
		id = atoi(strtok_r(strdup(s_player.c_str()), ":", &rest));
		x = atoi(strtok_r(NULL, ":", &rest));
		y = atoi(strtok_r(NULL, ":", &rest));
		angle = atoi(strtok_r(NULL, ":", &rest));
		lvl = atoi(strtok_r(NULL, ":", &rest));
		if (angle == 0)
			charSet(id, RIGHT_DIR, x, y);
		else if (angle == 90)
			charSet(id, UP_DIR, x, y);
		else if (angle == 180)
			charSet(id, LEFT_DIR, x, y);
		else
			charSet(id, DOWN_DIR, x, y);
		charSetLevel(id, lvl);
		charSetFood(id, atoi(strtok_r(NULL, ":", &rest)));
		charSetGem(id, LINEMATE, atoi(strtok_r(NULL, ":", &rest)));
		charSetGem(id, DERAUMERE, atoi(strtok_r(NULL, ":", &rest)));
		charSetGem(id, SIBUR, atoi(strtok_r(NULL, ":", &rest)));
		charSetGem(id, MENDIANE, atoi(strtok_r(NULL, ":", &rest)));
		charSetGem(id, PHIRAS, atoi(strtok_r(NULL, ":", &rest)));
		charSetGem(id, THYSTAME, atoi(strtok_r(NULL, ":", &rest)));
	}
}

void	rcp_map(string str)
{
	char	*map, *cases, *player;
	int		x, y;

	map = strtok(strdup(str.c_str()),";");
	cases = strtok(NULL,";");
	player = strtok(NULL,";");

	x = atoi(strtok(map,":"));
	y = atoi(strtok(NULL,":"));
	linkWorldSize(x, y);
	pthread_mutex_lock(&mutex_init);
	ft_cases(cases, x, y);
	charDestroyAll();
	if (player)
		ft_player(player);
	pthread_mutex_unlock(&mutex_init);
}
