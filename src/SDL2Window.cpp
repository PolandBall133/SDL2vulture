#include "SDL2Window.hpp"

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
        return _title;
    }

    void
    SDL2Window::title(const std::string &value){
        _title = value;
        SDL_SetWindowTitle(_handle.get(), _title.c_str());
    }

    const Size
    SDL2Window::size() const{
        return Size(_rect.width, _rect.height);
    };

    void
    SDL2Window::size(const Size &val){
        _rect.width = val.width;
        _rect.height = val.height;
        setWindowSize();
    }

    const Point
    SDL2Window::position() const{
        return Point(_rect.x, _rect.y);
    }

    void
    SDL2Window::position(const Point &val){
        _rect.x = val.x;
        _rect.y = val.y;
        setWindowPosition();
    }

    Window *
    SDL2Window::Factory::create(const std::string &title, const Rectangle &rect, const Flags flags){
        return new SDL2Window(title, rect, flags);
    }

    SDL2Window::HandleProvider::handle
    SDL2Window::HandleProvider::provide(SDL2Window &window){
        return handle(window._handle);
    }

    void
    SDL2Window::setWindowSize(){
        SDL_SetWindowSize(_handle.get(), size().width, size().height);
    }

    void
    SDL2Window::setWindowPosition(){
        SDL_SetWindowPosition(_handle.get(), position().x, position().y);
    }
}
