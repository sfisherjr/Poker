#include "Sprite.h"

void Sprite::load_text(TTF_Font *font, std::string text, SDL_Renderer *renderer)
{
    isText = true;

    surface = TTF_RenderText_Blended(font, text.c_str(), text_color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);

    dest_rect.x = 0;
    dest_rect.y = 0;

    SDL_QueryTexture(texture, nullptr, nullptr, &dest_rect.w, &dest_rect.h);
}

void Sprite::load_from_file(std::string filename, SDL_Renderer *renderer)
{
    isText = false;

    surface = IMG_Load(filename.c_str());

    if (surface == nullptr)
        std::cout << "Error loading: " << filename;

    texture = SDL_CreateTextureFromSurface(renderer, surface);
}

void Sprite::draw(SDL_Renderer *renderer)
{
    if (isText)
    {
        SDL_RenderCopy(renderer, texture, nullptr, &dest_rect);
    }
    else
    {
        SDL_RenderCopy(renderer, texture, &src_rect, &dest_rect);
    }
}

Sprite::~Sprite()
{
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}