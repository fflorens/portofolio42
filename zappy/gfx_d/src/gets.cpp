// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   gets.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: abanvill <abanvill@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/06/20 19:09:16 by abanvill          #+#    #+#             //
//   Updated: 2014/06/20 19:09:16 by abanvill         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <zproject.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

t_game				*getGameParams(void)
{
	return (setGameParams(NULL, NULL, NULL, 0, 0));
}

int					getCaseClickFoodNumber(void)
{
	int					j;
	t_map				*root;
	t_map				*ref;
	t_game				*params;

	j = 0;
	root = setRootMap();
	if (root)
	{
		ref = root;
		params = getGameParams();
		if (params)
		{
			while (ref)
			{
				if (ref->x == params->mapClickMatrix[0] && ref->y == params->mapClickMatrix[1])
				{
					if (ref->attr && ref->attr->food > 0)
						return (ref->attr->food);
				}
				ref = ref->next;
			}
		}
	}
	return (0);
}

int					getCaseClickGemNumber(int gem)
{
	int					j;
	t_map				*root;
	t_map				*ref;
	t_game				*params;

	j = 0;
	root = setRootMap();
	if (root)
	{
		ref = root;
		params = getGameParams();
		if (params)
		{
			while (ref)
			{
				if (ref->x == params->mapClickMatrix[0] && ref->y == params->mapClickMatrix[1])
				{
					if (ref->attr && ref->attr->gem[gem] > 0)
						return (ref->attr->gem[gem]);
				}
				ref = ref->next;
			}
		}
	}
	return (0);
}

int					getCharFoodNumber(int id)
{
	t_sprite			*root;

	root = linkSpriteByID(CHARACTERS, id);
	if (root)
		return (root->food);
	return (0);
}

int					getCharGemNumber(int id, int gem)
{
	t_sprite			*root;

	root = linkSpriteByID(CHARACTERS, id);
	if (root)
		return (root->gem[gem]);
	return (0);
}
