#pragma once

#include "Card.h"
#include <algorithm>

class HandManager
{
public:
	Card * playerHand;
	Card * dealerHand;

	HandManager();
	void dealHand(bool dealPlayer, bool dealDealer);
	void shuffleDeck();
	~HandManager();

private:
	Card * deck;

	void generateDeck();
	void dealCardsTo(Card * hand);
};

