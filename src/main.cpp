/**
	Author: Steven Fisher
	Project: Unit 2 Problem 1
	Documentation: Full source control and documentation 
	can be found at https://gitlab.com/Reizen/Poker
*/

#include "Game.h"

int main(int argc, char ** argv)
{
	Game * mGame = new Game();

	mGame->start();

	delete mGame;

	return 0;
}