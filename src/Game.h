/**
	Author: Steven Fisher
	Project: Unit 2 Problem 1
*/

#ifndef _GAME_H_
#define _GAME_H_

#include <iostream>
#include "HandManager.h"
#include "WinCalc.h"
#include "BetManager.h"
#include "StatTracker.h"

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
	void discard();
	void printPlayerHand();
	void printDealerHand();
	void printResults();
};

#endif