// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   draw.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: abanvill <abanvill@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/06/20 19:09:00 by abanvill          #+#    #+#             //
/*   Updated: 2014/06/26 22:26:26 by bgauci           ###   ########.fr       */
//                                                                            //
// ************************************************************************** //
#include <zproject.h>
#include <SDL/SDL.h>
#include <unistd.h>
#include <write.h>
#include <time.h>
#include <SDL/SDL_mixer.h>

#include <iostream>
#include <sstream>

void				drawSnapshot(void)
{
	static time_t		i = 0;
	time_t				t;

	time(&t);
	if (i < t)
	{
		i = t;
		snapshot();
	}
}

void				drawLoop(void)
{
	t_game				*params;
	t_sprite			*sprite;

	sprite = linkRootSprite();
	params = getGameParams();
	usleep(WAIT_DRAW);
	if (params)
	{
		SDL_FillRect(params->screen, NULL, SDL_MapRGB(params->screen->format, 0, 0, 0));
		if (params->xBlocks && params->yBlocks)
		{
			drawStaticMap(params->xBlocks, params->yBlocks);
			drawStaticGemScene(params->screen);
			drawStaticFoodScene(params->screen);
			drawStaticCharScene(params->screen);
			drawDynamicMap();
			for (int i = 0; sprite; i++)
			{
				if (sprite->type == CHARACTERS && sprite->animLevel == true && sprite->alive == true)
					drawDynamicSkill(sprite, sprite->dstX, sprite->dstY - 1);
				sprite = sprite->next;
			}
		}
		drawBottomInterface();
		drawDynamicInterface();
		SDL_Flip(params->screen);
		drawSnapshot();
	}
}

void				drawDynamicMap(void)
{
	t_sprite			*ref;
	t_sprite			*root;
	t_game				*params;
	SDL_Surface			*block;

	params = getGameParams();
	root = linkRootSprite();
	ref = root;
	block = SDL_CreateRGBSurface(0, 32, 32, 32, 0, 0, 0, 0);
	if (ref && params && params->fogMode && block)
	{
		for (int i = 0; i < params->xBlocks; i++)
		{
			for (int j = 0; j < params->yBlocks; j++)
			{
				drawBlackBlock(params->screen, block, i, j);
				if (params->mapClickMatrix[0] != -1 && params->mapClickMatrix[1] != -1)
					drawStaticBlock(params->screen, params->assets[GROUNDS_HOLD][1], params->mapClickMatrix[0], params->mapClickMatrix[1]);
				if (i == params->mapHoldMatrix[0] && j == params->mapHoldMatrix[1])
					drawStaticBlock(params->screen, params->assets[GROUNDS_HOLD][0], i, j);
			}
		}
		SDL_FreeSurface(block);
	}
}

void				drawBlackBlock(SDL_Surface *screen, SDL_Surface *bitmap, int x, int y)
{
	SDL_Rect			srcRect;
	SDL_Rect			dstRect;

	// Part of the bitmap that we want to draw
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = BLOCKS_SIZE - GRID_SIZE;
	srcRect.h = BLOCKS_SIZE - GRID_SIZE;

	// Part of the screen we want to draw the sprite to
	dstRect.x = x * BLOCKS_SIZE;
	dstRect.y = y * BLOCKS_SIZE;
	dstRect.w = BLOCKS_SIZE - GRID_SIZE;
	dstRect.h = BLOCKS_SIZE - GRID_SIZE;

	if (!calcCharVision(x, y))
		SDL_BlitSurface(bitmap, &srcRect, screen, &dstRect);
}

void				drawStaticText(SDL_Surface *text, int x, int y)
{
	SDL_Rect 			txtRect;
	t_game				*params;

	params = getGameParams();
	if (params)
	{
		txtRect.x = x;
		txtRect.y = y;
		SDL_BlitSurface(text, NULL, params->screen, &txtRect);
		SDL_FreeSurface(text);
	}
	return ;

}


void				drawDynamicSkill(t_sprite *sprite, int x, int y)
{
	static bool			status = false;
	static int			value = 0;
	SDL_Rect			srcRect;
	SDL_Rect			dstRect;
	t_game				*params;

	params = getGameParams();
	if (!params)
		return ;
	if (sprite)
		status = true;
	if (status)
	{
		srcRect.x = 0;
		srcRect.y = 0;
		srcRect.w = BLOCKS_SIZE;
		srcRect.h = BLOCKS_SIZE;

		dstRect.x = calcCaseX(x) * BLOCKS_SIZE;
		dstRect.y = calcCaseY(y) * BLOCKS_SIZE;
		dstRect.w = BLOCKS_SIZE;
		dstRect.h = BLOCKS_SIZE;
		if (params->assets[SKILLS][value])
		{
			SDL_SetColorKey(params->assets[SKILLS][value], SDL_SRCCOLORKEY, SDL_MapRGB(params->assets[SKILLS][value]->format, 255, 0, 255));
			SDL_BlitSurface(params->assets[SKILLS][value], &srcRect, params->screen, &dstRect);
		}
		if (value == SKILLS_SPRITE_NUMBER)
		{
			status = false;
			value = 0;
			sprite->animLevel = false;
		}
		else
			value++;
	}
}


