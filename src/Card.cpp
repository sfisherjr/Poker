#include "Card.h"

Card::Card(SDL_Renderer *renderer, int value, Card::Suit suit)
        : Sprite()
{
    this->value = value;
    this->suit = suit;

    std::string texture_path{card_texture_path()};

    load_from_file(texture_path, renderer);

    src_rect.x = 0;
    src_rect.y = 0;
    src_rect.w = 140;
    src_rect.h = 190;

    dest_rect.x = 0;
    dest_rect.y = 0;
    dest_rect.w = 140;
    dest_rect.h = 190;
}

void Card::select()
{
    isSelected = true;

    prev_pos_y = dest_rect.y;
    dest_rect.y -= selection_push_height;
}

void Card::deselect()
{
    isSelected = false;

    dest_rect.y = prev_pos_y;
    prev_pos_y = -1;
}

std::string Card::card_texture_path()
{
    std::string texture_path = "media/Cards/";

    switch (suit)
    {
        case clubs: texture_path += "cardClubs"; break;
        case diamonds: texture_path += "cardDiamonds"; break;
        case hearts: texture_path += "cardHearts"; break;
        case spades: texture_path += "cardSpades"; break;
    }

    switch (value)
    {
        case 1: texture_path += "Ace"; break;
        case 2: texture_path += "Two"; break;
        case 3: texture_path += "Three"; break;
        case 4: texture_path += "Four"; break;
        case 5: texture_path += "Five"; break;
        case 6: texture_path += "Six"; break;
        case 7: texture_path += "Seven"; break;
        case 8: texture_path += "Eight"; break;
        case 9: texture_path += "Nine"; break;
        case 10: texture_path += "Jack"; break;
        case 11: texture_path += "Queen"; break;
        case 12: texture_path += "King"; break;
        default: break;
    }

    texture_path += ".png";

    return texture_path;
}