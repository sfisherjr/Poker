/**
	Author: Steven Fisher
	Project: Wie Neu?
*/

#ifndef _SPRITE_H_
#define _SPRITE_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>

class Sprite
{
public:
	SDL_Surface *image;
	SDL_Texture *texture;
	SDL_Rect srcRect;
	SDL_Rect destRect;

	Sprite();
	void load(std::string filename, SDL_Renderer *renderer);
	void draw(SDL_Renderer *renderer);
	~Sprite();
};

#endif