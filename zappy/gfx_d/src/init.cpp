// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   init.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: abanvill <abanvill@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/06/20 19:09:19 by abanvill          #+#    #+#             //
/*   Updated: 2014/06/26 15:08:50 by bgauci           ###   ########.fr       */
//                                                                            //
// ************************************************************************** //
#include <zproject.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_thread.h>
#include <SDL/SDL_timer.h>
#include <SDL/SDL_mixer.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <reseau.h>
#include <stdio.h>
#include <time.h>

#include <iostream>

pthread_mutex_t mutex_init = PTHREAD_MUTEX_INITIALIZER;

SDL_Surface			*initWin(int width, int height)
{
	int 				rest;
	int 				interface;
	SDL_Surface			*screen;

	rest = 0;
	interface = 200;
	SDL_Init(SDL_INIT_VIDEO);
	if ((height + interface) < 300)
		rest = 300 - (height + interface);
	screen = SDL_SetVideoMode(width + interface, height + interface + rest, 0, SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_WM_SetCaption(TITLE, 0);
	SDL_EnableKeyRepeat(0, 0);
	return (screen);
}

void					initMapCase(int x, int y)
{
	t_map					*ref;
	t_map					*root;
	t_map					*newCase;

	if (!(newCase = (t_map *)malloc(sizeof(t_map))))
		exitFailure("Allocation error::map newcase\n");
	newCase->x = x;
	newCase->y = y;
	newCase->next = NULL;
	if (!(newCase->attr = (t_state *)malloc(sizeof(t_state))))
		exitFailure("Allocation error::map case\n");
	newCase->attr->food = 0;
	for (int i = 0; i < TEAMS; i++)
	{
		for (int j = 0; j < PLAYERS_MAX; j++)
			newCase->attr->players[i][j] = 0;
	}
	for (int i = 0; i < GEMS_NUMBER; i++)
	{
		newCase->attr->gem[i] = 0;
		newCase->attr->set[i] = false;
	}
	newCase->attr->set[GEMS_NUMBER + 1] = false;
	root = setRootMap();
	if (root)
	{
		ref = root;
		while (ref->next)
			ref = ref->next;
		ref->next = newCase;
	}
}

void				initMap(void)
{
	t_game				*params;

	params = getGameParams();
	if (params)
	{
		for (int i = 0; i < params->xBlocks; i++)
			for (int j = 0; j < params->yBlocks; j++)
				initMapCase(i, j);
	}
}

SDL_Surface			*initText(std::string text, int size, int red, int green, int blue)
{
	SDL_Surface			*text_surface;
	TTF_Font			*font;
	SDL_Color			font_color;

	font_color.r = red;
	font_color.g = green;
	font_color.b = blue;
	font_color.unused = 0;
	font = TTF_OpenFont("img/fonts/MOZART_0.ttf", size);
	text_surface = NULL;
	if (font)
	{
		text_surface = TTF_RenderText_Blended(font, text.c_str(), font_color);
		TTF_CloseFont(font);
	}
	return (text_surface);

}

SDL_Surface			**initSkills(int nbr)
{
	SDL_Surface			**table;
	int					i;

	if (!(table = (SDL_Surface **)malloc(sizeof(SDL_Surface *) * nbr + 1)))
		(void)exitFailure("Memory allocation error::skills table\n");
	for (i = 0; i < nbr; i++)
		table[i] = loadSkill(i);
	table[i] = 0;
	return (table);
}


SDL_Surface			**initGems(int nbr)
{
	SDL_Surface			**table;
	int					i;

	if (!(table = (SDL_Surface **)malloc(sizeof(SDL_Surface *) * nbr + 1)))
		(void)exitFailure("Memory allocation error::gems table\n");
	for (i = 0; i < nbr; i++)
		table[i] = loadGem(i);
	table[i] = 0;
	return (table);
}

SDL_Surface			**initFoods(int nbr)
{
	SDL_Surface			**table;
	int					i;

	if (!(table = (SDL_Surface **)malloc(sizeof(SDL_Surface *) * nbr )))
		(void)exitFailure("Memory allocation error::characters table\n");
	for (i = 0; i < nbr; i++)
		table[i] = loadFood(i);
	table[i] = 0;
	return (table);
}

SDL_Surface			**initCharacters(int nbr)
{
	SDL_Surface			**table;
	int					i;

	if (!(table = (SDL_Surface **)malloc(sizeof(SDL_Surface *) * (nbr * CHARACTERS_COLORS))))
		(void)exitFailure("Memory allocation error::characters table\n");
	for (i = 0; i < nbr; i++)
		table[i] = loadCharacter(i);
	table[i] = 0;
	return (table);
}

SDL_Surface			**initGrounds(int nbr)
{
	SDL_Surface			**table;
	int					i;

	if (!(table = (SDL_Surface **)malloc(sizeof(SDL_Surface *) * nbr + 1)))
		exitFailure("Memory allocation error::ground table\n");
	for (i = 0; i < nbr; i++)
		table[i] = loadGround(i);
	table[i] = 0;
	return (table);
}

SDL_Surface			**initGroundsHold(int nbr)
{
	SDL_Surface			**table;
	int					i;

	if (!(table = (SDL_Surface **)malloc(sizeof(SDL_Surface *) * nbr + 1)))
		exitFailure("Memory allocation error::ground table\n");
	for (i = 0; i < nbr; i++)
		table[i] = loadGroundHold(i);
	table[i] = 0;
	return (table);
}

SDL_Surface			***initAssets(void)
{
	SDL_Surface			***assets;
	Mix_Music			**musics;

	if (!(assets = (SDL_Surface ***)malloc(sizeof(SDL_Surface **) * ASSETS_NUMBER)))
		(void)exitFailure("Memory allocation error::assets\n");
	if (!(musics = (Mix_Music **)malloc(sizeof(Mix_Music *) * MUSICS_NUMBER)))
		(void)exitFailure("Memory allocation error::musics\n");
	if (!(assets[GROUNDS_HOLD] = initGroundsHold(GROUNDS_HOLD_NUMBER)))
		(void)exitFailure("Loading error::grounds assets\n");
	if (!(assets[GROUNDS] = initGrounds(GROUNDS_NUMBER)))
		(void)exitFailure("Loading error::grounds assets\n");
	if (!(assets[CHARACTERS] = initCharacters(CHARACTERS_NUMBER * CHARACTERS_COLORS)))
		(void)exitFailure("Loading error::characters assets\n");
	if (!(assets[GEMS] = initGems(GEMS_SPRITE_NUMBER)))
		(void)exitFailure("Loading error::gems assets\n");
	if (!(assets[FOODS] = initFoods(FOODS_NUMBER)))
		(void)exitFailure("Loading error::foods assets\n");
	if (!(assets[SKILLS] = initSkills(SKILLS_SPRITE_NUMBER)))
		(void)exitFailure("Loading error::skills assets\n");
	for (int i = 0; i < MUSICS_NUMBER; i++)
	{
		if (!(musics[i] = loadMusic(i)))
			(void)exitFailure("Loading error::musics assets\n");
	}
	if (!(initGame(assets, musics)))
		(void)exitFailure("Initialization error::game\n");
	assets[EMPTY] = 0;
	return (assets);
}

int					**initMapSkinMatrix(int x, int y)
{
	int					value;
	int					**matrix = NULL;

	if (!matrix)
	{
		if (!(matrix = (int **)malloc(sizeof(int *) * x)))
			exitFailure("Allocation error::matrix **X\n");
		for (int i = 0; i < x; i++)
		{
			if (!(matrix[i] = (int *)malloc(sizeof(int) * y)))
				exitFailure("Allocation error::matrix *Y\n");
		}
		srand(time(NULL));
		value = rand() % GROUNDS_TYPE_NUMBER;
		value = value * 4;
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
				matrix[i][j] = (rand() % 4) + value;
		}
	}
	return (matrix);
}

