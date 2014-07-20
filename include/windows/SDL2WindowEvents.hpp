#pragma once

#include "windows/WindowEvents.hpp"
#include "SDL2/SDL.h"
#include <map>

namespace vulture{
    class SDL2WindowEvent : public WindowEvent{
    public:
        SDL2WindowEvent(SDL_Event &);
    };
}
