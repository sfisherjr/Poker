#ifndef _CARD_MANAGER_H_
#define _CARD_MANAGER_H_

#include <memory>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "Card.h"

class CardManager
{
public:
    std::vector<std::unique_ptr<Card>> cards;

    CardManager();
    void load_cards(SDL_Renderer *renderer);
    std::unique_ptr<Card> random_card();
};

#endif