/**
	Author: Steven Fisher
	Project: Unit 2 Problem 1
*/

#ifndef _GAME_H_
#define _GAME_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <memory>
#include <vector>
#include "Player.h"

class Game
{
public:
	static const int SCREEN_WIDTH;
	static const int SCREEN_HEIGHT;

	Game();
	void start();
	~Game();

private:
	SDL_Window *window;
	SDL_Renderer *renderer;
	bool isRunning;
	std::unique_ptr<Player> player;

	void init();
	void load();
	void handle_input(SDL_Event event);
	void update();
	void draw();
};

#endif