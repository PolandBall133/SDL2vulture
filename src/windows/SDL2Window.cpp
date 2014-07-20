#include "windows/SDL2Window.hpp"

namespace vulture{
    SDL2Window::SDL2Window(const std::string &title, const Rectangle &info, Window::Flags flags):
        Window(title, info, flags)
    {
        _handle = window_handle(
            SDL_CreateWindow(title.c_str(), info.x, info.y, info.width, info.height, flags),
            SDL_DestroyWindow
        );
    }

    const std::string
    SDL2Window::title() const{
        return std::string(SDL_GetWindowTitle(_handle.get()));
    }

    void
    SDL2Window::title(const std::string &value){
        SDL_SetWindowTitle(_handle.get(), value.c_str());
    }

    const Size
    SDL2Window::size() const{
        int w, h;
        SDL_GetWindowSize(_handle.get(), &w, &h);
        return Size(w, h);
    };

    void
    SDL2Window::size(const Size &val){
        SDL_SetWindowSize(_handle.get(), (int)val.width, (int)val.height);
    }

    const Point
    SDL2Window::position() const{
        int x, y;
        SDL_GetWindowPosition(_handle.get(), &x, &y);
        return Point(x, y);
    }

    void
    SDL2Window::position(const Point &val){
        SDL_SetWindowPosition(_handle.get(), (int)val.x, (int)val.y);
    }

    void
    SDL2Window::pollEvent(WindowEvent &event){
    }

    Window *
    SDL2Window::Factory::create(const std::string &title, const Rectangle &rect, const Flags flags){
        return new SDL2Window(title, rect, flags);
    }

    SDL2Window::HandleProvider::handle
    SDL2Window::HandleProvider::provide(SDL2Window &window){
        return handle(window._handle);
    }
}
