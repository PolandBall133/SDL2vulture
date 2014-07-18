#include "graphics/SDL2Renderer.hpp"

namespace vulture{
    SDL2Renderer::SDL2Renderer(std::weak_ptr<SDL2Window> window):
        Renderer(window)
    {

    }

    void
    SDL2Renderer::clear(){
    }

    void
    SDL2Renderer::present(){
    }

    void
    SDL2Renderer::drawingColor(const Color &){
    }
}
