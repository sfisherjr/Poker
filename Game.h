#pragma once

#include <iostream>
#include "HandManager.h"
#include "WinCalc.h"

class Game
{
public:
	Game();
	void start();
	~Game();

private:
	HandManager * hMan;
	bool isRunning;

	void dealHands();
	void printHands();
};