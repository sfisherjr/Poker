/**
    Author: Steven Fisher
    Project: Unit 2 Problem 1
    Documentation: Full source control and documentation 
    can be found at https://gitlab.com/Reizen/Poker
*/

#include "Game.h"
#include <memory>

int main()
{
    auto game = std::make_unique<Game>();
    game->start();

    return 0;
}