// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   debug.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: abanvill <abanvill@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/06/20 19:08:54 by abanvill          #+#    #+#             //
//   Updated: 2014/06/20 19:08:54 by abanvill         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <zproject.h>
#include <stdio.h>

#include <string>
#include <iostream>

void					showSpriteList(void)
{
	t_sprite			*root;
	t_sprite			*ref;

	root = linkRootSprite();
	ref = root;
	while (ref)
	{
		printf("Pushed = %d - ", (int)ref->pushed);
		printf("ID = %d - Type = %d\n", ref->id, ref->type);
		printf("DSTX = %d, DSTY = %d\n", ref->dstX, ref->dstY);
		ref = ref->next;
	}
	return ;
}

void					exitFailure(std::string error)
{
	fprintf(stderr, "%s\n", error.c_str());
	exit(EXIT_FAILURE);
}
