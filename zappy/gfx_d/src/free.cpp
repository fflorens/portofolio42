// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   free.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: abanvill <abanvill@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/06/20 19:09:05 by abanvill          #+#    #+#             //
//   Updated: 2014/06/20 19:09:06 by abanvill         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <zproject.h>
#include <SDL/SDL.h>

void				freeAllAssets(void)
{
	t_game				*params;

	params = getGameParams();
	if (params)
	{
		for (int i = 0; i < GROUNDS_HOLD_NUMBER; i++)
			SDL_FreeSurface(params->assets[GROUNDS_HOLD][i]);
		for (int i = 0; i < GROUNDS_NUMBER; i++)
			SDL_FreeSurface(params->assets[GROUNDS][i]);
		for (int i = 0; i < CHARACTERS_NUMBER; i++)
			SDL_FreeSurface(params->assets[CHARACTERS][i]);
		for (int i = 0; i < GEMS_SPRITE_NUMBER; i++)
			SDL_FreeSurface(params->assets[GEMS][i]);
	}
}
