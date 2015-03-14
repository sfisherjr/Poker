#include "Game.h"

using namespace std;

const int Game::SCREEN_WIDTH = 1024;
const int Game::SCREEN_HEIGHT = 768;

Game::Game()
{
	isRunning = false;

	init();
}

void Game::start()
{
	isRunning = true;
	SDL_Event event;

	while (isRunning)
	{
		SDL_WaitEvent(&event);

		switch (event.type)
		{
			case SDL_QUIT:
				isRunning = false;
				break;
		}

		update();
		draw();
		SDL_RenderPresent(renderer);
	}
}

void Game::init()
{
	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);

	window = SDL_CreateWindow("Poker", 
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH, SCREEN_HEIGHT, 0);

	renderer = SDL_CreateRenderer(window, -1, 0);

	load();
}

void Game::load()
{
	
}

void Game::update()
{

}

void Game::draw()
{
	
}

Game::~Game()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();
}