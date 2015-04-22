/**
	Author: Steven Fisher
	Project: Unit 2 Problem 1
*/

#ifndef _STATTRACKER_H_
#define _STATTRACKER_H_

#include <iostream>

class StatTracker
{
public:
	struct Stats { int playerMoney; int playerWins; int dealerWins; int totalGames; int totalPushes; };
	static Stats trackedStats;

	StatTracker();
	static void printStats();
	~StatTracker();
};

#endif