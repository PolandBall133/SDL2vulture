#pragma once

#include "windows/WindowEvents.hpp"
#include "SDL2/SDL.h"

namespace vulture{
    class SDL2WindowEvent : public WindowEvent{
    public:
        SDL2WindowEvent(SDL_Event &);
    };
}
