#include "graphics/SDL2Renderer.hpp"

namespace vulture{
    SDL2Renderer::SDL2Renderer(std::weak_ptr<SDL2Window> window):
        Renderer(window)
    {
        SDL2Window::HandleProvider provider;
        auto hwindow = provider.provide(*window.lock().get());
        _handle = renderer_handle(
            SDL_CreateRenderer(hwindow.lock().get(), -1, SDL_RENDERER_ACCELERATED),
            SDL_DestroyRenderer
        );
    }

    void
    SDL2Renderer::clear(){
        SDL_RenderClear(_handle.get());
    }

    void
    SDL2Renderer::present(){
        SDL_RenderPresent(_handle.get());
    }

    void
    SDL2Renderer::drawingColor(const Color &color){
        SDL_SetRenderDrawColor(
            _handle.get(),
            color.r, color.g, color.b, color.a
        );
    }
}
