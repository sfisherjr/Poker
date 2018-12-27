#include "Player.h"

Player::Player(SDL_Renderer *renderer)
{
    this->renderer = renderer;

    auto card_mgr = std::make_unique<CardManager>();
    card_mgr->load_cards(renderer);

    // Width of game screen
    const int screen_width = 1024;

    // Height of game screen
    const int screen_height = 768;

    // Width of card
    const int card_width = 140;

    // Height of card
    const int card_height = 190;

    hand_panel_height = card_height;

    // Number of cards to display in hand
    const int card_count = 5;

    // width of hand panel
    hand_panel_width = card_width * card_count;

    // Starting x position of the hand panel
    int panel_start_pos_x = (screen_width / 2) - (hand_panel_width / 2);

    hand_panel_x = panel_start_pos_x;

    // Starting y position of the hand panel
    hand_panel_y = screen_height - card_height;
    
    // The max distance the cards can be displayed at
    const int pos_x_bounds = (hand_panel_width + panel_start_pos_x) - card_width;

    for (; panel_start_pos_x <= pos_x_bounds; panel_start_pos_x += card_width)
    {
        auto card = card_mgr->random_card();

        // Set position of card
        card->sprite->destRect.x = panel_start_pos_x;
        card->sprite->destRect.y = hand_panel_y;
        
        hand.push_back(std::move(card));
    }
}

void Player::handle_input(int x, int y)
{
    for (int i = 0; i < hand.size(); i++)
    {
        if (x >= hand[i]->sprite->destRect.x && x <= hand[i]->sprite->destRect.x + hand[i]->sprite->destRect.w
            && y >= hand[i]->sprite->destRect.y && y <= hand[i]->sprite->destRect.y + hand[i]->sprite->destRect.h)
        {
            (!hand[i]->isSelected) ? hand[i]->select() : hand[i]->deselect();

            break;
        }
    }
}

void Player::update()
{

}

void Player::draw_hand()
{
    for (int i = 0; i < hand.size(); i++) 
    {
        hand[i]->sprite->draw(renderer);
    }
}