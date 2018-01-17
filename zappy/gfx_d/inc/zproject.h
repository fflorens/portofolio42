/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zproject.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abanvill <abanvill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 19:10:16 by abanvill          #+#    #+#             */
/*   Updated: 2014/06/26 00:19:53 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZPROJECT_H
# define ZPROJECT_H

# define TEAMS					2
# define PLAYERS_MAX			12

# define TITLE					"Z Project"
# define MAP_WIDTH				XBLOCKS * BLOCKS_SIZE
# define MAP_HEIGHT				YBLOCKS * BLOCKS_SIZE

# define GRID_SIZE				0
# define BLOCKS_SIZE			32
# define XBLOCKS				24
# define YBLOCKS				24

# define BACKGROUNDS			0
# define GROUNDS_HOLD			1
# define GROUNDS				2
# define CHARACTERS				3
# define GEMS					4
# define FOODS 					5
# define SKILLS					6
# define MISCS					7
# define MUSICS					8
# define EMPTY					9
# define ASSETS_NUMBER			10

# define GROUNDS_HOLD_NUMBER	2
# define GROUNDS_HOLD_PATH		"gfx_d/img/grounds/Sprite_Ground_Hold"
# define GROUNDS_HOLD_EXTENSION	".bmp"

# define GROUNDS_TYPE_NUMBER	6
# define GROUNDS_NUMBER			24
# define GROUNDS_PATH			"gfx_d/img/grounds/Sprite_Ground"
# define GROUNDS_EXTENSION		".bmp"

# define CHARACTERS_NUMBER		14
# define CHARACTERS_COLORS		8
# define CHARACTERS_PATH		"gfx_d/img/characters/Sprite_Actor"
# define CHARACTERS_EXTENSION	".bmp"

# define GEMS_SPRITE_NUMBER		6
# define GEMS_NUMBER			6
# define GEMS_PATH				"gfx_d/img/gems/Sprite_Gem"
# define GEMS_EXTENSION			".bmp"

# define FOODS_SPRITE_NUMBER	1
# define FOODS_NUMBER			1
# define FOODS_PATH				"gfx_d/img/foods/Sprite_Food"
# define FOODS_EXTENSION		".bmp"

# define SKILLS_SPRITE_NUMBER	12
# define SKILLS_NUMBER			1
# define SKILLS_PATH			"gfx_d/img/skills/Sprite_Skill"
# define SKILLS_EXTENSION		".bmp"

# define MUSICS_NUMBER			6
# define MUSICS_PATH			"gfx_d/snd/musics/Theme"
# define MUSICS_EXTENSION		".wav"

# define STARTSCREEN_MUSIC		0
# define GAME_MUSIC				1

# define DOWN_DIR				0
# define LEFT_DIR				1
# define RIGHT_DIR				2
# define UP_DIR					3

# define WAIT_DRAW				200
# define WAIT_EVENT				0

# define ANIMATION_VALUE		100
# define APS					2
# define IPS 					2

# define LARGE_FONT				24
# define MEDIUM_FONT			18
# define SMALL_FONT				16

# define REMOVE					0
# define ADD					1
# define SET 					2

# define LEVEL_DOWN				0
# define LEVEL_UP				1

# define __DEBUG__				printf("Stable line[%d]\n", __LINE__);

# include <SDL/SDL.h>
# include <SDL/SDL_mixer.h>
# include <iostream>
# include <string>

enum 							e_things
{
	LINEMATE,
	DERAUMERE,
	SIBUR,
	MENDIANE,
	PHIRAS,
	THYSTAME
};

typedef struct 					s_size
{
	int 						x;
	int 						y;
}								t_size;

typedef	struct 					s_net
{
	char 						*addr;
	int							port;
}								t_net;

typedef	struct 					s_map
{
	int							x;
	int							y;
	struct s_state				*attr;
	struct s_map				*next;
}								t_map;

typedef	struct 					s_state
{
	
	bool						set[GEMS_NUMBER + 2];
	int							gem[GEMS_NUMBER];
	int							food;
	int							gemDst[GEMS_NUMBER][2];
	int							players[TEAMS][PLAYERS_MAX];
}								t_state;

typedef struct 					s_inter
{
	std::string					x;
	std::string					y;
	int							smallFontSize;
	int							mediumFontSize;
	int							largeFontSize;
}								t_inter;

typedef struct					s_game
{
	bool						eventRunning;
	bool						drawRunning;
	bool						drawInterface;
	bool						fogMode;
	int							xBlocks;
	int							yBlocks;
	int							mapHoldMatrix[2];
	int							mapClickMatrix[2];
	int							**mapSkinMatrix;
	SDL_Surface					*interfaceSurface;
	SDL_Surface					*screen;
	SDL_Surface					***assets;
	Mix_Music					**musics;
	struct s_map				*map;
	struct s_inter				*textInterface;
}								t_game;

typedef struct					s_sprite
{
	int							id;
	int							dir;
	int							srcX;
	int							srcY;
	int							dstX;
	int							dstY;
	int							sprw;
	int							sprh;
	int							type;
	int							anim;
	int							level;
	int							gem[GEMS_NUMBER];
	int							animation;
	int							food;
	bool						animLevel;
	bool						pushed;
	bool						alive;
	SDL_Surface					**bitmap;
	struct s_sprite				*next;
}								t_sprite;

int					getCaseClickGemNumber(int gem);
int					getCharGemNumber(int id, int gem);
int					getCharFoodNumber(int id);
int					getCaseClickFoodNumber(void);
t_game				*getGameParams(void);

void				loadingScreen(void);

t_map				*setRootMap(void);
int					setDirValue(t_sprite *ref);
int					setPushValue(int type, int id);
int					setAnimValue(t_sprite *ref);
int					setSprite(int type, int id, int dir);
void				setCharSpriteDST(t_sprite *sprite);
void				setMapHoldMatrix(int x, int y);
void				setMapClickMatrix(void);
void				setGameOff(void);
void				setInterface(void);
void				setAnimLevel(int id);
void				setFogMode(void);
t_game				*setGameParams(SDL_Surface *screen, SDL_Surface ***assets, Mix_Music **musics, int x, int y);

void				drawLoop(void);
void				drawStaticCharScene(SDL_Surface *screen);
void				drawStaticGemScene(SDL_Surface *screen);
void				drawDynamicMap(void);
void				drawStaticMap(int x, int y);
void				drawStaticBlock(SDL_Surface *screen, SDL_Surface *bitmap, int x, int y);
void				drawStaticText(SDL_Surface *text, int x, int y);
void				drawStaticInterface(void);
void				drawDynamicInterface(void);
void				drawBottomInterface(void);
void				drawDynamicSkill(t_sprite *sprite, int x, int y);
void				drawBlackBlock(SDL_Surface *screen, SDL_Surface *bitmap, int x, int y);
void				drawStaticFoodScene(SDL_Surface *screen);
void				drawSnapshot(void);

void				keyDown(int keySignal);
void				keyMotion(int x, int y);

void				initSound(void);
void				initMap(void);
void				initMapCase(int x, int y);
void				initNetwork(void);
int					initEvents(SDL_Surface *screen, SDL_Surface ***assets);
int					initGlobal(void);
int					**initMapSkinMatrix(int x, int y);
SDL_Surface			***initAssets(void);
SDL_Surface			**initCharacters(int nbr);
SDL_Surface			**initGroundsHold(int nbr);
SDL_Surface			**initGrounds(int nbr);
SDL_Surface			**initGems(int nbr);
SDL_Surface			**initFoods(int nbr);
SDL_Surface			**initSkills(int nbr);
SDL_Surface			*initText(std::string text, int size, int red, int green, int blue);
SDL_Surface			*initGame(SDL_Surface ***assets, Mix_Music **musics);
SDL_Surface			*initWin(int width, int height);


SDL_Surface			*loadGem(int id);
SDL_Surface			*loadSkill(int id);
SDL_Surface			*loadCharacter(int id);
SDL_Surface			*loadGroundHold(int id);
SDL_Surface			*loadGround(int id);
Mix_Music			*loadMusic(int id);
SDL_Surface			*loadFood(int id);

t_net				*linkNetwork(t_net *net);
t_sprite			*linkCharSprite(SDL_Surface **bitmap, int id);
t_sprite			*linkLastSprite(void);
t_sprite			*linkRootSprite(void);
t_sprite			*linkSpriteByID(int type, int id);
t_size				*linkWorldSize(int x, int y);

int					calcCaseX(int x);
int					calcCaseY(int y);
int					calcMapBorderX(int x);
int					calcMapBorderY(int y);
int					calcCharVision(int x, int y);

int					charMove(int id);
int					charTurn(int id, int dir);
void				charDisplace(int id, int dir, int caseX, int caseY);
void				charInvoke(int id, int dir, int caseX, int caseY);
void				charRevoke(int id);
void				charResurrect(int id);
void				charDestroy(int id);
void				charDestroyAll(void);
void				charSet(int id, int dir, int caseX, int caseY);
void				charSetLevel(int id, int lvl);
void				charLevel(int id, int set);
void				charPutGem(int id, int gem, int number);
void				charTakeGem(int id, int gem, int number);
void				charSetGem(int id, int gem, int number);
void				charSetFood(int id, int number);

void				caseSetGem(int caseX, int caseY, int gem, int set, int number);
void				caseSetFood(int caseX, int caseY, int set, int number);

void				freeAllAssets(void);

void				playMusic(int id);
void				playMute(int coef);

void				displayUsage(char *argv[]);

/*
** DEBUG
*/

void				showSpriteList(void);
void				exitFailure(std::string error);

#endif
