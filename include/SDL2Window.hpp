#pragma once
#include "Window.hpp"
#include "Rectangle.hpp"

namespace vulture{
    class SDL2Window : public Window{
    public:
        SDL2Window(const Rectangle &, Window::Flags);
    };
}
