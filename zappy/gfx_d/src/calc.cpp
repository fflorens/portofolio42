// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   calc.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: abanvill <abanvill@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/06/20 19:08:47 by abanvill          #+#    #+#             //
/*   Updated: 2014/06/26 17:55:00 by bgauci           ###   ########.fr       */
//                                                                            //
// ************************************************************************** //
#include <zproject.h>
#include <stdio.h>

int					calcMapBorderX(int x)
{
	return (x);
}

int					calcMapBorderY(int y)
{
	return (y);
}

int					calcCaseX(int x)
{
	return (x / BLOCKS_SIZE); 
}

int					calcCaseY(int y)
{
	return (y / BLOCKS_SIZE); 
}

int					calcCharVision(int x, int y)
{
	t_sprite			*ref;
	t_sprite			*root;
	t_game				*params;
	int					lvl;

	params = getGameParams();
	root = linkRootSprite();
	ref = root;
	if (!params)
		return (0);
	while (ref)
	{
		lvl = ref->level + 1;
		if (ref && ref->dir == DOWN_DIR)
		{
			if (lvl > 0 && lvl < 9)
			{
				for (int i = 0; i < lvl; i++)
				{
					if (x >= calcCaseX(ref->dstX) - i && x <= calcCaseX(ref->dstX) + i && y == calcCaseY(ref->dstY) + i)
						return (1);
					if (calcCaseY(ref->dstY) + i >= params->yBlocks && x >= calcCaseX(ref->dstX) - i && x <= calcCaseX(ref->dstX) + i && y == (i - (params->yBlocks - calcCaseY(ref->dstY))))
						return (1);
				}
			}
		}
		else if (ref && ref->dir == LEFT_DIR)
		{
			if (lvl > 0 && lvl < 9)
			{
				for (int i = 0; i < lvl; i++)
				{
					if (y >= calcCaseY(ref->dstY) - i && y <= calcCaseY(ref->dstY) + i && x == calcCaseX(ref->dstX) - i)
						return (1);
					if (calcCaseX(ref->dstX) - i < 0 && y >= calcCaseY(ref->dstY) - i && y <= calcCaseY(ref->dstY) + i && x == (params->xBlocks - i))
						return (1);
				}
			}
		}
		else if (ref && ref->dir == RIGHT_DIR)
		{
			if (lvl > 0 && lvl < 9)
			{
				for (int i = 0; i < lvl; i++)
				{
					if (y >= calcCaseY(ref->dstY) - i && y <= calcCaseY(ref->dstY) + i && x == calcCaseX(ref->dstX) + i)
						return (1);
					if (calcCaseX(ref->dstX) + i >= params->xBlocks && y >= calcCaseY(ref->dstY) - i && y <= calcCaseY(ref->dstY) + i && x == (i - (params->xBlocks - calcCaseX(ref->dstX))))
						return (1);
				}
			}
		}
		else if (ref && ref->dir == UP_DIR)
		{
			if (lvl > 0 && lvl < 9)
			{
				for (int i = 0; i < lvl; i++)
				{
					if (x >= calcCaseX(ref->dstX) - i && x <= calcCaseX(ref->dstX) + i && y == calcCaseY(ref->dstY) - i)
						return (1);
					if (calcCaseY(ref->dstY) - i < 0 && x >= calcCaseX(ref->dstX) - i && x <= calcCaseX(ref->dstX) + i && y == (params->yBlocks - i))
						return (1);
				}
			}
		}
		ref = ref->next;
	}
	return (0);
}