void				drawBottomInterface(void)
{
	int					block;
	int					xColumn;
	int					yColumn;
	t_game				*params;
	t_sprite			*root;
	t_sprite			*ref;
	std::string			newString;
	std::stringstream	charID;
	std::stringstream	gemNumber;

	root = linkRootSprite();
	ref = root;
	params = getGameParams();
	block = BLOCKS_SIZE;
	xColumn = (params->xBlocks + 1) * BLOCKS_SIZE;
	yColumn = (params->yBlocks + 1) * BLOCKS_SIZE;
	if (params)
	{
		while (ref)
		{
			if (ref && ref->alive == true && ref->type == CHARACTERS
				&& calcCaseX(ref->dstX) == params->mapClickMatrix[0]
				&& calcCaseY(ref->dstY) == params->mapClickMatrix[1])
			{
				charID << ref->id;
				newString = "Character [" + charID.str() + "]";
				drawStaticText(initText(newString, params->textInterface->largeFontSize, 255, 255, 255), block , yColumn);
				charID.str("");
				charID << ref->level;
				newString = "Level: " + charID.str(); 
				drawStaticText(initText("Blood", params->textInterface->mediumFontSize, 255, 255, 255), block, yColumn + block / 2);
				drawStaticBlock(params->screen, ref->bitmap[ref->level - 1], 1, params->yBlocks + 3);
				drawStaticText(initText("HP: __/MAX_HP", params->textInterface->mediumFontSize, 255, 255, 255), block, yColumn + block * 5 + block / 2);
				drawStaticText(initText(newString, params->textInterface->mediumFontSize, 255, 255, 255), block, yColumn + block * 4);
				charID.str("");
				for (int i = 0; i < GEMS_NUMBER; i++)
				{
					gemNumber << getCharGemNumber(ref->id, i);
					newString = "x " + gemNumber.str();
					drawStaticBlock(params->screen, params->assets[GEMS][i], 4 + i, params->yBlocks + 3);
					drawStaticText(initText(newString.c_str(), params->textInterface->mediumFontSize, 255, 255, 255), block * (i + 4), yColumn + block * 3);
					gemNumber.str("");
				}
				gemNumber << getCharFoodNumber(ref->id);
				newString = "x " + gemNumber.str();
				drawStaticBlock(params->screen, params->assets[FOODS][0], 4 + GEMS_NUMBER, params->yBlocks + 3);
				drawStaticText(initText(newString.c_str(), params->textInterface->mediumFontSize, 255, 255, 255), block * (GEMS_NUMBER + 4), yColumn + block * 3);
				gemNumber.str("");
			}
			ref = ref->next;
		}

	}
	return ;
}

