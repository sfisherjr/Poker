#include "BetManager.h"

using namespace std;

BetManager::BetManager()
{
}

void BetManager::getPlayerBet()
{
	cout << endl << endl;

	bool isValidInput = false;
	int inputBuffer = 0;

	do
	{
		if (playerMoney >= 5) cout << "1 ... Bet $5\n";
		if (playerMoney >= 10) cout << "2 ... Bet $10\n";
		if (playerMoney >= 20) cout << "3 ... Bet $20\n";

		cout << "Selection: ";
		cin >> inputBuffer;

		if (inputBuffer < 1 || inputBuffer > 3)
		{
			cout << "That is invalid bet, try again!\n";
		}
		else
		{
			switch (inputBuffer)
			{
			case 1:
				totalPot = 5;
				playerMoney -= 5;
				break;

			case 2:
				totalPot = 10;
				playerMoney -= 10;
				break;

			case 3:
				totalPot = 20;
				playerMoney -= 20;
				break;
			}

			isValidInput = true;
		}

	} while (!isValidInput);
}

void BetManager::playerWins()
{
	playerMoney += totalPot * 2;
	totalPot = 0;

	StatTracker::trackedStats.playerMoney = playerMoney;
	StatTracker::trackedStats.playerWins++;
	StatTracker::trackedStats.totalGames++;
}

void BetManager::dealerWins()
{
	totalPot = 0;

	StatTracker::trackedStats.playerMoney = playerMoney;
	StatTracker::trackedStats.dealerWins++;
	StatTracker::trackedStats.totalGames++;
}

void BetManager::pushNoWin()
{
	playerMoney += totalPot;
	totalPot = 0;

	StatTracker::trackedStats.playerMoney = playerMoney;
	StatTracker::trackedStats.totalPushes++;
	StatTracker::trackedStats.totalGames++;
}

BetManager::~BetManager()
{
}
