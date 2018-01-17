// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   char.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: abanvill <abanvill@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/06/20 19:08:40 by abanvill          #+#    #+#             //
//   Updated: 2014/06/26 14:16:02 by abanvill         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <zproject.h>

int					charTurn(int id, int dir)
{
	t_sprite			*sprite;

	sprite = linkSpriteByID(CHARACTERS, id);
	if (sprite && sprite->type == CHARACTERS && sprite->id == id && sprite->alive)
	{
		sprite->dir = dir;
		return (0);
	}
	return (-1);
}

int					charMove(int id)
{
	t_sprite			*sprite;

	sprite = linkSpriteByID(CHARACTERS, id);
	if (sprite && sprite->type == CHARACTERS && sprite->id == id && sprite->alive)
	{
		setCharSpriteDST(sprite);
		return (0);
	}
	return (-1);
}

void				charDestroyAll(void)
{
	int	i;

	for (i = 0; i < 10000 ; i++)
		charDestroy(i);
}

void				charSet(int id, int dir, int caseX, int caseY)
{
	t_sprite			*sprite;

	sprite = linkSpriteByID(CHARACTERS, id);
	if (sprite && sprite->type == CHARACTERS)
	{
		sprite->dstX = caseX * BLOCKS_SIZE;
		sprite->dstY = caseY * BLOCKS_SIZE;
		sprite->dir = dir;
		sprite->alive = true;
	}
	else
		charInvoke(id, dir, caseX, caseY);
	return ;
}

void				charDisplace(int id, int dir, int caseX, int caseY)
{
	t_sprite			*sprite;

	sprite = linkSpriteByID(CHARACTERS, id);
	if (sprite && sprite->type == CHARACTERS && sprite->id == id && sprite->alive)
	{
		sprite->dstX = caseX * BLOCKS_SIZE;
		sprite->dstY = caseY * BLOCKS_SIZE;
		sprite->dir = dir;
	}
	return ;
}

void				charInvoke(int id, int dir, int caseX, int caseY)
{
	int 				value = 0;
	static int			i = 0;
	SDL_Surface			**tmpTable;
	t_sprite			*sprite;
	t_game				*params;

	tmpTable = NULL;
	params = getGameParams();
	value = i * CHARACTERS_COLORS;
	i = (i < CHARACTERS_NUMBER - 1) ? i + 1 : 0;
	if (params)
	{
		if (!(tmpTable = (SDL_Surface **)malloc(sizeof(SDL_Surface *) * CHARACTERS_COLORS + 1)))
			(void)exitFailure("Memory allocation error::characters table\n");
		for (int j = 0; j < CHARACTERS_COLORS; j++)
			tmpTable[j] = params->assets[CHARACTERS][j + value];
	}
	sprite = linkCharSprite(tmpTable, id);
	if (sprite && sprite->type == CHARACTERS)
	{
		sprite->id = id;
		sprite->dstX = caseX * BLOCKS_SIZE;
		sprite->dstY = caseY * BLOCKS_SIZE;
		sprite->dir = dir;
		sprite->alive = true;
		std::cout << "Linked: Character id[" << sprite->id << "] " << "\n";
	}
	return ;
}

void				charRevoke(int id)
{
	t_sprite			*sprite;

	sprite = linkSpriteByID(CHARACTERS, id);
	if (sprite && sprite->type == CHARACTERS && sprite->id == id && sprite->alive)
		sprite->alive = false;
	return ;
}

void				charResurrect(int id)
{
	t_sprite			*sprite;

	sprite = linkSpriteByID(CHARACTERS, id);
	if (sprite && sprite->type == CHARACTERS && sprite->id == id && !sprite->alive)
		sprite->alive = true;
	return ;
}

void				charDestroy(int id)
{
	t_sprite			*sprite;

	sprite = linkSpriteByID(CHARACTERS, id);
	if (sprite && sprite->type == CHARACTERS && sprite->id == id && sprite->alive)
	{
		sprite->dstX = 0;
		sprite->dstY = 0;
		sprite->dir = DOWN_DIR;
		sprite->alive = false;
	}
	return ;
}

void				charSetLevel(int id, int lvl)
{
	t_sprite			*sprite;

	sprite = linkSpriteByID(CHARACTERS, id);
	if (lvl < 0 || lvl > 8)
		return ;
	if (sprite && sprite->type == CHARACTERS && sprite->id == id && sprite->alive)
		sprite->level = lvl;
	return ;
}

void				charLevel(int id, int set)
{
	t_sprite			*sprite;

	sprite = linkSpriteByID(CHARACTERS, id);
	if (sprite && sprite->type == CHARACTERS && sprite->id == id && sprite->alive)
	{
		if (sprite->level < 8 && set == LEVEL_UP)
		{
			setAnimLevel(id);
			sprite->level += 1;
		}
		if (sprite->level > 1 && set == LEVEL_DOWN)
			sprite->level -= 1;
	}
	return ;
}

void				charTakeGem(int id, int gem, int number)
{
	t_map				*ref;
	t_game				*params;
	t_sprite			*sprite;

	params = getGameParams();
	sprite = linkSpriteByID(CHARACTERS, id);
	if (!params)
		return ;
	if (sprite)
	{
		ref = params->map;
		while (ref && (ref->x != calcCaseX(sprite->dstX) || ref->y != calcCaseY(sprite->dstY)))
			ref = ref->next;
		if (ref && ref->x == calcCaseX(sprite->dstX) && ref->y == calcCaseY(sprite->dstY))
		{
			if (ref->attr && ref->attr->gem[gem] >= number)
			{
				sprite->gem[gem] += number;
				ref->attr->gem[gem] -= number;
			}
			else if (ref->attr->gem[gem] < number && ref->attr->gem[gem] > 0)
			{
				sprite->gem[gem] += ref->attr->gem[gem];
				ref->attr->gem[gem] = 0;
			}
		}
	}
}

void				charPutGem(int id, int gem, int number)
{
	t_map				*ref;
	t_game				*params;
	t_sprite			*sprite;

	params = getGameParams();
	sprite = linkSpriteByID(CHARACTERS, id);
	if (!params)
		return ;
	if (sprite)
	{
		ref = params->map;
		while (ref && (ref->x != calcCaseX(sprite->dstX) || ref->y != calcCaseY(sprite->dstY)))
			ref = ref->next;
		if (ref && ref->x == calcCaseX(sprite->dstX) && ref->y == calcCaseY(sprite->dstY))
		{
			if (sprite->gem[gem] >= number)
			{
				ref->attr->gem[gem] += number;
				sprite->gem[gem] -= number;
			}
			else if (sprite->gem[gem] < number && sprite->gem[gem] > 0)
			{
				ref->attr->gem[gem] += sprite->gem[gem];
				sprite->gem[gem] = 0;
			}
		}
	}
}

void				charSetGem(int id, int gem, int number)
{
	t_sprite			*sprite;

	sprite = linkSpriteByID(CHARACTERS, id);
	if (sprite)
		sprite->gem[gem] = number;
	return ;
}

void				charSetFood(int id, int number)
{
	t_sprite			*sprite;

	sprite = linkSpriteByID(CHARACTERS, id);
	if (sprite)
		sprite->food = number;
	return ;
}
