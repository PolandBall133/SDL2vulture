#pragma once
#include <memory>

#include "windows/Window.hpp"
#include "util/Rectangle.hpp"

#include "SDL2/SDL.h"

namespace vulture{
    namespace windows{
        namespace SDL2{
            class Window : public windows::Window{
                friend class HandleProvider;
            public:
                Window(const std::string &, const Rectangle &, Window::Flags);

                virtual const std::string title() const override;
                virtual void title(const std::string &) override;

                virtual const Size size() const override;
                virtual void size(const Size &) override;

                virtual const Point position() const override;
                virtual void position(const Point &) override;

                virtual uint32_t ID() const override;

                virtual void onClosed(const windows::Event::Closed &) override;

                struct Factory : windows::Window::Factory{
                    virtual Window *create(const std::string &, const Rectangle &, const Flags) override;
                };

                struct HandleProvider;
            protected:
                typedef std::shared_ptr<SDL_Window> window_handle;
                window_handle _handle;
            };

            struct Window::HandleProvider{
                typedef std::weak_ptr<SDL_Window> handle;
                handle provide(Window &);
            };
        }
    }
}
