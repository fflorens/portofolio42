// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   link.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: abanvill <abanvill@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/06/20 19:09:24 by abanvill          #+#    #+#             //
//   Updated: 2014/06/20 19:09:24 by abanvill         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <zproject.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

t_size				*linkWorldSize(int x, int y)
{
	static t_size		*size = NULL;

	if (!size && x != 0 && y != 0)
	{
		if (!(size = (t_size *)malloc(sizeof(t_size))))
			exitFailure("Allocation error::world size\n");
		size->x = x;
		size->y = y;
	}
	return (size);
}

t_net				*linkNetwork(t_net *net)
{
	static t_net		*root = NULL;

	if (!root)
	{
		if (!(root = (t_net *)malloc(sizeof(t_net))))
			exitFailure("Allocation error::network\n");
		root->addr = net->addr;
		root->port = net->port;
		free(net);
	}
	return (root);
}

t_sprite				*linkSpriteByID(int type, int id)
{
	t_sprite			*ref;
	t_sprite			*root;

	root = linkRootSprite();
	ref = root;
	while (ref && (ref->type != type || ref->id != id))
		ref = ref->next;
	return (ref);
}

t_sprite				*linkCharSprite(SDL_Surface **bitmap, int id)
{
	t_sprite				*newSprite;

	if (!(newSprite = (t_sprite *)malloc(sizeof(t_sprite))))
		exitFailure("Allocation error::sprite child struct\n");
	newSprite->id = id;
	newSprite->srcX = 0;
	newSprite->srcY = 0;
	newSprite->dstX = 0;
	newSprite->dstY = 0;
	newSprite->sprw = 32;
	newSprite->sprh = 32;
	newSprite->anim = 0;
	newSprite->food = 0;
	newSprite->animLevel = false;
	newSprite->level = 1;
	newSprite->dir = DOWN_DIR;
	newSprite->type = CHARACTERS;
	newSprite->animation = 0;
	newSprite->alive = false;
	newSprite->pushed = false;
	newSprite->bitmap = bitmap;
	newSprite->next = NULL;
	for (int i = 0; i < GEMS_NUMBER; i++)
		newSprite->gem[i] = 0;
	linkLastSprite()->next = newSprite;
	return (newSprite);
}

t_sprite			*linkLastSprite(void)
{
	t_sprite			*root;
	t_sprite			*ref;

	root = linkRootSprite();
	ref = root;
	while (ref->next)
		ref = ref->next;
	return (ref);
}

t_sprite			*linkRootSprite(void)
{
	static t_sprite		*root = NULL;

	if (!root)
	{
		if (!(root = (t_sprite *)malloc(sizeof(t_sprite))))
			exitFailure("Allocation error::sprite root struct\n");
		root->id = 0;
		root->srcX = 0;
		root->srcY = 0;
		root->dstX = 0;
		root->dstY = 0;
		root->sprw = 0;
		root->sprh = 0;
		root->type = EMPTY;
		root->bitmap = NULL;
		root->next = NULL;
	}
	return (root);
}
