// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   case.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: abanvill <abanvill@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/06/20 19:08:40 by abanvill          #+#    #+#             //
//   Updated: 2014/06/20 19:08:41 by abanvill         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <zproject.h>

void			caseSetGem(int caseX, int caseY, int gem, int set, int number)
{
	t_map			*root;
	t_map			*ref;

	root = setRootMap();
	ref = root;
	while (ref)
	{
		if (ref->x == caseX && ref->y == caseY)
			break;
		else if (ref->next == NULL)
			return ;
		ref = ref->next;
	}
	if (set > 0)
	{
		if (ref->attr->gem[gem] > number && set == REMOVE)
			ref->attr->gem[gem] -= number;
		else if (ref->attr->gem[gem] < number && set == REMOVE)
			ref->attr->gem[gem] = 0;
		else if (set == ADD)
			ref->attr->gem[gem] += number;
		else if (set == SET)
			ref->attr->gem[gem] = number;
	}
}

void			caseSetFood(int caseX, int caseY, int set, int number)
{
	t_map			*root;
	t_map			*ref;

	root = setRootMap();
	ref = root;
	while (ref)
	{
		if (ref->x == caseX && ref->y == caseY)
			break;
		else if (ref->next == NULL)
			return ;
		ref = ref->next;
	}
	if (set > 0)
	{
		if (ref->attr->food > number && set == REMOVE)
			ref->attr->food -= number;
		else if (ref->attr->food < number && set == REMOVE)
			ref->attr->food = 0;
		else if (set == ADD)
			ref->attr->food += number;
		else if (set == SET)
			ref->attr->food = number;
	}
}
