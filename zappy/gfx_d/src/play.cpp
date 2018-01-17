// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   play.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: abanvill <abanvill@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/06/20 19:09:33 by abanvill          #+#    #+#             //
//   Updated: 2014/06/20 19:09:33 by abanvill         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <zproject.h>

void				playMusic(int id)
{
	t_game				*params;

	params = getGameParams();

	if (params && id < MUSICS_NUMBER)
		Mix_PlayMusic(params->musics[id], -1);
}

void				playMute(int coef)
{
	static bool			set = false;

	if (!set)
	{
		set = true;
		Mix_VolumeMusic(0);
	}
	else if (set)
	{
		set = false;
		Mix_VolumeMusic(MIX_MAX_VOLUME / coef);
	}
}