#ifndef _CARD_MANAGER_H_
#define _CARD_MANAGER_H_

#include <memory>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "Card.h"
#include <random>

class Deck
{
public:
    std::vector<std::unique_ptr<Card>> cards;

    Deck() = default;
    void load_cards(SDL_Renderer *renderer);
    std::unique_ptr<Card> random_card();

private:
    std::random_device rd;
    std::mt19937 gen{rd()};
};

#endif