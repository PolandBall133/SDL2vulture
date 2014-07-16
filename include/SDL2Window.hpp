#pragma once
#include <memory>

#include "Window.hpp"
#include "Rectangle.hpp"

#include "SDL2/SDL.h"

namespace vulture{
    class SDL2Window : public Window{
    public:
        SDL2Window(const std::string &, const Rectangle &, Window::Flags);
        virtual const std::string title() const override;
        virtual void title(const std::string &) override;
        virtual size_t width() const override;
        virtual void width(size_t) override;
        virtual size_t height() const override;
        virtual void height(size_t) override;
        virtual const Point position() const override;
        virtual void position(const Point &) override;
    protected:
        typedef std::shared_ptr<SDL_Window> window_handle;

        window_handle _handle;
    private:
        void setWindowSize();
        void setWindowPosition();
    };
}
