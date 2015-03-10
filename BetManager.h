/**
	Author: Steven Fisher
	Project: Unit 2 Problem 1
*/

#pragma once

#include <iostream>
#include "StatTracker.h"

class BetManager
{
public:
	int totalPot;
	int playerMoney;

	BetManager();
	void getPlayerBet();
	void playerWins();
	void dealerWins();
	void pushNoWin();
	~BetManager();
};