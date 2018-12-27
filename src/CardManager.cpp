#include "CardManager.h"

CardManager::CardManager()
{
    srand(time(NULL));
}

void CardManager::load_cards(SDL_Renderer *renderer)
{
    // Suits
    for (int suit = 0; suit < 4; suit++)
    {
        // Card values
        for (int value = 1; value <= 12; value++)
        {
            cards.push_back(std::make_unique<Card>(
                renderer, 
                value, 
                static_cast<Card::Suit>(suit)));
        }
    }
}

std::unique_ptr<Card> CardManager::random_card()
{
    int random_index = rand() % cards.size();
    auto card = std::move(cards[random_index]);
    cards.erase(cards.begin() + random_index);
    return card;
}