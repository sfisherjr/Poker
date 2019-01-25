#ifndef _CARD_H_
#define _CARD_H_

#include "Sprite.h"
#include <memory>
#include <string>

class Card : public Sprite
{
public:
    enum Suit
    {
        clubs,
        diamonds,
        hearts,
        spades
    } suit;

    int value;
    bool isSelected{false};
    int hand_position{-1};

    Card(SDL_Renderer *renderer, int value, Card::Suit suit);

    void select();
    void deselect();

private:
    const int selection_push_height{40};
    int prev_pos_y{-1};

    std::string card_texture_path();
};

#endif