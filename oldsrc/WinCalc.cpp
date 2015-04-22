#include "WinCalc.h"

const char * WinCalc::winTypeStr[7] = {
	"Loser", "Pair", "Two Pair", "Three-of-a-Kind", "Four-of-a-Kind", "Straight", "Flush"
};

WinCalc::WinCalc()
{
}

const char * WinCalc::winTypeToStr(int index)
{
	return winTypeStr[index];
}

WinCalc::WinResult WinCalc::checkHand(Card * hand)
{
	WinResult retVal;
	WinResult bufferWinResult;

	retVal = checkPairs(hand);

	bufferWinResult = checkStraight(hand);

	if (bufferWinResult.winType > Loser)
		retVal = bufferWinResult;

	bufferWinResult = checkFlush(hand);

	if (bufferWinResult.winType > Loser)
		retVal = bufferWinResult;

	// If the player doesn't have a winning hand use the highest card
	if (retVal.winType == Loser)
	{
		retVal.highCard = hand[0].rank;

		for (int i = 0; i < 5; i++)
		{
			if (hand[i].rank > retVal.highCard)
				retVal.highCard = hand[i].rank;
		}
	}

	return retVal;
}

WinCalc::WinResult WinCalc::checkPairs(Card * hand)
{
	WinResult retVal;
	retVal.winType = Loser;
	int dubPairCounter = 0;
	int cardHolder[13] = { 0 };

	for (int i = 0; i < 5; i++)
	{
		cardHolder[hand[i].rank]++;
	}

	for (int i = 0; i < 13; i++)
	{
		if (cardHolder[i] == 2)
		{
			retVal.winType = Pair;
			retVal.highCard = (Card::Rank)i;

			dubPairCounter++;
		}

		if (cardHolder[i] == 3)
		{
			retVal.winType = ThreeKind;
			retVal.highCard = (Card::Rank)i;
		}

		if (cardHolder[i] == 4)
		{
			retVal.winType = FourKind;
			retVal.highCard = (Card::Rank)i;
		}
	}

	if (dubPairCounter == 2)
		retVal.winType = TwoPair;

	return retVal;
}

WinCalc::WinResult WinCalc::checkStraight(Card * hand)
{
	WinResult retVal;
	int straightCount = 0;
	int cardHolder[13] = { 0 };

	for (int i = 0; i < 5; i++)
	{
		cardHolder[hand[i].rank]++;
	}

	for (int i = 0; i < 13; i++)
	{
		if (straightCount == 5)
		{
			// Get highest card
			retVal.highCard = (Card::Rank)i;
			break;
		}
		else
		{
			if (cardHolder[i] == 1)
				straightCount++;
			else
				straightCount = 0;
		}
	}

	if (straightCount == 5)
		retVal.winType = Straight;
	else
		retVal.winType = Loser;

	return retVal;
}

WinCalc::WinResult WinCalc::checkFlush(Card * hand)
{
	WinResult retVal;
	Card::Suit sBuffer;
	int flushCount = 0;
	sBuffer = hand[0].suit;

	for (int i = 0; i < 5; i++)
	{
		if (hand[i].suit == sBuffer)
		{
			flushCount++;
		}
		else
		{
			flushCount = 0;
			break;
		}
	}

	if (flushCount == 5)
	{
		retVal.winType = Flush;

		retVal.highCard = hand[0].rank;

		// Get high card
		for (int i = 0; i < 5; i++)
		{
			if (hand[i].rank > retVal.highCard)
				retVal.highCard = hand[i].rank;
		}
	}
	else
	{
		retVal.winType = Loser;
	}

	return retVal;
}

WinCalc::~WinCalc()
{
}