#pragma once
#include <memory>

#include "Window.hpp"
#include "Rectangle.hpp"

#include "SDL2/SDL.h"

namespace vulture{
    class SDL2Window : public Window{
        friend class HandleProvider;
    public:
        SDL2Window(const std::string &, const Rectangle &, Window::Flags);

        virtual const std::string title() const override;
        virtual void title(const std::string &) override;

        virtual const Size size() const override;
        virtual void size(const Size &) override;

        virtual const Point position() const override;
        virtual void position(const Point &) override;

        struct Factory : Window::Factory{
            virtual Window *create(const std::string &, const Rectangle &, const Flags) override;
        };

        struct HandleProvider{
            typedef std::weak_ptr<SDL_Window> handle;
            handle provide(SDL2Window &);
        };
    protected:
        typedef std::shared_ptr<SDL_Window> window_handle;
        window_handle _handle;
    private:
        void setWindowSize();
        void setWindowPosition();
    };
}
