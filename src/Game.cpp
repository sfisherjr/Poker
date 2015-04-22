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
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
				case SDL_QUIT:
					isRunning = false;
					break;
			}
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
	testSprite = new Sprite();
	testSprite->load("Cards/cardClubsAce.png", renderer);

	testSprite->srcRect.x = 0;
	testSprite->srcRect.y = 0;
	testSprite->srcRect.w = 140;
	testSprite->srcRect.h = 190;

	testSprite->destRect.x = 0;
	testSprite->destRect.y = 0;
	testSprite->destRect.w = 140;
	testSprite->destRect.h = 190;
}

void Game::update()
{
	
}

void Game::draw()
{
	testSprite->draw(renderer);
}

Game::~Game()
{
	delete testSprite;

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();
}