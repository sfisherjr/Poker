#include "Game.h"
#include <memory>

int main(int argc, char **argv)
{
    auto game{std::make_unique<Game>()};
    game->start();

    return 0;
}