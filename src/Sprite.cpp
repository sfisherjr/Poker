#include "Sprite.h"

Sprite::Sprite()
{
	
}

void Sprite::load(const char * filename, SDL_Renderer * renderer)
{
	image = IMG_Load(filename);

	if (image == NULL)
		std::cout << "Error loading: " << filename;

	texture = SDL_CreateTextureFromSurface(renderer, image);
}

void Sprite::draw(SDL_Renderer * renderer)
{
	SDL_RenderCopy(renderer, texture, &srcRect, &destRect);
}

Sprite::~Sprite()
{
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(image);
}