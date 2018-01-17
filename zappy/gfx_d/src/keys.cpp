#include <zproject.h>
#include <SDL/SDL.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void				keyDown(int keySignal)
{
	static int			character = 0;

 	if (keySignal == SDLK_1)
 		character = 0;
 	else if (keySignal == SDLK_2)
 		character = 1;
 	else if (keySignal == SDLK_3)
 		character = 2;
 	else if (keySignal == SDLK_4)
 		character = 3;
 	else if (keySignal == SDLK_5)
 		character = 4;
 	else if (keySignal == SDLK_6)
 		character = 5;
 	else if (keySignal == SDLK_DOWN)
 		setSprite(CHARACTERS, character, DOWN_DIR);
 	else if (keySignal == SDLK_LEFT)
 		setSprite(CHARACTERS, character, LEFT_DIR);
 	else if (keySignal == SDLK_RIGHT)
 		setSprite(CHARACTERS, character, RIGHT_DIR);
 	else if (keySignal == SDLK_UP)
 		setSprite(CHARACTERS, character, UP_DIR);
 	else if (keySignal == SDLK_m)
 		playMute(2);
 	else if (keySignal == SDLK_l)
 		playMute(4);
 	else if (keySignal == SDLK_i)
 		charInvoke(0, DOWN_DIR, 1, 1);
 	else if (keySignal == SDLK_r)
 		charRevoke(0);
 	 else if (keySignal == SDLK_t)
 		charTakeGem(0, SIBUR, 1);
 	else if (keySignal == SDLK_p)
 		charPutGem(0, SIBUR, 1);
 	else if (keySignal == SDLK_SPACE)
 		setFogMode();
 	else if (keySignal == SDLK_TAB)
 		setInterface();
 	else if (keySignal == SDLK_MINUS)
 		charLevel(0, LEVEL_UP);
 	else if (keySignal == SDLK_0)
 		charLevel(0, LEVEL_DOWN);
 	else if (keySignal == SDLK_ESCAPE)
 		setGameOff();
}

void				keyMotion(int x, int y)
{
	t_game				*params;

	params = getGameParams();
	if (!params)
		return ;
	if (calcCaseX(x) < params->xBlocks && calcCaseY(y) < params->yBlocks)
		setMapHoldMatrix(x, y);
}
