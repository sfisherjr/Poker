#include "WinCalc.h"

const char * WinCalc::winTypeStr[6] = {
	"Loser", "Two Pair", "Three-of-a-Kind", "Four-of-a-Kind", "Straight", "Flush"
};

WinCalc::WinCalc()
{
}

const char * WinCalc::winTypeToStr(int index)
{
	return winTypeStr[index];
}

WinCalc::WinType WinCalc::checkHand(Card * hand)
{
	WinType retVal = WinType::Loser;

	retVal = checkPairs(hand);

	if (checkStraight(hand))
		retVal = WinType::Straight;
	if (checkFlush(hand))
		retVal = WinType::Flush;

	return retVal;
}

WinCalc::WinType WinCalc::checkPairs(Card * hand)
{
	WinType retVal = WinType::Loser;

	int cardHolder[13] = { 0 };

	for (int i = 0; i < 5; i++)
	{
		cardHolder[hand[i].rank]++;
	}

	for (int i = 0; i < 13; i++)
	{
		if (cardHolder[i] == 2)
			retVal = WinType::TwoPair;

		if (cardHolder[i] == 3)
			retVal = WinType::ThreeKind;

		if (cardHolder[i] == 4)
			retVal = WinType::FourKind;
	}

	return retVal;
}

bool WinCalc::checkStraight(Card * hand)
{
	bool isStraight = false;

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
		isStraight = true;

	return isStraight;
}

bool WinCalc::checkFlush(Card * hand)
{
	bool isFlush = false;
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
		isFlush = true;

	return isFlush;
}

WinCalc::~WinCalc()
{
}
