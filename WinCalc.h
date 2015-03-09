#pragma once

#include "Card.h"
#include <iostream>

class WinCalc
{
public:
	enum WinType { Loser, TwoPair, ThreeKind, FourKind, Straight, Flush };

	WinCalc();
	static const char * winTypeToStr(int index);
	static WinType checkHand(Card * hand);
	~WinCalc();

private:
	static const char * winTypeStr[6];

	static WinType checkPairs(Card * hand);
	static bool checkStraight(Card * hand);
	static bool checkFlush(Card * hand);
};