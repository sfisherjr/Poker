#include "StatTracker.h"

using namespace std;

StatTracker::Stats StatTracker::trackedStats;

StatTracker::StatTracker()
{
}

void StatTracker::printStats()
{
	cout << "Stats\n";
	cout << "Your Wins: " << trackedStats.playerWins << endl;
	cout << "Dealer Wins: " << trackedStats.dealerWins << endl;
	cout << "Total Pushes: " << trackedStats.totalPushes << endl;
	cout << "Total Games: " << trackedStats.totalGames << endl;
	cout << "Your Money: $" << trackedStats.playerMoney << endl << endl;
}

StatTracker::~StatTracker()
{
}
