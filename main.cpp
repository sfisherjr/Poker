/**
	Author: Steven Fisher
	Project: Unit 2 Problem 1
	Documentation: Full source control and documentation 
	can be found at https://gitlab.com/Reizen/Poker
*/

#include <iostream>
#include "Game.h"

using namespace std;

int main()
{
	Game * mGame = new Game();

	mGame->start();

	delete mGame;

	cout << endl;
	system("pause");
	return 0;
}