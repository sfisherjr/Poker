#include "Card.h"

const char * Card::suitStr[4] = { 
	"Spades", "Clubs", "Diamonds", "Hearts" 
};

const char * Card::rankStr[13] = { 
	"Ace", "Two", "Three", "Four", 
	"Five", "Six", "Seven", "Eight", "Nine", 
	"Ten", "Jack", "Queen", "King" 
};

Card::Card()
{
	
}

Card::Card(Suit suit, Rank rank)
{
	this->suit = suit;
	this->rank = rank;
}

const char * Card::suitToStr(int index)
{
	return suitStr[index];
}

const char * Card::rankToStr(int index)
{
	return rankStr[index];
}

Card::~Card()
{
}
