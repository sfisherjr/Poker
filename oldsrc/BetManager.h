/**
	Author: Steven Fisher
	Project: Unit 2 Problem 1
*/

#ifndef _BETMANAGER_H_
#define _BETMANAGER_H_

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

#endif