void				drawDynamicInterface(void)
{
	int					block;
	int					xColumn;
	int					yColumn;
	std::stringstream	xPos;
	std::stringstream	yPos;
	std::stringstream	gemNumber;
	std::string			gemString;
	std::string			position;
	std::string			loading;
	t_game				*params;

	params = getGameParams();
	block = BLOCKS_SIZE;
	xColumn = (params->xBlocks + 1) * BLOCKS_SIZE;
	yColumn = (params->yBlocks + 1) * BLOCKS_SIZE;
	if (params && params->drawInterface)
	{
		xPos << params->mapHoldMatrix[0];
		yPos << params->mapHoldMatrix[1];
		position = "Case Cursor [" + xPos.str() + "][" + yPos.str() + "]";
		drawStaticInterface();
		drawStaticText(initText("Caracteristics", params->textInterface->largeFontSize, 255, 255, 255), xColumn , block / 2);
		drawStaticText(initText(position.c_str(), params->textInterface->mediumFontSize, 255, 255, 255), xColumn, block + block / 2);
		xPos.str("");
		yPos.str("");
		position.clear();
		xPos << params->mapClickMatrix[0];
		yPos << params->mapClickMatrix[1];
		position = "Case Click  [" + xPos.str() + "][" + yPos.str() + "]";
		drawStaticText(initText(position.c_str(), params->textInterface->mediumFontSize, 255, 255, 255), xColumn, block * 2);
		for (int i = 0; i < GEMS_NUMBER; i++)
		{
			gemNumber << getCaseClickGemNumber(i);
			gemString = "x " + gemNumber.str();
			drawStaticBlock(params->screen, params->assets[GEMS][i], params->xBlocks + 1, 3 + i);
			drawStaticText(initText(gemString.c_str(), params->textInterface->mediumFontSize, 255, 255, 255), (params->xBlocks + 2) * BLOCKS_SIZE, BLOCKS_SIZE * 3 + i * BLOCKS_SIZE + 10);
			gemNumber.str("");
		}
		gemNumber << getCaseClickFoodNumber();
		gemString = "x " + gemNumber.str();
		drawStaticBlock(params->screen, params->assets[FOODS][0], params->xBlocks + 1, 3 + GEMS_NUMBER);
		drawStaticText(initText(gemString.c_str(), params->textInterface->mediumFontSize, 255, 255, 255), (params->xBlocks + 2) * BLOCKS_SIZE, BLOCKS_SIZE * 3 + GEMS_NUMBER * BLOCKS_SIZE + 10);
		gemNumber.str("");
	}
	else
	{
		drawStaticText(initText("[Tab]", params->textInterface->mediumFontSize, 255, 255, 255), xColumn , block / 2);
		drawStaticText(initText("Show Interface", params->textInterface->mediumFontSize, 255, 255, 255), xColumn , block);
		drawStaticText(initText("[Space]", params->textInterface->mediumFontSize, 255, 255, 255), xColumn , block * 2);
		drawStaticText(initText("Ultra Vision Mode", params->textInterface->mediumFontSize, 255, 255, 255), xColumn , block * 2 + block / 2);
		drawStaticText(initText("[M]", params->textInterface->mediumFontSize, 255, 255, 255), xColumn , block * 3 + block / 2 );
		drawStaticText(initText("Mute Music", params->textInterface->mediumFontSize, 255, 255, 255), xColumn , block * 3 + block);
		drawStaticText(initText("[Escape]", params->textInterface->mediumFontSize, 255, 255, 255), xColumn , block * 4 + block);
		drawStaticText(initText("Quit", params->textInterface->mediumFontSize, 255, 255, 255), xColumn , block * 5 + block / 2);

	}
	return ;
}

void				drawStaticInterface(void)
{
	int 				side;
	SDL_Rect			srcRect;
	SDL_Rect			dstRect;
	t_game				*params;

	side = 0;
	params = getGameParams();
	if (params)
	{
		// Part of the bitmap that we want to draw
		srcRect.x = 0;
		srcRect.y = 0;
		srcRect.w = (params->xBlocks * BLOCKS_SIZE) / 4;
		srcRect.h = params->yBlocks * BLOCKS_SIZE;

		// Part of the screen we want to draw the sprite to
		dstRect.x = params->xBlocks * BLOCKS_SIZE;
		dstRect.y = 0;
		dstRect.w = (params->xBlocks * BLOCKS_SIZE) / 4;
		dstRect.h = params->yBlocks;

		SDL_BlitSurface(params->interfaceSurface, &srcRect, params->screen, &dstRect);
	}
}

void				drawStaticMap(int x, int y)
{
	t_game				*params;

	params = getGameParams();
	if (params)
	{
		for (int i = 0; i < x; i++)
			for (int j = 0; j < y; j++)
			{
				drawStaticBlock(params->screen, params->assets[GROUNDS][params->mapSkinMatrix[i][j]], i, j);
				if (params->mapClickMatrix[0] != -1 && params->mapClickMatrix[1] != -1)
					drawStaticBlock(params->screen, params->assets[GROUNDS_HOLD][1], params->mapClickMatrix[0], params->mapClickMatrix[1]);
				if (i == params->mapHoldMatrix[0] && j == params->mapHoldMatrix[1])
					drawStaticBlock(params->screen, params->assets[GROUNDS_HOLD][0], i, j);
			}
	}
}

void				drawStaticBlock(SDL_Surface *screen, SDL_Surface *bitmap, int x, int y)
{
	SDL_Rect			srcRect;
	SDL_Rect			dstRect;

	// Part of the bitmap that we want to draw
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = BLOCKS_SIZE - GRID_SIZE;
	srcRect.h = BLOCKS_SIZE - GRID_SIZE;

	// Part of the screen we want to draw the sprite to
	dstRect.x = x * BLOCKS_SIZE;
	dstRect.y = y * BLOCKS_SIZE;
	dstRect.w = BLOCKS_SIZE - GRID_SIZE;
	dstRect.h = BLOCKS_SIZE - GRID_SIZE;

	if (bitmap)
	{
		SDL_SetColorKey(bitmap, SDL_SRCCOLORKEY, SDL_MapRGB(bitmap->format, 255, 0, 255));
		SDL_BlitSurface(bitmap, &srcRect, screen, &dstRect);
	}
}

