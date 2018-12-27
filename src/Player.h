#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <memory>
#include <SDL2/SDL.h>
#include <vector>
#include "CardManager.h"
#include "Card.h"

class Player {
public:
    int hand_panel_x;
    int hand_panel_y;
    int hand_panel_width;
    int hand_panel_height;

    Player(SDL_Renderer *renderer);
    void handle_input(int x, int y);
    void update();
    void draw_hand();

private:
    SDL_Renderer *renderer;
    int card_display_count = 5;
    std::vector<std::unique_ptr<Card>> hand;
};

#endif