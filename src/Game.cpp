#include "Game.h"

Game::Game()
    : graphics_manager(GraphicsManager::get_instance())
{
    init();
}

void Game::start()
{
    isRunning = true;
    SDL_Event event;

    while (isRunning)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    isRunning = false;
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    this->handle_input(event);
                    break;

                case SDL_KEYDOWN:
                    this->handle_input(event);
                    break;

                default:
                    break;
            }
        }

        update();
        SDL_RenderClear(renderer);
        draw();
        SDL_RenderPresent(renderer);
    }
}

void Game::init()
{
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();

    SDL_DisplayMode dm;
    SDL_GetDesktopDisplayMode(0, &dm);

//    window = SDL_CreateWindow("Poker",
//                              SDL_WINDOWPOS_CENTERED,
//                              SDL_WINDOWPOS_CENTERED,
//                              dm.w,
//                              dm.h,
//                              SDL_WINDOW_FULLSCREEN_DESKTOP);

    window = SDL_CreateWindow("Poker",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              1024,
                              768,
                              0);

    renderer = SDL_CreateRenderer(window, -1, 0);

    graphics_manager->window = window;

    load();
}

Game::~Game()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    TTF_CloseFont(font);

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

void Game::load()
{
    font = TTF_OpenFont("media/Fonts/OpenSans-Regular.ttf", 20);

    deck = std::make_unique<Deck>();
    deck->load_cards(renderer);

    player = std::make_unique<Player>();

    deal_cards();
    game_status = Status::bet_first;

    pot_text = std::make_unique<Sprite>();
    update_pot_text();

    player_balance_text = std::make_unique<Sprite>();
    update_player_balance_text(500);

    std::stringstream stream;
    stream << "Current bet: $" << current_bet;

    hud_text = std::make_unique<Sprite>();
    change_hud_text(stream.str());
}

void Game::handle_input(SDL_Event event)
{
    // TODO: Move mouse handling and key handling to their own functions
    if (event.type == SDL_MOUSEBUTTONDOWN)
    {
        // Only allow to click cards when the status is draw_dump
        if (game_status == Status::draw_dump)
        {
            // Check if input is in players hand panel
            if (event.button.x >= player->hand_panel_x
                && event.button.x <= player->hand_panel_x + player->hand_panel_width
                && event.button.y >= player->hand_panel_y
                && event.button.y <= player->hand_panel_y + player->hand_panel_height)
            {
                // Send mouse event to player to handle
                player->handle_input(event.button.x, event.button.y);
            }
        }
    }
    else if (event.type == SDL_KEYDOWN)
    {
        switch (event.key.keysym.sym)
        {
            case SDLK_RETURN:
            {
                game_status_completed();

                int new_status = static_cast<int>(game_status) + 1;

                if (new_status > Status::show)
                {
                    start_new_game();
                    break;
                }

                game_status = static_cast<Status>(new_status);

                game_status_updated();
            } break;

            case SDLK_UP:
            {
                if (game_status == Status::bet_first
                    || game_status == Status::bet_second)
                {
                    if (current_bet + 10 > player->get_balance()) break;

                    current_bet += 10;

                    std::stringstream stream;
                    stream << "Current bet: $" << current_bet;

                    change_hud_text(stream.str());
                }
            } break;

            case SDLK_ESCAPE:
            {
                isRunning = false;
            } break;

            default:
                break;
        }
    }
}

void Game::update()
{
    player->update();
}

void Game::draw()
{
    player->draw(renderer);
    pot_text->draw(renderer);
    player_balance_text->draw(renderer);
    hud_text->draw(renderer);
}

void Game::game_status_completed()
{
    if (game_status == Status::draw_dump)
    {
        auto selected_cards = player->retrieve_selected();

        for (int i{0}; i < static_cast<int>(selected_cards.size()); ++i)
        {
            player->add_to_hand(std::move(deck->random_card()));
        }

        player->layout_hand();
    }
    else if (game_status == Status::bet_first
             || game_status == Status::bet_second)
    {
        current_pot += current_bet;
        update_pot_text();
        update_player_balance_text(-current_bet);
    }
}

void Game::game_status_updated()
{
    int game_status_int = static_cast<int>(game_status);

    std::cout << "Updated game status = " << game_status_int << std::endl;

    if (game_status == Status::draw_dump)
    {
        change_hud_text("Select cards to discard and press ENTER");
    }
    else if (game_status == Status::bet_first
             || game_status == Status::bet_second)
    {
        current_bet = 0;

        std::stringstream stream;
        stream << "Current bet: $" << current_bet;

        change_hud_text(stream.str());
    }
    else if (game_status == Status::show)
    {
        auto hand_eval = std::make_unique<HandEvaluation>(player->get_hand());

        std::stringstream stream;

        if (player->get_balance() == 0)
        {
            // TODO: Show game end screen and display stats
            stream << hand_eval->result_str(hand_eval->evaluate_hand())
                   << ". You ran out of cash! Press ENTER to start a new game.";
        }
        else
        {
            stream << hand_eval->result_str(hand_eval->evaluate_hand())
                   << ". Press ENTER to start a new game.";
        }

        change_hud_text(stream.str());
    }
}

void Game::deal_cards()
{
    for (int i{0}; i < 5; ++i)
    {
        player->add_to_hand(std::move(deck->random_card()));
    }

    player->layout_hand();

    std::cout << "Deck size = " << deck->cards.size() << std::endl;
}

void Game::change_hud_text(std::string text)
{
    hud_text->load_text(font, std::move(text), renderer);

    auto window_res = graphics_manager->get_window_size();

    hud_text->dest_rect.x = window_res.first / 2 - hud_text->dest_rect.w / 2;
    hud_text->dest_rect.y = window_res.second / 2 - hud_text->dest_rect.h / 2;
}

void Game::update_pot_text()
{
    std::stringstream stream;
    stream << "Pot: $" << current_pot;

    pot_text->load_text(font, stream.str(), renderer);
}

void Game::update_player_balance_text(int amount)
{
    player->set_balance(player->get_balance() + amount);

    std::stringstream stream;
    stream << "Balance: $" << player->get_balance();

    player_balance_text->load_text(font, stream.str(), renderer);

    auto window_res = graphics_manager->get_window_size();

    player_balance_text->dest_rect.x = window_res.first - player_balance_text->dest_rect.w;
}

void Game::start_new_game()
{
    game_status = Status::bet_first;

    deck->cards.clear();
    deck->load_cards(renderer);

    current_pot = 0;
    current_bet = 0;

    update_pot_text();

    if (player->get_balance() == 0)
        update_player_balance_text(500);

    std::stringstream stream;
    stream << "Current bet: $" << current_bet;

    change_hud_text(stream.str());

    player->clear_hand();

    deal_cards();
}