void				drawStaticCharScene(SDL_Surface *screen)
{
	int					dir, anim;
	t_sprite			*ref;
	t_sprite			*root;
	SDL_Rect			srcRect;
	SDL_Rect			dstRect;

	root = linkRootSprite();
	ref = root;
	while (ref)
	{
		if (ref->type == CHARACTERS && ref->alive == true)
		{

			ref->pushed = true;
			ref->animation++;
			dir = setDirValue(ref);
			anim = setAnimValue(ref);

			srcRect.x = ref->srcX + anim;
			srcRect.y = ref->srcY + dir;
			srcRect.w = ref->sprw;
			srcRect.h = ref->sprh;

			dstRect.x = ref->dstX;
			dstRect.y = ref->dstY;
			dstRect.w = ref->sprw;
			dstRect.h = ref->sprh;

			if (ref->bitmap[ref->level - 1])
			{
				SDL_SetColorKey(ref->bitmap[ref->level - 1], SDL_SRCCOLORKEY, SDL_MapRGB(ref->bitmap[ref->level - 1]->format, 255, 0, 255));
				SDL_BlitSurface(ref->bitmap[ref->level - 1], &srcRect, screen, &dstRect);
			}
		}
		ref = ref->next;
	}
}

void				drawStaticGemScene(SDL_Surface *screen)
{
	int					gemNumber;
	t_game				*params;
	t_map				*ref;
	t_map				*root;
	SDL_Rect			srcRect;
	SDL_Rect			dstRect;

	root = setRootMap();
	ref = root;
	params = getGameParams();
	if (!params)
		return ;
	gemNumber = 0;
	while (ref)
	{
		for (int i = 0; i < GEMS_NUMBER; i++)
		{
			if (ref->attr && ref->attr->gem[i] >= 1)
			{
				if (ref->attr->set[i] == false)
				{
					ref->attr->gemDst[i][0] = rand() % 20;
					ref->attr->gemDst[i][1] = rand() % 20;
					ref->attr->set[i] = true;
				}
				srcRect.x = 10;
				srcRect.y = 10;
				srcRect.w = 8;
				srcRect.h = 8;

				dstRect.x = ref->x * BLOCKS_SIZE + ref->attr->gemDst[i][0];
				dstRect.y = ref->y * BLOCKS_SIZE + ref->attr->gemDst[i][1];
				dstRect.w = 8;
				dstRect.h = 8;

				if (params->assets[GEMS][i])
				{
					SDL_SetColorKey(params->assets[GEMS][i], SDL_SRCCOLORKEY, SDL_MapRGB(params->assets[GEMS][i]->format, 255, 0, 255));
					SDL_BlitSurface(params->assets[GEMS][i], &srcRect, screen, &dstRect);
				}
			}
		}
		ref = ref->next;
	}
}

void				drawStaticFoodScene(SDL_Surface *screen)
{
	static int			x = 0;
	static int			y = 0;
	t_game				*params;
	t_map				*ref;
	t_map				*root;
	SDL_Rect			srcRect;
	SDL_Rect			dstRect;

	root = setRootMap();
	ref = root;
	params = getGameParams();
	if (!params)
		return ;
	while (ref)
	{
		if (ref->attr && ref->attr->food >= 1)
		{
			if (ref->attr->set[GEMS_NUMBER + 1] == false)
			{
				x = rand() % 20;
				y = rand() % 20;
				ref->attr->set[GEMS_NUMBER + 1] = true;
			}
			srcRect.x = 6;
			srcRect.y = 6;
			srcRect.w = 12;
			srcRect.h = 12;

			dstRect.x = ref->x * BLOCKS_SIZE + x;
			dstRect.y = ref->y * BLOCKS_SIZE + y;
			dstRect.w = 12;
			dstRect.h = 12;

			if (params->assets[FOODS][0])
			{
				SDL_SetColorKey(params->assets[FOODS][0], SDL_SRCCOLORKEY, SDL_MapRGB(params->assets[FOODS][0]->format, 255, 0, 255));
				SDL_BlitSurface(params->assets[FOODS][0], &srcRect, screen, &dstRect);
			}
		}
		ref = ref->next;
	}
}
