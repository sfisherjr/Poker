/**
	Author: Steven Fisher
	Project: Unit 2 Problem 1
*/

#pragma once

#include "Card.h"
#include <iostream>

class WinCalc
{
public:
	enum WinType { Loser, Pair, TwoPair, ThreeKind, FourKind, Straight, Flush };
	struct WinResult { Card::Rank highCard; WinCalc::WinType winType; };

	WinCalc();
	static const char * winTypeToStr(int index);
	static WinResult checkHand(Card * hand);
	~WinCalc();

private:
	static const char * winTypeStr[7];

	static WinResult checkPairs(Card * hand);
	static WinResult checkStraight(Card * hand);
	static WinResult checkFlush(Card * hand);
};