#include "Deck.h"

void Deck::load_cards(SDL_Renderer *renderer)
{
    // Loop through Suits
    for (int suit{0}; suit < 4; ++suit)
    {
        // Loop through Card face values
        for (int value{1}; value <= 12; ++value)
        {
            cards.push_back(std::make_unique<Card>(
                renderer, 
                value, 
                static_cast<Card::Suit>(suit)));
        }
    }
}

std::unique_ptr<Card> Deck::random_card()
{
    std::uniform_int_distribution<int> dis(0, static_cast<int>(cards.size() - 1));

    int random_index{dis(gen)};
    auto card{std::move(cards[random_index])};
    cards.erase(cards.begin() + random_index);
    return card;
}