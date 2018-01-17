// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   sets.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: abanvill <abanvill@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/06/20 19:09:46 by abanvill          #+#    #+#             //
//   Updated: 2014/06/20 19:09:47 by abanvill         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <zproject.h>
#include <unistd.h>
#include <stdio.h>

void				setFogMode(void)
{
	t_game				*params;

	params = getGameParams();
	if (params && params->fogMode == false)
		params->fogMode = true;
	else if (params && params->fogMode == true)
		params->fogMode = false;
}

t_game					*setGameParams(SDL_Surface *screen, SDL_Surface ***assets, Mix_Music **musics, int x, int y)
{
	static t_game		*params = NULL;

	if (!params)
	{
		if (!(params = (t_game *)malloc(sizeof(t_game))))
			exitFailure("Allocation error::game parameters\n");
		params->eventRunning = true;
		params->drawRunning = true;
		params->drawInterface = false;
		params->fogMode = false;
		params->textInterface = (t_inter *)malloc(sizeof(t_inter));
		params->textInterface->largeFontSize = LARGE_FONT;
		params->textInterface->mediumFontSize = MEDIUM_FONT;
		params->textInterface->smallFontSize = SMALL_FONT;
		params->xBlocks = x;
		params->yBlocks = y;
		params->mapHoldMatrix[0] = 0;
		params->mapHoldMatrix[1] = 0;
		params->mapClickMatrix[0] = 0;
		params->mapClickMatrix[1] = 0;
		params->mapSkinMatrix = initMapSkinMatrix(x, y);
		params->map = setRootMap();
		params->musics = musics;
		params->assets = assets;
		params->screen = screen;
		params->interfaceSurface = SDL_CreateRGBSurface(SDL_HWSURFACE, (x * BLOCKS_SIZE) / 4, y * BLOCKS_SIZE, 32, 0, 0, 0, 0);
	}
	return (params);
}

t_map				*setRootMap(void)
{
	static t_map		*root;

	if (!root)
	{
		if (!(root = (t_map *)malloc(sizeof(t_map))))
			exitFailure("Allocation error::Map root\n");
		root->x = -1;
		root->y = -1;
		root->attr = NULL;
		root->next = NULL;
	}
	return (root);
}

void				setInterface(void)
{
	t_game				*params;

	params = getGameParams();
	if (!params->drawInterface)
		params->drawInterface = true;
	else
		params->drawInterface = false;
}

void				setCharSpriteDST(t_sprite *sprite)
{
	t_game				*params;

	params = getGameParams();
	if (sprite->dir == DOWN_DIR)
	{
		sprite->dstX += 0;
		sprite->dstY += 32;
	}
	else if (sprite->dir == LEFT_DIR)
	{
		sprite->dstX += -32;
		sprite->dstY += 0;
	}
	else if (sprite->dir == RIGHT_DIR)
	{
		sprite->dstX += 32;
		sprite->dstY += 0;
	}
	else if (sprite->dir == UP_DIR)
	{
		sprite->dstX += 0;
		sprite->dstY += -32;
	}
	if (params && sprite->dstX == params->xBlocks * BLOCKS_SIZE)
		sprite->dstX = 0;
	else if (params && sprite->dstX == 0 - BLOCKS_SIZE)
		sprite->dstX = params->xBlocks * BLOCKS_SIZE - BLOCKS_SIZE;
	if (params && sprite->dstY == params->yBlocks * BLOCKS_SIZE)
		sprite->dstY = 0;
	else if (params && sprite->dstY == 0 - BLOCKS_SIZE)
		sprite->dstY = params->yBlocks * BLOCKS_SIZE - BLOCKS_SIZE;
	return ;
}

int					setSprite(int type, int id, int dir)
{
	static bool			action = false;
	t_sprite			*sprite;

	sprite = linkSpriteByID(type, id);
	if (sprite && sprite->type == type && sprite->id == id)
	{
		if (sprite->dir == dir)
			action = true;
		charTurn(id, dir);
		if (action)
		{
			charMove(id);
			action = false;
		}
		return (1);
	}
	return (0);
}

int					setPushValue(int type, int id)
{
	t_sprite			*sprite;

	sprite = linkSpriteByID(type, id);
	if (sprite && sprite->type == type && sprite->id == id)
	{
		sprite->pushed = true;
		return (1);
	}
	return (0);
}

int					setDirValue(t_sprite *ref)
{
	if (ref->dir == DOWN_DIR)
		return (0);
	if (ref->dir == LEFT_DIR)
		return (32);
	if (ref->dir == RIGHT_DIR)
		return (64);
	if (ref->dir == UP_DIR)
		return (96);
	return (0);
}

void				setAnimLevel(int id)
{
	t_sprite			*sprite;

	sprite = linkSpriteByID(CHARACTERS, id);
	if (sprite && sprite->type == CHARACTERS && sprite->id == id)
		sprite->animLevel = true;
}

int					setAnimValue(t_sprite *ref)
{
	if (ref->pushed == true && ref->animation == 10)
	{
		if (ref->anim >= 64)
			ref->anim = 0;
		else
			ref->anim += 32;
		ref->pushed = false;
		ref->animation = 0;
		return (ref->anim);
	}
	else
		return (ref->anim);
}

void				setGameOff(void)
{
	t_game				*params;

	params = getGameParams();
	params->eventRunning = false;
	return ;
}


void				setMapClickMatrix(void)
{
	t_game				*params;

	params = getGameParams();
	if (params)
	{
		params->mapClickMatrix[0] = params->mapHoldMatrix[0];
		params->mapClickMatrix[1] = params->mapHoldMatrix[1];
	}
	return ;
}

void				setMapHoldMatrix(int x, int y)
{
	t_game				*params;

	params = getGameParams();
	if (x < params->xBlocks * BLOCKS_SIZE && params->yBlocks < y * BLOCKS_SIZE)
	{
		params->mapHoldMatrix[0] = calcCaseX(x);
		params->mapHoldMatrix[1] = calcCaseY(y);
	}
	return ;
}
