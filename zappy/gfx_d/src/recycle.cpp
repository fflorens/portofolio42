// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   recycle.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: abanvill <abanvill@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/06/20 19:09:43 by abanvill          #+#    #+#             //
//   Updated: 2014/06/20 19:09:43 by abanvill         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
void				drawStartScreen(SDL_Surface *screen, int x, int y)
{
	SDL_Surface			*background;
	SDL_Surface			*text;
	SDL_Surface			*textShadow;
	SDL_Rect			srcRect;
	SDL_Rect			pos;

	background = SDL_LoadBMP("img/screen.bmp");
	text = initText("Press Enter !", 50, 0, 0, 0);
	textShadow = initText("Press Enter !", 50, 255, 255, 255);

	pos.x = 0;
	pos.y = 0;
	srcRect.x = x / 4;
	srcRect.y = y / 4;
	srcRect.w = x;
	srcRect.h = y;
	SDL_BlitSurface(background, &srcRect, screen, &pos);
	pos.x = x  / 2 - text->w / 2;
	pos.y = y / 2;
	SDL_BlitSurface(textShadow, 0, screen, &pos);		
	pos.x = 402 - text->w / 2;
	pos.y = 498;
	SDL_BlitSurface(textShadow, 0, screen, &pos);
	pos.x = 400 - text->w / 2;
	pos.y = 500;
	SDL_BlitSurface(text, 0, screen, &pos);
	SDL_Flip(screen);

	SDL_FreeSurface(background);
}

void				initStartScreen(void)
{
	int					width;
	bool				flag;
	t_game				*params;
	SDL_Surface			*screen;
	SDL_Event			event;

	flag = true;
	params = getGameParams();
	if (params)
	{
		width = params->xBlocks * BLOCKS_SIZE;
		screen = SDL_SetVideoMode(width + width / 4, params->yBlocks * BLOCKS_SIZE, 0, SDL_HWSURFACE | SDL_DOUBLEBUF);
		drawStartScreen(screen, width + width / 4, params->yBlocks * BLOCKS_SIZE);
	}
	playMusic(STARTSCREEN_MUSIC);
	while (flag)
	{
		SDL_WaitEvent(&event);
		if (event.type)
		{
			if (event.type == SDL_QUIT)
				exit(0);
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_ESCAPE)
					exit(0);
				if (event.key.keysym.sym == SDLK_RETURN)
					flag = false;
			}
		}
	}
}
