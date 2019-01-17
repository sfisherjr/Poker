#ifndef _SPRITE_H_
#define _SPRITE_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>

class Sprite
{
public:
    SDL_Surface *surface;
    SDL_Texture *texture;
    SDL_Color text_color = {255, 255, 255};
    SDL_Rect src_rect;
    SDL_Rect dest_rect;
    bool isText{false};

    Sprite() = default;
    void load_text(TTF_Font *font, std::string text, SDL_Renderer *renderer);
    void load_from_file(std::string filename, SDL_Renderer *renderer);
    void draw(SDL_Renderer *renderer);
    ~Sprite();
};

#endif