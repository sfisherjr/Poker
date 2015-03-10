#pragma once

#include <iostream>
#include "HandManager.h"
#include "WinCalc.h"
#include "BetManager.h"

class Game
{
public:
	Game();
	void start();
	~Game();

private:
	HandManager * hMan;
	BetManager * bMan;
	bool isRunning;

	void printPlayerInfo();
	void dealHands();
	void printPlayerHand();
	void printDealerHand();
	void printResults();
};