#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <memory>
#include <SDL2/SDL.h>
#include <vector>
#include "Card.h"

class Player {
public:
    int hand_panel_x;
    int hand_panel_y;
    int hand_panel_width;
    int hand_panel_height;

    Player() = default;
    void handle_input(int x, int y);
    void update();
    void draw(SDL_Renderer *renderer);
    void add_to_hand(std::unique_ptr<Card> card);
    void clear_hand();
    std::vector<std::unique_ptr<Card>> retrieve_selected();
    void layout_hand();
    std::vector<Card*> get_hand();
    int get_balance();
    void set_balance(int balance);

private:
    std::vector<std::unique_ptr<Card>> hand;
    std::vector<Card*> removal_hand_refs;
    int player_balance{0};
};

#endif