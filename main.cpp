#include <iostream>
#include "HandManager.h"
#include "WinCalc.h"

using namespace std;

int main()
{
	HandManager * hMan = new HandManager();

	hMan->shuffleDeck();

	hMan->dealHand(true, true);

	cout << "Player Hand\n\n";

	for (int i = 0; i < 5; i++)
	{
		cout << Card::rankToStr(hMan->playerHand[i].rank) 
			 << " of " 
			 << Card::suitToStr(hMan->playerHand[i].suit) << endl;
	}

	cout << WinCalc::winTypeToStr(WinCalc::checkHand(hMan->playerHand)) << endl;

	cout << "\nDealer Hand\n\n";

	for (int i = 0; i < 5; i++)
	{
		cout << Card::rankToStr(hMan->dealerHand[i].rank)
			 << " of "
			 << Card::suitToStr(hMan->dealerHand[i].suit) << endl;
	}

	cout << WinCalc::winTypeToStr(WinCalc::checkHand(hMan->dealerHand)) << endl;

	delete hMan;

	cout << endl;
	system("pause");
	return 0;
}