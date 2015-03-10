#pragma once

#include <iostream>

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