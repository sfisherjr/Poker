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
		std::cout << cardHolder[i] << " ";

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

	int cardHolder[13] = { 0 };

	for (int i = 0; i < 5; i++)
	{
		cardHolder[hand[i].rank]++;
	}

	for (int i = 0; i < 13; i++)
	{
		
	}

	return isStraight;
}

bool WinCalc::checkFlush(Card * hand)
{
	return false;
}

WinCalc::~WinCalc()
{
}
