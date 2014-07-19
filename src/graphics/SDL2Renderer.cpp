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

    const Rectangle
    SDL2Renderer::viewPort() const{
        SDL_Rect r;
        SDL_RenderGetViewport(_handle.get(), &r);
        return Rectangle(r.x, r.y, r.w, r.h);
    }

    void
    SDL2Renderer::viewPort(const Rectangle &val){
        SDL_Rect r = { val.x, val.y, val.width, val.height };
        SDL_RenderSetViewport(_handle.get(), &r);
    }

    const Vector2
    SDL2Renderer::scale() const{
        float sx, sy;
        SDL_RenderGetScale(_handle.get(), &sx, &sy);
        return Vector2((double)sx, (double)sy);
    }

    void
    SDL2Renderer::scale(const Vector2 &val){
        float sx = (float)val.x, sy = (float)val.y;
        SDL_RenderSetScale(_handle.get(), sx, sy);
    }

    const Size
    SDL2Renderer::logicalSize() const{
        int w, h;
        SDL_RenderGetLogicalSize(_handle.get(), &w, &h);
        return Size((uint32_t)w, (uint32_t) h);
    }

    void
    SDL2Renderer::logicalSize(const Size &val){
        int w = (int)val.width, h = (int)val.height;
        SDL_RenderSetLogicalSize(_handle.get(), w, h);
    };
}
