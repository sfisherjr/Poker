/**
	Author: Steven Fisher
	Project: Unit 2 Problem 1
*/

#ifndef _GAME_H_
#define _GAME_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Sprite.h"

class Game
{
public:
	static const int SCREEN_WIDTH;
	static const int SCREEN_HEIGHT;

	Game();
	void start();
	~Game();

private:
	SDL_Window * window;
	SDL_Renderer * renderer;
	bool isRunning;
	Sprite * testSprite;

	void init();
	void load();
	void update();
	void draw();
};

#endif