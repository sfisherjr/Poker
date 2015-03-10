#include "Game.h"

Game::Game()
{
	bMan = new BetManager();
	hMan = new HandManager();
	isRunning = false;

	bMan->playerMoney = 100;
}

void Game::start()
{
	isRunning = true;
	int inputBuffer = 0;

	while (isRunning)
	{
		if (bMan->playerMoney >= 5)
		{
			printPlayerInfo();
			dealHands();
			printPlayerHand();
			bMan->getPlayerBet();

			system("cls");

			printPlayerInfo();
			printPlayerHand();
			std::cout << std::endl;
			printDealerHand();
			printResults();

			std::cout << "\n\nPress 1 to play again 0 to exit: ";
			std::cin >> inputBuffer;

			if (inputBuffer != 1)
				isRunning = false;
			else
				system("cls");
		}
	}

	std::system("cls");
	std::cout << "Thanks for playing!\n\n";
}

void Game::printPlayerInfo()
{
	std::cout << "Your Balance: $" << bMan->playerMoney << std::endl << std::endl;
}

void Game::dealHands()
{
	hMan->shuffleDeck();
	hMan->dealHand(true, true);
}

void Game::printPlayerHand()
{
	std::cout << "Your hand\n\n";

	for (int i = 0; i < 5; i++)
	{
		std::cout << Card::rankToStr(hMan->playerHand[i].rank)
			<< " of "
			<< Card::suitToStr(hMan->playerHand[i].suit) << std::endl;
	}
}

void Game::printDealerHand()
{
	std::cout << "DealerHand\n\n";

	for (int i = 0; i < 5; i++)
	{
		std::cout << Card::rankToStr(hMan->dealerHand[i].rank)
			<< " of "
			<< Card::suitToStr(hMan->dealerHand[i].suit) << std::endl;
	}
}

void Game::printResults()
{
	WinCalc::WinResult playerResult = WinCalc::checkHand(hMan->playerHand);

	std::cout << std::endl;

	std::cout << WinCalc::winTypeToStr(playerResult.winType) << std::endl;
	std::cout << "High Card: " << Card::rankToStr(playerResult.highCard);

	WinCalc::WinResult dealerResult = WinCalc::checkHand(hMan->dealerHand);

	std::cout << std::endl;

	std::cout << WinCalc::winTypeToStr(dealerResult.winType) << std::endl;
	std::cout << "High Card: " << Card::rankToStr(dealerResult.highCard);

	std::cout << std::endl;

	/* Compare results to show who won */
	if (playerResult.winType == dealerResult.winType)
	{
		// Push
		if (playerResult.highCard == dealerResult.highCard)
		{
			std::cout << "\nWin Result: Push!" << std::endl;
			bMan->pushNoWin();
		}
		else if (playerResult.highCard > dealerResult.highCard)
		{
			// Player win
			std::cout << "\nWin Result: You Won!" << std::endl;
			bMan->playerWins();
		}
		else if (dealerResult.highCard > playerResult.highCard)
		{
			// Dealer win
			std::cout << "\nWin Result: The Dealer Won!" << std::endl;
			bMan->dealerWins();
		}
	}
	else if (playerResult.winType > dealerResult.winType)
	{
		// Player win
		std::cout << "\nWin Result: You Won!" << std::endl;
		bMan->playerWins();
	}
	else if (dealerResult.winType > playerResult.winType)
	{
		// Dealer win
		std::cout << "\nWin Result: The Dealer Won!" << std::endl;
		bMan->dealerWins();
	}
}

Game::~Game()
{
	delete bMan;
	delete hMan;
}