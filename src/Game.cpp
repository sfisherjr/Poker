#include "Game.h"

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
				case SDL_MOUSEBUTTONDOWN:
					this->handle_input(event);
					break;
			}
		}

		update();
		SDL_RenderClear(renderer);
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
	player = std::make_unique<Player>(renderer);
}

void Game::handle_input(SDL_Event event)
{
	if (event.type == SDL_MOUSEBUTTONDOWN)
	{
		// Check if input is in players hand panel
		if (event.button.x >= player->hand_panel_x 
			&& event.button.x <= player->hand_panel_x + player->hand_panel_width
			&& event.button.y >= player->hand_panel_y
			&& event.button.y <= player->hand_panel_y + player->hand_panel_height)
		{
			// Send mouse event to player to handle
			player->handle_input(event.button.x, event.button.y);
		}
	}
}

void Game::update()
{
	
}

void Game::draw()
{
	player->draw_hand();
}

Game::~Game()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();
}