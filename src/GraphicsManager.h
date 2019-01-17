#ifndef _GRAPHICSMANAGER_H_
#define _GRAPHICSMANAGER_H_

#include <SDL2/SDL.h>
#include <utility>

class GraphicsManager
{
public:
    SDL_Window *window;

    static GraphicsManager *get_instance();
    GraphicsManager(GraphicsManager const&) = delete;
    GraphicsManager& operator=(GraphicsManager const&) = delete;


    std::pair<int, int> get_window_size();

private:
    static GraphicsManager *m_instance;

    GraphicsManager() = default;
};


#endif