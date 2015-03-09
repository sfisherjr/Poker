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