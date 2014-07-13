#include "SDL2Window.hpp"

namespace vulture{
    SDL2Window::SDL2Window(const std::string &title, const Rectangle &info, Window::Flags flags):
        _rect(info)
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

    size_t
    SDL2Window::width() const{
        return _rect.width;
    }

    void
    SDL2Window::width(size_t val){
        _rect.width = val;
        setWindowSize();
    }

    size_t
    SDL2Window::height() const{
        return _rect.height;
    }

    void
    SDL2Window::height(size_t val){
        _rect.height = val;
        setWindowSize();
    }

    const Point
    SDL2Window::position() const{
        return _position;
    }

    void
    SDL2Window::position(const Point &val){
        _position = val;
        setWindowPosition();
    }

    void
    SDL2Window::setWindowSize(){
        SDL_SetWindowSize(_handle.get(), width(), height());
    }

    void
    SDL2Window::setWindowPosition(){
        SDL_SetWindowPosition(_handle.get(), position().x, position().y);
    }
}
