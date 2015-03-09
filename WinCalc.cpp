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

	return retVal;
}

WinCalc::WinType WinCalc::checkPairs(Card * hand)
{
	WinType retVal = WinType::Loser;

	int cardHolder[14] = { 0 };

	for (int i = 0; i < 5; i++)
	{
		cardHolder[hand[i].rank]++;
	}

	for (int i = 0; i < 14; i++)
	{
		if (cardHolder[i] == 2 && retVal < WinType::TwoPair)
			retVal = WinType::TwoPair;

		if (cardHolder[i] == 3 && retVal < WinType::ThreeKind)
			retVal = WinType::ThreeKind;

		if (cardHolder[i] == 4 && retVal < WinType::FourKind)
			retVal = WinType::FourKind;
	}

	return retVal;
}

WinCalc::~WinCalc()
{
}
