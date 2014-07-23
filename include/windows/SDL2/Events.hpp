#pragma once

#include "windows/Events.hpp"
#include "SDL2/SDL.h"
#include <map>

namespace vulture{
    namespace windows{
        namespace SDL2{
            class Event : public windows::Event{
            public:
                Event(SDL_Event &);
            };
        }
    }
}
