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