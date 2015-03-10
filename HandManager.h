#pragma once

#include "Card.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

class HandManager
{
public:
	Card * playerHand;
	Card * dealerHand;

	HandManager();
	void dealHand(bool dealPlayer, bool dealDealer);
	void shuffleDeck();
	Card * getCardFromDeck(int index);
	~HandManager();

private:
	Card * deck;

	void generateDeck();
	void dealCardsTo(Card * hand, int set);
};

