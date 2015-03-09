#include "HandManager.h"

HandManager::HandManager()
{
	deck = new Card[52]();
	playerHand = new Card[5]();
	dealerHand = new Card[5]();

	generateDeck();
}

void HandManager::dealHand(bool dealPlayer, bool dealDealer)
{
	if (dealPlayer)
		dealCardsTo(playerHand, 1);
	
	if (dealDealer)
		dealCardsTo(dealerHand, 2);
}

void HandManager::shuffleDeck()
{
	std::random_shuffle(&deck[0], &deck[52]);
}

void HandManager::generateDeck()
{
	Card * cBuffer;
	int suitIndexer = 0;
	int rankIndexer = 0;

	// Loop through total cards
	for (int a = 0; a < 52; a++)
	{
		if (suitIndexer > 3)
		{
			suitIndexer = 0;
			rankIndexer++;
		}

		if (rankIndexer > 13)
			rankIndexer = 0;

		cBuffer = new Card();
		cBuffer->suit = (Card::Suit)suitIndexer;
		cBuffer->rank = (Card::Rank)rankIndexer;
		deck[a] = *cBuffer;

		suitIndexer++;
	}
}

void HandManager::dealCardsTo(Card * hand, int set)
{
	if (set == 1)
	{
		for (int i = 0; i < 5; i++)
			hand[i] = deck[i];
	}
	else
	{
		for (int i = 5; i < 10; i++)
			hand[i - 5] = deck[i];
	}
}

HandManager::~HandManager()
{
	delete[] deck;
	delete[] playerHand;
	delete[] dealerHand;
}
