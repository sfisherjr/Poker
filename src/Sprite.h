/**
	Author: Steven Fisher
	Project: Wie Neu?
*/

#ifndef _SPRITE_H_
#define _SPRITE_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Sprite
{
public:
	SDL_Surface * image;
	SDL_Texture * texture;

	Sprite();
	void load(const char * filename, SDL_Renderer * renderer);
	void draw(SDL_Renderer * renderer);
	~Sprite();
};

#endif