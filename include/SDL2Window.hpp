#pragma once
#include <memory>

#include "Window.hpp"
#include "Rectangle.hpp"

#include "SDL.h"

namespace vulture{
    class SDL2Window : public Window{
    public:
        SDL2Window(const Rectangle &, Window::Flags);
        virtual const std::string &title() const override;
        virtual void title(const std::string &) override;
        virtual size_t width() const override;
        virtual void width(size_t) override;
        virtual size_t height() const override;
        virtual void height(size_t) override;
    protected:
        typedef std::shared_ptr<SDL_Window> window_handle;
        window_handle handle;
    };
}
