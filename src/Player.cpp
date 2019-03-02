#include "Player.h"
#include "GraphicsManager.h"

void Player::handle_input(int x, int y)
{
    for (auto && c : hand)
    {
        if (x >= c->dest_rect.x && x <= c->dest_rect.x + c->dest_rect.w
            && y >= c->dest_rect.y && y <= c->dest_rect.y + c->dest_rect.h)
        {
            if (c->isSelected)
            {
                c->deselect();

                for (int rc{0}; rc < removal_hand_refs.size(); ++rc)
                {
                    if (removal_hand_refs[rc] == c.get())
                        removal_hand_refs.erase(removal_hand_refs.begin() + rc);
                }
            }
            else
            {
                c->select();
                removal_hand_refs.push_back(c.get());
            }

            break;
        }
    }
}

void Player::update()
{

}

void Player::draw(SDL_Renderer *renderer)
{
    for (auto && c : hand)
    {
        c->draw(renderer);
    }
}

void Player::add_to_hand(std::unique_ptr<Card> card)
{
    hand.push_back(std::move(card));
}

void Player::clear_hand()
{
    hand.clear();
}

std::vector<std::unique_ptr<Card>> Player::retrieve_selected()
{
    std::vector<std::unique_ptr<Card>> selected_cards;

    std::cout << "removal_hand size = " << removal_hand_refs.size() << std::endl;

    for (int i = hand.size() - 1; i >= 0; --i)
    {
        std::cout << "i = " << i << std::endl;

        for (auto removal_card : removal_hand_refs)
        {
            if (hand[i].get() == removal_card)
            {
                selected_cards.push_back(std::move(hand[i]));
                hand.erase(hand.begin() + i);
                break;
            }
        }
    }

    return selected_cards;
}

void Player::layout_hand()
{
    auto gm = GraphicsManager::get_instance();
    auto window_res = gm->get_window_size();

    // Width of card
    const int card_width{140};

    // Height of card
    const int card_height{190};

    hand_panel_height = card_height;

    // Number of cards to display in hand
    const int card_count{5};

    // width of hand panel
    hand_panel_width = card_width * card_count;

    // Starting x position of the hand panel
    int panel_start_pos_x{(window_res.first / 2) - (hand_panel_width / 2)};

    hand_panel_x = panel_start_pos_x;

    // Starting y position of the hand panel
    hand_panel_y = window_res.second - card_height;

    for (auto && c : hand)
    {
        c->dest_rect.x = panel_start_pos_x;
        c->dest_rect.y = hand_panel_y;

        panel_start_pos_x += card_width;
    }
}

std::vector<Card*> Player::get_hand()
{
    std::vector<Card*> buffer_vec;

    for (auto &card : hand)
        buffer_vec.push_back(card.get());

    return buffer_vec;
}