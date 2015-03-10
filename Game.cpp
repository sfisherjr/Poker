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


	WinCalc::WinResult playerResult = WinCalc::checkHand(hMan->playerHand);

	std::cout << std::endl;

	std::cout << WinCalc::winTypeToStr(playerResult.winType) << std::endl;
	std::cout << "High Card: " << Card::rankToStr(playerResult.highCard);

	std::cout << "\n\nDealerHand\n\n";

	for (int i = 0; i < 5; i++)
	{
		std::cout << Card::rankToStr(hMan->dealerHand[i].rank)
			      << " of "
			      << Card::suitToStr(hMan->dealerHand[i].suit) << std::endl;
	}

	WinCalc::WinResult dealerResult = WinCalc::checkHand(hMan->dealerHand);

	std::cout << std::endl;

	std::cout << WinCalc::winTypeToStr(dealerResult.winType) << std::endl;
	std::cout << "High Card: " << Card::rankToStr(dealerResult.highCard);

	std::cout << std::endl;

	printResults(playerResult, dealerResult);
}

void Game::printResults(WinCalc::WinResult playerResult, WinCalc::WinResult dealerResult)
{
	/* Compare results to show who won */
	if (playerResult.winType == dealerResult.winType)
	{
		// Push
		if (playerResult.highCard == dealerResult.highCard)
		{
			std::cout << "\nWin Result: Push!" << std::endl;
		}
		else if (playerResult.highCard > dealerResult.highCard)
		{
			// Player win
			std::cout << "\nWin Result: You Won!" << std::endl;
		}
		else if (dealerResult.highCard > playerResult.highCard)
		{
			// Dealer win
			std::cout << "\nWin Result: The Dealer Won!" << std::endl;
		}
	}
	else if (playerResult.winType > dealerResult.winType)
	{
		// Player win
		std::cout << "\nWin Result: You Won!" << std::endl;
	}
	else if (dealerResult.winType > playerResult.winType)
	{
		// Dealer win
		std::cout << "\nWin Result: The Dealer Won!" << std::endl;
	}
}

Game::~Game()
{
	delete hMan;
}