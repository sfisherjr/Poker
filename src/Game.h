#ifndef _GAME_H_
#define _GAME_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <memory>
#include <vector>
#include <sstream>
#include "Player.h"
#include "Deck.h"
#include "GraphicsManager.h"

class Game
{
public:
    Game();
    void start();
    ~Game();

private:
    enum Status {
        bet_first,
        draw_dump,
        bet_second,
        show
    };

    SDL_Window *window;
    SDL_Renderer *renderer;
    int current_bet{0};
    int current_pot{0};
    bool isRunning{false};
    std::unique_ptr<Player> player;
    std::unique_ptr<Deck> deck;
    Status game_status;
    TTF_Font *font;
    std::unique_ptr<Sprite> hud_text;
    std::unique_ptr<Sprite> pot_text;
    GraphicsManager *graphics_manager;

    void init();
    void load();
    void handle_input(SDL_Event event);
    void update();
    void draw();
    void deal_cards();
    void game_status_completed();
    void game_status_updated();
    void change_hud_text(std::string text);
    void update_pot_text();
    void start_new_game();
};

#endif