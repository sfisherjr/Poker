#include "GraphicsManager.h"

GraphicsManager *GraphicsManager::m_instance = nullptr;

GraphicsManager *GraphicsManager::get_instance()
{
    if (!m_instance)
        m_instance = new GraphicsManager();

    return m_instance;
}

std::pair<int, int> GraphicsManager::get_window_size()
{
    std::pair<int, int> window_size;

    SDL_GetWindowSize(window, &window_size.first, &window_size.second);

    return window_size;
}
