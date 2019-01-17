#include "Game.h"
#include <memory>

int main()
{
    auto game{std::make_unique<Game>()};
    game->start();

    return 0;
}