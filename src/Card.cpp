#include "Card.h"

Card::Card(SDL_Renderer *renderer, int value, Card::Suit suit)
{
	this->value = value;
	this->suit = suit;
    sprite = std::make_unique<Sprite>();

	std::string texture_path = card_texture_path();

    sprite->load(texture_path, renderer);

    sprite->srcRect.x = 0;
	sprite->srcRect.y = 0;
	sprite->srcRect.w = 140;
	sprite->srcRect.h = 190;

	sprite->destRect.x = 0;
	sprite->destRect.y = 0;
	sprite->destRect.w = 140;
	sprite->destRect.h = 190;
}

void Card::select()
{
	isSelected = true;

	prev_pos_y = sprite->destRect.y;
	sprite->destRect.y -= selection_push_height;
}

void Card::deselect()
{
	isSelected = false;

	sprite->destRect.y = prev_pos_y;
	prev_pos_y = -1;
}

void Card::update()
{
	
}

std::string Card::card_texture_path()
{
	std::string texture_path = "Cards/";

	switch (suit)
	{
		case clubs: texture_path += "cardClubs"; break;
		case diamonds: texture_path += "cardDiamonds"; break;
		case hearts: texture_path += "cardHearts"; break;
		case spades: texture_path += "cardSpades"; break;
	}

	switch (value)
	{
		case 1: texture_path += "Ace"; break;
		case 2: texture_path += "Two"; break;
		case 3: texture_path += "Three"; break;
		case 4: texture_path += "Four"; break;
		case 5: texture_path += "Five"; break;
		case 6: texture_path += "Six"; break;
		case 7: texture_path += "Seven"; break;
		case 8: texture_path += "Eight"; break;
		case 9: texture_path += "Nine"; break;
		case 10: texture_path += "Jack"; break;
		case 11: texture_path += "Queen"; break;
		case 12: texture_path += "King"; break;
	}

	texture_path += ".png";

	return texture_path;
}