void				initSound(void)
{
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
	Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
}

void				initNetwork(void)
{
	pthread_t			netThread;

	pthread_create(&netThread, NULL, network, (void *)linkNetwork(NULL));

}

SDL_Surface			*initGame(SDL_Surface ***assets, Mix_Music **musics)
{
	int 				ips;
	int					music;
	t_size				*size;
	t_game				*params;
	SDL_Event			event;
	SDL_Surface			*screen;

	TTF_Init();
	ips = 0;
	srand(time(NULL) * getpid());
	music = rand() % MUSICS_NUMBER;
	pthread_mutex_lock(&mutex_init);
	initNetwork();
	//(void)linkWorldSize(XBLOCKS, YBLOCKS);
	while (!(size = linkWorldSize(0, 0)))
	{
		usleep(25600);
		printf("Uninitialized: World size\n");
	}
	screen = initWin(size->x * BLOCKS_SIZE, size->y * BLOCKS_SIZE);
	(void)setGameParams(screen, assets, musics, size->x, size->y);
	params = getGameParams();
	playMusic(music);
	initMap();
	pthread_mutex_unlock(&mutex_init);
	while (params->eventRunning)
	{
		usleep(WAIT_EVENT);
		if (ips == IPS)
		{
			ips = 0;
			drawLoop();
		}
		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				params->eventRunning = false;
			if (event.type == SDL_KEYDOWN)
				keyDown((int)event.key.keysym.sym);
			if (event.type == SDL_MOUSEMOTION)
				keyMotion(event.button.x, event.button.y);
			if (event.type == SDL_MOUSEBUTTONDOWN)
				setMapClickMatrix();
			// if (event.type == SDL_KEYUP)
		}
		ips++;
	}
	return (screen);
}

int					initGlobal(void)
{
	SDL_Surface			***assets;

	if (!(assets = initAssets()))
		(void)exitFailure("Initialization error::assets\n");
	freeAllAssets();
	SDL_Quit();
	return (1);
}
