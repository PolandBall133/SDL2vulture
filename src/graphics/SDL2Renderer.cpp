#include "graphics/SDL2Renderer.hpp"

namespace vulture{
    SDL2Renderer::SDL2Renderer(std::weak_ptr<SDL2Window> window):
        Renderer(window)
    {

    }
}
