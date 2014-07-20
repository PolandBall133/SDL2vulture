#include "windows/SDL2WindowEvents.hpp"
#include "SDL2/SDL.h"

#include <map>

namespace vulture{

    SDL2WindowEvent::SDL2WindowEvent(SDL_Event &e){
        static const std::map<uint32_t, WindowEvent::Type> types_map = {
            {SDL_WINDOWEVENT_SHOWN,     WindowEvent::Type::Shown},
            {SDL_WINDOWEVENT_EXPOSED,   WindowEvent::Type::Exposed},
            {SDL_WINDOWEVENT_MOVED,     WindowEvent::Type::Moved},
            {SDL_WINDOWEVENT_RESIZED,   WindowEvent::Type::Resized},
            {SDL_WINDOWEVENT_MINIMIZED, WindowEvent::Type::Minimized},
            {SDL_WINDOWEVENT_MAXIMIZED, WindowEvent::Type::Maximized},
            {SDL_WINDOWEVENT_RESTORED,  WindowEvent::Type::Restored},
            {SDL_WINDOWEVENT_CLOSE,     WindowEvent::Type::Closed}
        };
        if(e.type != SDL_WINDOWEVENT &&
           types_map.count(e.window.event))
            _type = types_map.at(e.window.event);
    }
}
