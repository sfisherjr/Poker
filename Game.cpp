#include "Game.h"

Game::Game()
{
	hMan = new HandManager();
	isRunning = false;
}

void Game::start()
{
	isRunning = true;
	int inputBuffer = 0;

	while (isRunning)
	{
		dealHands();
		printHands();

		std::cout << "\n\nPress 1 to play again 0 to exit: ";
		std::cin >> inputBuffer;

		if (inputBuffer != 1)
			isRunning = false;
	}

	std::system("cls");
	std::cout << "Thanks for playing!\n\n";
}

void Game::dealHands()
{
	hMan->shuffleDeck();
	hMan->dealHand(true, true);
}

void Game::printHands()
{
	std::system("cls");
	std::cout << "Your hand\n\n";
	
	for (int i = 0; i < 5; i++)
	{
		std::cout << Card::rankToStr(hMan->playerHand[i].rank)
			      << " of "
			      << Card::suitToStr(hMan->playerHand[i].suit) << std::endl;
	}

	std::cout << std::endl;

	std::cout << WinCalc::winTypeToStr(WinCalc::checkHand(hMan->playerHand)) << std::endl;

	std::cout << "\nDealerHand\n\n";

	for (int i = 0; i < 5; i++)
	{
		std::cout << Card::rankToStr(hMan->dealerHand[i].rank)
			      << " of "
			      << Card::suitToStr(hMan->dealerHand[i].suit) << std::endl;
	}

	std::cout << std::endl;

	std::cout << WinCalc::winTypeToStr(WinCalc::checkHand(hMan->dealerHand)) << std::endl;
}

Game::~Game()
{
	delete hMan;
}